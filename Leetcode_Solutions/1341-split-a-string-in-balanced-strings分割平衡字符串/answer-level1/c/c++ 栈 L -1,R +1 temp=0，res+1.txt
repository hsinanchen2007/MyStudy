### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int balancedStringSplit(string s) {
        stack<char> st;
        for(int i = 0;i<s.size();i++){
            st.push(s[i]);
        }
        int temp = 0;
        int res = 0;
        while(!st.empty()){
            char ch = st.top();
            st.pop();
            if(ch == 'L'){
                temp--;
            }
            if(ch == 'R'){
                temp++;
            }
            if(temp == 0){
                res++;
            }
        }
        return res;
    }
};
```