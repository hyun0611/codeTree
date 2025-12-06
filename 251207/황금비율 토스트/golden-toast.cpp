#include <iostream>
#include <string>
#include <list>

using namespace std;

int n, m;
string s;

int main() {
    list<char>::iterator it;

    cin >> n >> m; // 식빵 개수, 암호문 개수
    cin >> s; // 식빵 문자열

    list<char> l(s.begin(), s.end());

    it = l.end(); //맨 뒤 위치로 시작

    for (int i = 0; i < m; i++) {
        char command;
        cin >> command;

        if (command == 'P') {
            char c;
            cin >> c;
            l.insert(it, c);
        }
        else if(command == 'L'){
            if(it!=l.begin())
                it--;
        }
        else if(command == 'R'){
            if(it!=l.end())
                it++;
        }
        else{
            if(it != l.end())
                it = l.erase(it);
        }
    }

    for(it = l.begin(); it != l.end(); it++){
        cout<<*it;
    }

    return 0;
}
