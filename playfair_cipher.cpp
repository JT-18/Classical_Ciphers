#include<bits/stdc++.h>
using namespace std;

class playfair
{
	string ip;
	string cipher;
	string key;
	char keyMat[5][5];
	public:
		void encrypt();
		void decrypt();
		void display();
};

void playfair :: encrypt()
{
	cout<<"\n\tEnter message:";
	cin>>ip;
	//Replace Q with P.
	for(int i=0;i<ip.size();i++)
	{
		if(ip[i] == 'q')
			ip[i]--;
	}
	cout<<"\tEnter key:";
	cin>>key;
	//Replace Q with P.
	for(int i=0;i<key.size();i++)
	{
		if(key[i] == 'q')
			key[i]--;
	}
	set<char> s;
	vector<char> v;
	pair<set<char>::iterator,bool> p;
	//Generates a key having same insertion order and duplicates are eleminated.
	for(int i=0;i<key.size();i++)
	{
		p = s.insert(key[i]);		
		if(p.second == true)
			v.push_back(key[i]);
	}
	int i=0,j=0;
	//Inserts the key into the key matrix
	for(int k=0;k<v.size();k++)
	{
		keyMat[i][j] = v[k];
		j++;
		if(j%5 == 0)
		{
			j=0;
			i++;
		}
	}
	//Used to fill the remaining key matrix.
	char ch = 'a';
	for(;i<5;i++)
	{
		
		for(;j<5;)
		{
			set<char>::iterator it = s.find(ch);
			if(it == s.end() && ch !='q')
			{
				keyMat[i][j] = ch;
				j++;
			}
			ch++;
		}
		j=0;
	}
	cout<<"\n\tKey Matrix\n";
	for(int i=0;i<5;i++)
	{
		cout<<"\t";
		for(int j=0;j<5;j++)
		{
			cout<<keyMat[i][j]<<" ";
		}
		cout<<"\n";
	}
	//Breaks input text into diaphers
	string tmp;
	cout<<"\n\tDiagraphs: ";
	int l=1;
	do
	{
		if(ip[l-1] == ip[l])
		{
			tmp += ip[l-1];
			tmp += 'x';
			cout<<ip[l-1]<<'x'<<" ";
			l++;
		}
		else
		{
			tmp += ip[l-1];
			tmp += ip[l];
			cout<<ip[l-1]<<ip[l]<<" ";
			l += 2;
		}
		
	}while(l<ip.size());
	if(ip.size() - l == 0)
	{
		tmp += ip[ip.size()-1];
		tmp += 'x';
		cout<<ip[ip.size() - 1]<<'x'<<" ";
	}
	//Encryption according to rules
	cipher.clear();
	cout<<"\n\n\tEncryption of Diagraphs:\n";
	for(int k1=0;k1<tmp.size()-1;k1 += 2)
	{
		int i1,i2,j1,j2;
		//To get the position of 1st letter in diapher
		for(i1=0;;i1++)
		{
			for(j1 = 0;j1 < 5;j1++)
			{
				if(keyMat[i1][j1] == tmp[k1])
					break;
			}
			if(j1 == 5)
				j1=0;
			if(keyMat[i1][j1] == tmp[k1])
				break;
		}
		//To get the position of 2nd letter in diapher.
		for(i2 = 0;;i2++)
		{
			for(j2 = 0;j2 < 5;j2++)
			{
				if(tmp[k1+1] == keyMat[i2][j2])
				{
					break;
				}
					
			}
			if(j2 == 5)
				j2=0;
			if(tmp[k1+1] == keyMat[i2][j2])
			{
				break;
			}
				
		}
		//If both letters are in same row
		if(i1 == i2)
		{
			cipher += keyMat[i1][(j1+1)%5];
			cipher += keyMat[i2][(j2+1)%5];
		}
		//If both letters are in same columns
		else if(j1 == j2)
		{
			cipher += keyMat[(i1+1)%5][j1];
			cipher += keyMat[(i2+1)%5][j2];
		}
		//If letters are not in same columns or same rows
		else
		{
			cipher += keyMat[i1][j2];
			cipher += keyMat[i2][j1];
		}
		cout<<"\n\t"<<tmp[k1]<<tmp[k1+1]<<" -> "<<cipher[cipher.size()-2]<<cipher[cipher.size() - 1];
	}
	cout<<"\n\n\tCipher text:"<<cipher<<endl;
}

