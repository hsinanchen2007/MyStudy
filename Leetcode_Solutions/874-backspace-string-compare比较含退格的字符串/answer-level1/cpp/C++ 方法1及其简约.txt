### 解题思路
方法1：定义两个vector并遍历两个字符串，如果不是'#'则push_back()至vector里，否则pop_back()出来。
方法2：方法1有两个for循环太啰嗦，搞一个函数简化代码。注意：vector的类型为char

4ms, 8.6MB

### 代码

方法1：
```cpp
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        vector<char> svec;
        vector<char> tvec;
        for(int i = 0; i < S.length(); i++){
            if(S[i]!='#') svec.push_back(S[i]);
            else if(!svec.empty()) svec.pop_back();
        }
        for(int i = 0; i < T.length(); i++){
            if(T[i]!='#') tvec.push_back(T[i]);
            else if(!tvec.empty()) tvec.pop_back();
        }

        return svec==tvec;

    }
};
```

方法2：
```cpp
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        return equalDitect(S) == equalDitect(T);
    }

    vector<char> equalDitect(string s){
        vector<char> svec;
        for(int i = 0; i < s.length(); i++){
            if(s[i]!='#') svec.push_back(s[i]);
            else if(!svec.empty()) svec.pop_back();
        }
        return svec;
    }

};
```