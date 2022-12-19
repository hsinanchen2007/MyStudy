```
class Solution {
public:
    string freqAlphabets(string s) {
        stack<char> st;
        string res = "";
        for(int i = s.size() - 1; i >= 0; i--){             //逆序遍历
            if(s[i] != '#'){
                st.push(s[i] - '1' + 'a');                  //‘0’-‘9’，转化为‘a’-‘i’
            }
            else{
                int tmp = 0;
                tmp = s[i-1] - '0' + (s[i-2] -'0')*10;
                st.push(tmp - 1 + 'a');                     //‘10#’-‘26#’，转化为‘j’-‘z’
                i-=2;
            }
        }
        while(!st.empty()){                                 //利用栈的特性将其再逆序则得到原顺序
            res += st.top();
            st.pop();
        }
        return res;
    }
};
```
