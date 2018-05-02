#include "ToDo.h"
using namespace std;

ToDo::ToDo(){


ifstream fin;
    fin.open("list.txt");

    int count = 0;
    char str[80];
   
    while(!fin.eof())
    {
        fin.getline(str,80);
        count++;
    }

ToDo(count);

fin.seekp(pos, ios::beg);

while(!fin.eof())
    {
        fin.getline(str,80);
        add(str);
    }

fin.close();
}

ToDo::ToDo(int len){

length = len;

list = new string[length];

}

ToDo::~ToDo(){

if(next > 0)
{
ofstream fout;
    fout.open("list.txt");

      int i = 0;
      while(i<next)
      {
fout.write((char *)&list[i], sizeof(list[i]));
i++;
}

fout.close();
}

delete [] list;

}

// Add an item to list

void ToDo::add(string item){

if(next < length){

list[next] = item;

next++;

}

}

/ Finish the last thing in list

/*void ToDo::done(){

next--;

list[next] = "";

}*/

void ToDo::done(){

int i, input;

i = 0;

while(i<next)
{
cout<<i<<" . "<<list[i]<<endl;
i++;
}
cout<<"Input your choice";
cin>>input

i=0;
while(i<input)
i++;

while(i<next)
{
list[i] = list[i+1];
i++;
}

next--;

list[next] = "";

}