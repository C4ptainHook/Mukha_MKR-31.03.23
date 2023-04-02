//Програмно створити текстовий файл.
// Сформувати новий текстовий файл, що складається з непарних рядків вхідного файлу,
//у яких видалені слова, довжина яких більша, за вказану користувачем.
// Вивести вміст вхідного і створеного файлів.
// Реалізувати роботу з файлами даних з використанням файлових потоків та рядків string
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
void create_file();
void fill_file();
void second_file();
void print();
string analize_the_str(string some, int choice);
int main() {
    create_file();
    fill_file();
    second_file();
    print();
}
void create_file()
{
    ofstream outFile("Kr.txt", ios::out);
}
void fill_file()
{
    string content;
    int agree;
    do {
        cout<<"Enter string"<<endl;
        getline(cin, content);
        content.append("\n");
        ofstream outFile("Kr.txt", ios::app);
        outFile << content;
        outFile.close();
        cout<<"One more string press - 1, stop - 0"<<endl;
        cin>>agree;
        cin.ignore();
    }while(agree==1);
}
void second_file()
{
    string useful, trash;
    int choice;
    cout<<"Enter limit of word, program will delete any word in the row larger than limit"<<endl;
    cin>>choice;
    cin.ignore();
    int count=1;
    ifstream inFile ("Kr.txt", ios::in);
    ofstream outFile("Kr-next.txt", ios::out);
    while(!inFile.eof())
    {
        if(count%2!=0){getline(inFile, useful);
            useful= analize_the_str(useful, choice);
            outFile<<useful;
            outFile.put('\n');
            count++;}
        else{ getline(inFile, trash); count++;}
    }
    inFile.close();
    outFile.close();
}
string analize_the_str(string some, int choice)
{
    int start=0, finish, diff;
    for (int i = 0; i < some.size(); ++i) {
        some[i];
        if(isspace(some[i]))
        {
            finish=i;
            diff=finish-start;
            if(diff>choice)
            {
                some.erase(start, diff+1);
                i=0;
                start=i;
            }
            start=finish+1;
        }
    }
    return some;
}
void print()
{
    char sym;
    cout<<"First file:"<<endl;
    ifstream inFile ("Kr.txt");
    while(!inFile.eof())
    {inFile.get(sym);
    cout<<sym;
    }
    inFile.close();
    cout<<endl;
    cout<<"New file:"<<endl;
    ifstream inFile2 ("Kr-next.txt");
    while(!inFile2.eof())
    {inFile2.get(sym);
        cout<<sym;
    }

}
