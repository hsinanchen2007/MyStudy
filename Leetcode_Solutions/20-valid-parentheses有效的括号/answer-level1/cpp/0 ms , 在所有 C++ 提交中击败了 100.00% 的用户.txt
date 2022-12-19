### 解题思路
6.6 MB
, 在所有 C++ 提交中击败了
100.00%
的用户

### 代码

```cpp
class Solution {
public:
    bool isValid(string s) {
        map<char,char> charMap = {{'{','}'},{'(',')'},{'[',']'}};
        stack<char> st;
        int len = s.length();
        for(int i = len - 1; i >= 0; i--){
            char c = s[i];
            if(c == '}' || c == ')' || c == ']' ){
                st.push(c);
            } else {

                if(st.empty()){
                    return false;
                }
                char frontC = st.top();
                if(charMap[c] == frontC) {
                    st.pop();
                } else {
                    return false;
                }
                
            }
        }

        return st.empty();
        
    }
};
```