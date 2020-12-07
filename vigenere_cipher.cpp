#include<bits/stdc++.h>
using namespace std;

class vigenere
{
	string ip;
	string cipher;
	string key;
	public:
		void encrypt();
		void decrypt();
};

void vigenere :: encrypt()
{
	cout<<"\n\tEnter Message:";
	cin>>ip;
	cout<<"\tEnter Key:";
	cin>>key;
	cipher.clear();
	cout<<"\n\tText Mapping:\n";
	cout<<"\t\tInput:";
	//Encripts the text according to algorithm
	for(int i=0;i<ip.size();i++)
		cout<<"  "<<ip[i];
	cout<<"\n\t\tKey  :";
	for(int i=0,j=0;i<ip.size();i++,j++)
	{
		if(key.size() == j)
			j=0;
		cout<<"  "<<key[j];
	}
	cout<<endl;	
		
	for(int i = 0,j = 0;i<ip.size();i++,j++)
	{
		if(key.size() == j)
			j=0;
		int tmp = (ip[i] + (key[j] - 'a'));
		tmp = ((tmp > 'z') ? (tmp - 26) : tmp); 
		cipher += tmp;
	}
	cout<<"\n\tCipher Text:"<<cipher<<endl;
}

void vigenere :: decrypt()
{
	cout<<"\n\tEnter Key:";
	cin>>key;
	cout<<"\n\tCipher Text:"<<cipher<<endl;
	ip.clear();
	//Decrypts the text according to alogrithm.
	for(int i = 0,j = 0;i<cipher.size();i++,j++)
	{
		if(key.size() == j)
			j=0; 
		char tmp = (cipher[i] - (key[j] - 'a'));
		tmp = tmp < 'a' ? (tmp + 26) : tmp; 
		ip += tmp;
	}
	cout<<"\n\tDecrypted text :"<<ip<<endl;
	
}


int main()
{
	//Menu
	cout<<"\t------Vigenere Cipher--------";
	int opt;
	vigenere vg;
	while(1)
	{
		cout<<"\n\tSelect the following option\n\t1.Encrypt a message\n\t2.Decrypt the message\n\t3.Exit\n\tOption:";
		cin>>opt;
		if(opt>2)
			break;
		switch(opt)
		{
			case 1:
				vg.encrypt();
				break;
			case 2:
				vg.decrypt();
				break;
		}
		
	} 
}
