// ConsoleApplication16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <ctime>
#include <windows.h>
#include <shellapi.h>
#include <cstdio>
#include <fstream>
#include <urlmon.h>
#include <chrono>
#include <wininet.h>





#pragma comment(lib,"Urlmon.lib")
using namespace std;

class Cat {
public:
    Cat(int newAge = 1) :age(newAge) { howManyCats++; }
    virtual ~Cat() { howManyCats--; }
    virtual int gGetAge() { return age; }
    virtual void setAge(int newAge) { age = newAge; }
    void value() { std::cout << howManyCats; }
    static void getHowMany();
    static void getName(string value);
    
private:
    //static string name;
    int age;
    static int howManyCats;
};


class Cat_one :public Cat {
public:
    Cat_one();
    ~Cat_one();
    void (Cat_one::* pFun)();
    
    void download();
    void open_file();
    void playGame();
    void print_stuff(void(Cat_one::*)());
    int state;
};

Cat_one::Cat_one() :Cat(1) {
    std::cout << "which function do you want to use?\n";
    std::cout << "1.Download      2.Open_file       3.Print time";
    int choice;
    
    std::cin >> choice;
    switch (choice) {

    case 1:
        pFun= &Cat_one::download;
        
        break;
    case 2:
        pFun = &Cat_one::open_file;
        
        break;
    case 3:
        pFun = &Cat_one::playGame;
        break;
    }

    print_stuff((pFun));



}

Cat_one::~Cat_one() {
    //do nothing
}

void Cat_one::print_stuff(void(Cat_one::* pFun)()) {
    if (pFun == &Cat_one::download) {
        download();
    }
    else if (pFun == &Cat_one::open_file) {
        open_file();
    }
    else{
        playGame();
    }


}
void Cat_one::download() {
    std::cout << "enter the url you would like to download\n";
    
    string URL;
    cin >>URL;
    wstring wsTmp(URL.begin(),URL.end());
    wstring a=wsTmp;
    const wchar_t* newname = a.c_str();
    const wchar_t* destination = L"C:\\Users\\houma\\OneDrive\\Desktop\\University\\UTEA\\CSpython\\webfile.HTML";
    


    URLDownloadToFile(NULL,newname , destination, 0, NULL);
    std::cout << "the file has been downloaded";

}

void Cat_one::open_file() {
    
    std::cout << "what type of file do you want to open?\n";
    std::cout << "1.Text 2.internet";
    std::cin >> state;
    if (state == 1) {
        std::cout << "you choose text";
        std::ofstream First("filename");
        First << "hello how are you";
        First.close();
    }
    if (state==2){
        std::string second_part = "&authuser=2&sxsrf=ALeKk02bVzNqH6tOLDShXIMb9se2SwgLAg%3A1629151257062&source=hp&ei=GeAaYbWpAca7hwOz4rT4Cg&iflsig=AINFCbYAAAAAYRruKTWC7r8ZAkoBejG-l0HuBgVh5neX&oq=hi&gs_lcp=Cgdnd3Mtd2l6EAMyEQguEIAEELEDEMcBEK8BEJMCMgUIABCABDIICAAQsQMQgwEyEQguEIAEELEDEIMBEMcBEK8BMg4ILhCABBCxAxDHARCvATILCAAQgAQQsQMQgwEyCAgAEIAEELEDMggIABCxAxCDATILCAAQgAQQsQMQgwEyCAguELEDEIMBOgcIIxDqAhAnOg0ILhDHARCvARDqAhAnOgQIIxAnOg4ILhCABBCxAxDHARCjAjoRCAAQgAQQsQMQiwMQqAMQ0gNQjQpY4QtgjA1oAXAAeACAAVyIAagBkgEBMpgBAKABAbABCrgBAg&sclient=gws-wiz&ved=0ahUKEwj1mdevxbbyAhXG3WEKHTMxDa8Q4dUDCAo&uact=5;";
        std::string choice_of_website;
        std::cout << "choose the website you want\n";
        std::cin >> choice_of_website;
        std::string url;
        if (choice_of_website=="facebook") {
            url="https://www.facebook.com/";
        }
        if (choice_of_website == "google") {
            url = "https://www.google.com/webhp?authuser=2";
        }
        if (choice_of_website == "youtube") {
            url = "https://www.youtube.com/";
        }
        std::string username;
        std::cout << "enter a username\n";
        cin >> username;
        string a = url + username;
        

        ShellExecuteA(NULL, "open", a.c_str(), NULL, NULL, SW_SHOWNORMAL);

    }
}

