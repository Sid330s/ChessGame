#include<iostream>
#include<fstream>
#include<string.h>
#include<cstdlib>
using namespace std;
int main()
{
     int noc=0,now=0,nol=0;
      fstream fp;
     char fname[20],ch;

     cout<<"\n Enter  Name Of File You Want To Count For : ";
     
     gets(fname);
     
     fp.open(fname , ios::in);
     
     
     if(fp==NULL)
     {
          cout<<"\n Invalid File Name. \n No such File or Directory ";
          exit(0);
     }
     

     
     while(!fp.eof())
     {   
         fp.get(ch);
          if(ch!=' ' && ch!='\n')
               noc++;
          if(ch==' ')
               now++;
          if(ch=='\n')
          {
               nol++;
               now++;
          }
     
     }
     
     fp.close();
     cout<<" -------------------------------------";
     cout<<"\n Total No. of Characters  : "<<noc;
     cout<<"\n Total No. of Words       : "<<now;
     cout<<"\n Total No. of Lines       : "<<nol;

     return 0;
}



