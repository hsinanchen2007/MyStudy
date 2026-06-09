### 解题思路

法一，① 进行初始化(当时想到的是用数组代替map，懒得打表) 
② 初始化了两个temp数组用来进行队列模拟
③ 第一次直接进队temp1
④ 之后就是从temp1中取每个元素出来，给他加上该数组所代表的字母，再放到temp2中，结束后把temp2赋给temp1，temp2

### 代码
```cpp
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // initial first --- initial a vector<string> to record the number to letter
        int cnt = 0;
        vector<string> words, ans, temp1, temp2;

        for (int i = 0; i <= 9; ++ i){
            string ss;
            if (i == 0 || i == 1) {
                words.push_back("ss");
                continue;
            }
            if (i == 7 || i == 9){
                for (int j = 0; j < 4; ++ j){
                    ss.push_back('a' + cnt);
                    ++ cnt;
                }
                words.push_back(ss);
            }else {
                for (int j = 0; j < 3; ++ j){
                    ss.push_back('a' + cnt);
                    ++ cnt;
                }
                words.push_back(ss);
            }
        }
        // each number should loop three times , so we should initial the another vector<string> as temp
        // then， we insert the all letter to the string (exactly we can use bfs to finish this procedure)
        for (int i = 0; i < digits.size(); ++ i){
            if (temp1.empty()) for(auto& e : words[digits[i] - '0']){
                string tt;
                tt.push_back(e);
                temp1.push_back(tt);
            }
            else {
                for(auto e : temp1){
                    for(auto& r : words[digits[i] - '0']){
                        string tt = e;
                        tt.push_back(r);
                        temp2.push_back(tt);
                    }
                }
                temp1 = temp2; temp2.clear();
            }
        }

        return temp1;
    }
};
```
### 解题思路

法二，①进行初始化，打表
②类似bfs，初始化一个队列
③第一次队空直接入队，入队后记录队长度，用于确定下一次出队的次数
④循环之前确定的队长度，把原来的队内元素都进行一次添加，再入队，结束后更改队列长度

### 代码
```cpp
class Solution {
    map<char, string> m;
public:
    vector<string> letterCombinations(string digits) {
        // initialize
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz"; 
        int cnt = 0; // Used to determine the number of pop
        vector<string> ans;
        queue<string> Q;
        
        // BFS
        // Enter the queue, then determine the length of the queue and determine the number of loops
        // Pop the queue, then join the corresponding the letters, then join the queue
        for (int i = 0; i < digits.size(); ++ i){
            string ss;
            ss.clear();
            if (Q.empty()){
                for (auto& e : m[digits[i]]){
                    string tt; tt.push_back(e);
                    Q.push(tt);
                }
                cnt = Q.size();
            }else {
                for (int j = 0; j < cnt; ++ j){
                    ss = Q.front(); Q.pop();
                    for (auto& e : m[digits[i]]){
                        string tt = ss; tt.push_back(e);
                        Q.push(tt);
                    }
                }
                cnt = Q.size();
            }
        }

        // from queue to vector<sring>
        while (!Q.empty()){
            string ss = Q.front(); Q.pop();
            ans.push_back(ss);
        }
        return ans;
    }
};
```