void Cat_one::playGame() {
    int hours;
    int min;
    int sec;
    int set_hour=1;
    int set_min=1;
    int set_sec=1;
    bool gameOn = true;
    string message;
    std::cout << "would you like to set a timer?";
    string problem;
    cin >> problem;

    if (problem == "yes" || problem == "y" || problem == "Y") {
        cout << "select a time please\n";
        cout << "set the hour\n";
        cin >> set_hour;
        cout << "set the minute\n";
        cin >> set_min;
        cout << "set the seconds\n";
        cin >> set_sec;
        cout << "alarm is set\n";
        //cout << "do you want to display the time or run as background?";
    }

    while (gameOn==true) {
      time_t curr_time;
      curr_time = time(NULL);
      #pragma warning(disable : 4996)
     
      tm* tm_local = localtime(&curr_time);
      hours = tm_local->tm_hour;
      min = tm_local->tm_min;
      sec = tm_local->tm_sec;
      sec += 1;
      if (sec == 60) {
          sec = 0;
          min += 1;

      }
      if (min == 60) {
          min = 0;
          hours += 1;
      }
      if (hours == 24) {
          hours = 0;
      }

      if ((hours == set_hour) && (min == set_min)) {
          if (sec == set_sec) {
 
              ShellExecuteA(NULL, "open", "https://www.kijiji.ca/v-cars-trucks/edmonton/2019-lexus-lx-570-standard-package/m1707147", NULL, NULL, SW_SHOWNORMAL);

          }
      }
      cout << hours << ":" << min << ":" << sec;
      system("CLS");
      
  }

}


class Cat_two :public Cat {
public:
    Cat_two();
    ~Cat_two();
    void download_data();
    void interesting(int gridx,int gridy);
    void click_game();
    void RSI_INDICATOR();
    //void (Cat_two::* pFun)();
    //void print_stuff(void(Cat_two::*)());
private:

};

void Cat_two::RSI_INDICATOR() {

    //HINTERNET hSession = InternetOpen(L"Google Chrome", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
    

    //HINTERNET hConnect = InternetConnect(hSession,L"www.google.com/finance/quote/AMD:NASDAQ", INTERNET_DEFAULT_HTTP_PORT,NULL,NULL, INTERNET_SERVICE_HTTP,0,0);

    //HINTERNET hRequest = HttpOpenRequestA(hConnect, "GET", "/finance/quote/AMD:NASDAQ", "HTTP/1.1", NULL, NULL,0,0);



    //BOOL HttpSendRequestA(https://www.google.com/finance/quote/AMD:NASDAQ,LPCSTR,lpszHeaders,DWORD dwHeadersLength,LPVOID lpOptional,DWORD dwOptionalLength);
    int sumplus=0;
    int sumlose = 0;

    int prices[14] = { 100,104.2,104.3,102.7,104.6,103.8,108.4,106.4,106.5,108.9,104.7,104.6,103.1,110};
    for (int i = 1; i < sizeof(prices); i++) {
        int difference = prices[i] - prices[i - 1];
        if (difference > 0) {
            sumplus += difference;
        }

        if (difference < 0) {
            sumlose += difference;

        }
    }
    int AveU = sumplus / sizeof(prices);
    int AveD = sumlose / sizeof(prices);

    double RS = AveU / AveD;
    double RSI = 100 - 100 / (1 + RS);
    cout << "RSI :" << RSI <<endl;
    if (RSI < 30) {
        cout << "the stock is oversold, prepare for the price to increase";
    }
    else if (RSI > 70) {
        cout << "the stock is overbought, prepare for the price to decrease";
    }
    else {
        cout << "you are good bro";
    }
    

}
Cat_two::Cat_two() {
    //click_game();
    RSI_INDICATOR();

    //cout<<"please select what your bot will do for now "
    //bruh 
}
Cat_two::~Cat_two() {
    //nothing 
}