void playfair :: decrypt()
{
	cout<<"\n\tEnter key:";
	cin>>key;
	//Replaces Q with P.
	for(int i=0;i<key.size();i++)
	{
		if(key[i] == 'q')
			key[i]--;
	}
	//Generates a key having same insertion order and duplicates are eleminated.
	set<char> s;
	vector<char> v;
	pair<set<char>::iterator,bool> p;
	for(int i=0;i<key.size();i++)
	{
		p = s.insert(key[i]);		
		if(p.second == true)
			v.push_back(key[i]);
	}
	int i=0,j=0;
	//Inserts the key into the key matrix
	for(int k=0;k<v.size();k++)
	{
		keyMat[i][j] = v[k];
		j++;
		if(j%5 == 0)
		{
			j=0;
			i++;
		}
	}
	//Used to fill the remaining key matrix.
	char ch = 'a';
	for(;i<5;i++)
	{
		
		for(;j<5;)
		{
			set<char>::iterator it = s.find(ch);
			if(it == s.end() && ch !='q')
			{
				keyMat[i][j] = ch;
				j++;
			}
			ch++;
		}
		j=0;
	}
	cout<<"\n\tKey Matrix\n";
	for(int i=0;i<5;i++)
	{
		cout<<"\t";
		for(int j=0;j<5;j++)
		{
			cout<<keyMat[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n\tCipher text:"<<cipher;
	//Breaks input text into diaphers
	string tmp;
	cout<<"\n\n\tDiagraphs: ";
	int l=1;
	do
	{
			tmp += cipher[l-1];
			tmp += cipher[l];
			cout<<cipher[l-1]<<cipher[l]<<" ";
			l += 2;
	}while(l<cipher.size());

	//Decryption according to rules
	cout<<"\n\n\tDecryption of Diagraphs:\n";
	cipher.clear();
	for(int k1=0;k1<tmp.size()-1;k1 += 2)
	{
		int i1,i2,j1,j2;
		//To get the position of 1st letter in diapher
		for(i1=0;;i1++)
		{
			for(j1 = 0;j1 < 5;j1++)
			{
				if(keyMat[i1][j1] == tmp[k1])
					break;
			}
			if(j1 == 5)
				j1=0;
			if(keyMat[i1][j1] == tmp[k1])
				break;
		}
		//To get the position of 2nd letter in diapher.
		for(i2 = 0;;i2++)
		{
			for(j2 = 0;j2 < 5;j2++)
			{
				if(tmp[k1+1] == keyMat[i2][j2])
				{
					break;
				}
					
			}
			if(j2 == 5)
				j2=0;
			if(tmp[k1+1] == keyMat[i2][j2])
			{
				break;
			}
				
		}
		//If both letters are in same row
		if(i1 == i2)
		{
			cipher += keyMat[i1][((j1-1)>-1)?(j1-1):4];
			cipher += keyMat[i2][((j2-1)>-1?(j2-1):4)];
		}
		//If both letters are in same columns
		else if(j1 == j2)
		{
			cipher += keyMat[((i1-1)>-1)?(i1-1):4][j1];
			cipher += keyMat[((i2-1)>-1)?(i2-1):4][j2];
		}
		//If letters are not in same columns or same rows
		else
		{
			cipher += keyMat[i1][j2];
			cipher += keyMat[i2][j1];
		}
		cout<<"\n\t"<<tmp[k1]<<tmp[k1+1]<<" -> "<<cipher[cipher.size()-2]<<cipher[cipher.size() - 1];
	}
	//To replace the i with j in ouput
	for(int i=0;i<cipher.size();i++)
	{
		if(cipher[i] == 'i')
			cipher[i]++;
	}
	//To remove the dummy letter at the end
	if(cipher[cipher.size()-1] == 'x')
		cipher[cipher.size()-1] = '\0';
	cout<<"\n\n\tDecrypted text:"<<cipher<<endl;
		
}

int main()
{
	//Menu
	cout<<"\t------Playfair Cipher--------";
	int opt;
	playfair pf;
	while(1)
	{
		cout<<"\n\tSelect the following option\n\t1.Encrypt a message\n\t2.Decrypt the message\n\t3.Exit\n\tOption:";
		cin>>opt;
		if(opt>2)
			break;
		switch(opt)
		{
			case 1:
				pf.encrypt();
				break;
			case 2:
				pf.decrypt();
				break;
		}
		
	} 
}
