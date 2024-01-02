//port_scan_strobe
#include <iostream>
#include <SFML/Network.hpp>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

bool is_port_open(const std::string& address, int port)
{
    //cout << "tcp : address: " << address << endl;
    return (sf::TcpSocket().connect(address, port) == sf::Socket::Done);
}

bool is_port_open_w_timeout(const std::string& address, int port)
{
	sf::TcpSocket socket;
	socket.setBlocking(false);
	sf::Time timeout = sf::seconds(2);
	return (socket.connect(sf::IpAddress(address), port, timeout) == sf::Socket::Done);

}
std::vector<int> port_vector(const int range, const int range2)
{

    std::vector<int> port_list;
    for(int i = range; i <= range2; i++)
    {
        //cout << "adding value: " << i << endl;
        port_list.push_back(i);
    }
    return port_list;

}

int main()
{
	cout << "choose scan option: Vanilla (1) , Strobe (2) : " << endl;
	string option_s;
	std::getline(cin,option_s);

	stringstream option_n;

	option_n << option_s;

	int option;

	option_n >> option;



	switch(option)
	{
		case 1:
		{
			int range, range2;
			string s_host;

			cout << "insert host: " << endl;
			std::getline(cin, s_host);

			cout << "port range: " << endl;
			cin >> range >> range2;

			std::vector<int> port_list = port_vector(range, range2);

			for (int i : port_list)
			{
				if(is_port_open(s_host , i))
				{
					cout << "Port: " << i << ": Open" << endl;
				}
			}
			break;
		}
		// strobe scan
		case 2:
		{
			string strobe_host;
			cout << "insert host: " << endl;
			std::getline(cin, strobe_host);

			std::vector<int> strobe_list = {20,21,22,23,25,53,80,137,139,443,8080,8443,1433,1434,3306,3389};
			
			cout << "Scanning Host: " << strobe_host << endl;

			for (int j : strobe_list)
			{
				//cout << "value: " << j << endl;
				// timeout function doesnt work. wont connect but vanilla connection works
				if(is_port_open(strobe_host, j))
				{
					cout << "Port: " << j << " (Open)" << endl;
				}
				else
				{
					cout << "Port: " << j << " (Closed)" << endl;
				}
			}
			break;
		}
		default:
		{
			cout << "No option selected " << endl;
		}

	}

	return 0;


}