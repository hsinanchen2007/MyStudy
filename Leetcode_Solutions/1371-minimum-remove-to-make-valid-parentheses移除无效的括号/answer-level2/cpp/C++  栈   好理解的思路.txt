### 解题思路
将所有的括号和它们的索引以pair<char,int>依次入栈，同时将配对的有效括号出栈，最后剩下的就是无效括号以及其索引，再利用剩下的索引在原字符串中删除对应的括号

### 代码

```cpp
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>>ss;
        for(int i=0;i<s.size();i++){
            pair<char,int>t;
            t.first=s[i];
            t.second=i;
            if(!ss.empty()){
                if(ss.top().first=='('&&t.first==')'){
                    ss.pop();
                    continue;
                }            
                if(t.first=='('){
                    ss.push(t);
                    continue;
                }  
            }
            if(t.first=='('||t.first==')'){
                ss.push(t);
            }
        }
        while(!ss.empty()){
            s.erase(s.begin()+ss.top().second);
            ss.pop();
        }
        return s;
    }
};
```