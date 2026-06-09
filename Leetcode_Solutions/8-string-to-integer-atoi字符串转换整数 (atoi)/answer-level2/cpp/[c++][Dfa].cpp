### 解题思路
思路为模拟一个有限状态机(DFA)，没有使用列表的方式查找状态，而是给每个状态都编写了一个功能及跳转函数。时间复杂度O(N), 空间复杂度O(1).
### 代码

```cpp
using namespace std;

class Dfa{
    public:
        bool isNumber(char x){
            return int(x) - '0' >= 0 && int(x) - '0' <= 9;
        }
        bool isSign(char x){
            return x == '-' || x == '+';
        }
        bool valid(char x){
            return isNumber(x) || isSign(x);
        }
        string ns;
        int si = 1;
        bool nz = false;
        void end(){
            if(ns == "") return;
            if(ns.length() > 10){
                res = si == 1 ? INT_MAX : INT_MIN;
                return;
            }
            long b = 1;
            for(int i=ns.length()-1;i >= 0;i--){
                res += b*(ns[i] - '0');
                b *= 10;
            }
            if(si == 1 && res > long(INT_MAX)) res = INT_MAX;
            if(si == -1 && res > long(INT_MAX) + 1) res = INT_MIN;
            res *= si;
        }
        void wait(char i){
            if(i == ' ') return;
            else if(!valid(i)){
                state = "end";
            }else if(isSign(i)){
                state = "sign";
                si = i == '+' ? 1:-1;
            }else if(isNumber(i)){
                state = "rec";
                rec(i);
            }
        }
        void sign(char i){
            if(isNumber(i)){
                rec(i);
                state = "rec";
            }else{
                state = "end";
            }
        }
        void rec(char i){
            if(isNumber(i)){
                if(i != '0') nz = true;
                if(i == '0'){
                    if(nz) ns += i;
                }else ns += i;
            }else{
                state = "end";
                end();
            }
        }
        long res;
        string state;
        Dfa() : ns(""), res(0), state("wait"){}
        int getRes(){
            if(state != "end"){
                state = "end";
                end();
            }
            return res;
        }
        void exe(char i){
            if(state == "end") return;
            if(state == "wait") wait(i);
            else if(state == "sign") sign(i);
            else if(state == "rec") rec(i);
        }
};

class Solution{
    public:
        int myAtoi(string str){
            Dfa d = Dfa();
            int i=0;
            while(i < str.length()){
                d.exe(str[i++]);
            }
            return d.getRes();
        }
};

```