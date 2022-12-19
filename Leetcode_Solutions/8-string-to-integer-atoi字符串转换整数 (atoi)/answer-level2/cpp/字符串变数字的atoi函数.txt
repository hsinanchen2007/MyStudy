### 解题思路
官方解的状态机适合于现在状态受以前状态影响的算法情况，本题是利用了状态列表，并通过map来建立列表，然后通过二维数组根据不同情况得到不同的索引来访问列表，注意使用了isdigit和isspace函数，也可以用
x<'9' && x>'0'这样来写。还有ans变量定义的时候用long long，比int大所以可以判定是否溢出

### 代码

```cpp
class Automaton {
    string state = "start";
    unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}
    };

    int get_col(char c) {
        if (isspace(c)) return 0;
        if (c == '+' or c == '-') return 1;
        if (isdigit(c)) return 2;
        return 3;
    }
public:
    int sign = 1;
    long long ans = 0;

    void get(char c) {
        state = table[state][get_col(c)];
        if (state == "in_number") {
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
        }
        else if (state == "signed")
            sign = c == '+' ? 1 : -1;
    }
    const string get_state(){
        return state;
    }
};

class Solution {
public:
    int myAtoi(string str) {
        Automaton automaton;
        for (char c : str){
            automaton.get(c);
            if(automaton.get_state() == "end")
                break;
        }
        return automaton.sign * automaton.ans;
    }
};
```