void Cat_two::interesting(int gridx,int gridy) {
    for (int i = 0; i < gridy; i++) {
        for (int j = 0; j <gridx; j++) {
            if (j == 0) {
                std::cout << ".";
            }
            else if (i == 9) {
                std::cout << " .";
            }
        }
        std::cout << "\n";

    }
}

void Cat_two::click_game() {
    int num = 0;
    int choice_again;
    bool gameOn = true;
    int time;
    cout << "select the duriation of the game\n";
    cout << "1.15 seconds     2. 30 seconds    3.40 seconds\n";
    cin >> choice_again;
    if (choice_again == 1) {
        time = 15;
    }
    else if (choice_again == 2) {
        time = 30;
    }
    else if(choice_again==3){
        time = 40;
    }
    else {
        cout << "invalid input\n";
        cout << "we will set the time automatically to 1 minute\n";
        time = 60;
    }
    cout << "yay lets play a clicking game\n";

    while (gameOn == true) {
        //UINT SendInput(UINT cInp,LPINPUT pInputs,int cbSize);
        time -= 1;
        if (GetKeyState(VK_RBUTTON)& 0x8000) {
            num += 1;
            
            cout <<"mouse click"<< num << endl;
            system("CLS");

        }
        Sleep(100);
        if (GetAsyncKeyState(VK_DOWN)) {
            gameOn = false;

        }
    }


}
void Cat_two::download_data() {
    std::cout << "enter the url you would like to download\n";

    string URL;
    cin >> URL;
    wstring wsTmp(URL.begin(), URL.end());
    wstring a = wsTmp;
    const wchar_t* newname = a.c_str();
    const wchar_t* destination = L"C:\\Users\\houma\\OneDrive\\Desktop\\University\\UTEA\\CSpython\\webfile.txt";


    URLDownloadToFile(NULL, newname, destination, 0, NULL);
    std::cout << "the file has been downloaded";


}
int Cat::howManyCats = 0;


void Cat::getName(string value) {
   
    std::cout << "hello my name is " << value<< " and i'm ready to help\n ";
}

void Cat::getHowMany() {
    std::cout << "there are" << howManyCats << "cats alive\n";

}
int main() {

    char live;
    int choice;
    const int maxCats = 5;
    std::string names[5] = { "elfie", "fido", "woli", "polly", "ghif" };
    Cat* catHouse[maxCats];
    int i;
    for (i = 0; i < maxCats; i++) {
        catHouse[i] = new Cat(i);
        catHouse[i]->getHowMany();

    }
    std::cout << "do you want the cats bots to live?,enter yes or no\n";
    std::cin >> live;
    if (live == 'y' || live == 'Y') {
        std::cout << "select which cat you want, cat 1 , cat 2, cat 3 , cat 4 , cat 5\n";
        std::cin >> choice;
        if (choice == 1) {
            catHouse[choice-1]->getName(names[choice]);
            Cat_one first;
            

        }
        else if (choice == 2) {
            catHouse[choice - 1]->getName(names[choice]);

            Cat_two second;
        }
        else if (choice == 3) {
            catHouse[choice - 1]->getName(names[choice]);
            catHouse[choice]->value();
        }
        else if (choice == 4) {
            catHouse[choice - 1]->getName(names[choice]);
            cout<<"hello";
        }
        else {
            catHouse[choice - 1]->getName(names[choice]);
            cout << "hello";
        }
    }
    else {

        for (i = 0; i < maxCats; i++) {
            delete catHouse[i];
            catHouse[i]->getHowMany();

        }
    }
    //HWND window;
    //AllocConsole();
    //window = FindWindowA("ConsoleWindowClass", NULL);
    //ShowWindow(window, 0);
    //return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
