### 解题思路
此处撰写解题思路

### 代码

```cpp
class Automaton{
    string state = "start";
    unordered_map<string,vector<string>> table = {
        {"start",{"start","signed","in_number","end"}},
        {"signed",{"end","end","in_number","end"}},
        {"in_number",{"end","end","in_number","end"}},
        {"end",{"end","end","end","end"}}
    };
    int get_col(char c){
        if(isspace(c)) return 0;
        else if(c == '+' || c == '-') return 1;
        else if(isdigit(c)) return 2;
        else return 3;
    }
public:
    int sign = 1;
    long long ans = 0;
    void get(char c){
        state = table[state][get_col(c)];
        if(state == "in_number"){
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? min((long long)INT_MAX,ans) : min(-(long long)INT_MIN,ans);
        }else if(state == "signed"){
            sign = c == '+' ? 1 : -1;
        }
    }
};
class Solution {
public:
    int myAtoi(string str) {
        Automaton automation;
        for(char c : str){
            automation.get(c);
        }
        return automation.sign * automation.ans;
    }
};









```