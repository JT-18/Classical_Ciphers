#include<bits/stdc++.h>
using namespace std;
class ceasar
{
	string ip;
	int key;
	string cipher;
	public:
		void encrypt();
		void decrypt();
};

void ceasar :: encrypt()
{
	cout<<"\n\tEnter Message:";
	cin>>ip;
	cout<<"\tEnter Key:";
	cin>>key;
	key %= 26;
	cipher.clear();
	for(int i=0;i<ip.size();i++)
	{
		int tmp = (ip[i] + key);
		cipher += (tmp > 'z' ? (tmp - 26):tmp);
	}
	cout<<"\n\tEncrypted Message:"<<cipher<<endl;
}

void ceasar :: decrypt()
{
	cout<<"\n\tEnter Key:";
	cin>>key;
	key = key%26;
	ip.clear();
	for(int i=0;i<cipher.size();i++)
	{
		int tmp = (cipher[i] - key);
		ip += (tmp < 'a' ? (tmp + 26):tmp);
	}
	cout<<"\n\tDecrypted Message:"<<ip<<endl;
}
int main()
{
	cout<<"\t------Ceasar Cipher--------";
	int opt;
	ceasar c;
	while(1)
	{
		cout<<"\n\tSelect the following option\n\t1.Encrypt a message\n\t2.Decrypt the message\n\t3.Exit\n\tOption:";
		cin>>opt;
		if(opt>2)
			break;
		switch(opt)
		{
			case 1:
				c.encrypt();
				break;
			case 2:
				c.decrypt();
				break;
		}
	}	
} 
