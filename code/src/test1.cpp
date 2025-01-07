#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<fstream>
#include <string.h>
#include <string>
#include <cstdlib>
using namespace std;

class Crypto
{
    public:
        void SetKey(void)
        {
            cout<<"请输入密钥:"<<endl;
            long long key;
            cin>>key;
            this->Crypto_Key = key;
        }
        void SetKey(long long Key)
        {
            this->Crypto_Key = Key;
        }
        string Encryption()
        {
            string oringin_text = "";
            char *end_text = (char*)malloc(10000);
            cout<<"请输入要加密的文本："<<endl;
            //cin>>oringin_text;
            getline(cin,oringin_text);
            SetKey();
            for(int i=0;i<oringin_text.length();i++)
            {
                end_text[i] = oringin_text[i]^Crypto_Key;
            }
            cout<<"加密结果：\n"<<end_text<<endl;
            srand(time(NULL));
            SetKey(rand());
            return end_text;
        }
        string Encryption(string oringin_text)
        {
            char *end_text = (char*)malloc(oringin_text.length());
            for(int i=0;i<oringin_text.length();i++)
            {
                end_text[i] = oringin_text[i]^Crypto_Key;
            }
            // cout<<"加密结果：\n"<<end_text<<endl;
            // srand(time(NULL));
            // SetKey(rand());
            // string a=end_text;
            // free(end_text);
            return end_text;
        }
        string Decryption()
        {
            string end_text = "";
            char *oringin_text = (char*)malloc(10000);
            cout<<"请输入要解密的文本："<<endl;
            getline(cin,end_text);;
            SetKey();
            for(int i=0;i<end_text.length();i++)
            {

                oringin_text[i] = end_text[i]^Crypto_Key;
            }
            cout<<"解密结果：\n"<<oringin_text<<endl;
            return oringin_text;
        }
        string Decryption(string end_text)
        {
            char *oringin_text = (char*)malloc(end_text.length());
            // SetKey();
            for(int i=0;i<end_text.length();i++)
            {
                oringin_text[i] = end_text[i]^Crypto_Key;
            }
            // cout<<"解密结果：\n"<<oringin_text<<endl;
            // string a=oringin_text;
            // free(oringin_text);
            return oringin_text;
        }
    private:
        long long Crypto_Key;
};
class FileHandler:public Crypto 
{
    public:
        bool Encryption()
        {
            string inputfile;
            cout<<"请输入要加密的文件路径"<<endl;
            cin>>inputfile;
            ifstream ReadFile(inputfile);
            ofstream WriteFile("outputEncryption.txt");
            if(!ReadFile)
            {
                cout<<"被加密文件打开错误请确认是否正确输入路径!"<<endl;
                return 1;
            }
            string line;
            SetKey();
            while(getline(ReadFile,line))
            {
                WriteFile<<Crypto::Encryption(line)<<endl;
                line = "";
            }
            ReadFile.close();
            WriteFile.close();
            return 0;

        }
        bool Decryption()
        {
            string inputfile;
            cout<<"请输入要解密的文件路径"<<endl;
            cin>>inputfile;
            ifstream ReadFile(inputfile);
            ofstream WriteFile("outputDecryption.txt");
            if(!ReadFile)
            {
                cout<<"被加密文件打开错误请确认是否正确输入路径!"<<endl;
                return 1;
            }
            string line;
            SetKey();
            while(getline(ReadFile,line))
            {
                WriteFile<<Crypto::Decryption(line)<<endl;
                line = "";
            }
            ReadFile.close();
            WriteFile.close();
            return 0;

        }
    
};
class Menu:private FileHandler
{
    public:
        bool DisplayMenu()
        {
            while(true){
                system("clear");
                cout<<"------输入数字以选择--------\n"<<endl;
                cout<<"----手动输入文本加密--1-----\n"<<endl;
                cout<<"----读取文件文本加密--2-----\n"<<endl;
                cout<<"----手动输入文本解密--3-----\n"<<endl;
                cout<<"----读取文件文本解密--4-----\n"<<endl;
                cout<<"----------EXIT--0-----------\n"<<endl;
                int sel = 0;
                cin>>sel;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if(sel<0||sel>4)
                    {
                        cout<<"指令错误！！\n"<<endl;
                        return 1;
                    }
                switch(sel)
                {
                    case 0:
                        return 0;
                    case 1:
                        Crypto::Encryption();
                        break;
                    case 2:
                        FileHandler::Encryption();
                        break;
                    case 3:
                        Crypto::Decryption();
                        break;
                    case 4:
                        FileHandler::Decryption();
                        break;
                }
                system("sleep 2");
            }
            
            









        }
    private:

};






int main()
{
    Menu Menu;
    Menu.DisplayMenu();
    return 0;
}
