### 解题思路
首先用res得到第一堆原语（用栈来判断，"("push, ")"pop, 当栈为空说明得到第一堆原语），
接着将它脱衣，得到res1;
接着用res2存放res1，将res,res1重新置为“”，继续循环，不断加给res2.最终return res2.

### 代码

```cpp
class Solution {
public:
    string removeOuterParentheses(string S) {
        string res="";
        string res1="";
        string res2="";
        stack<char>st;
        int i=0;
        for(;i<S.size();++i){  //得到原语分解，一个原语被存在res中
            if(S[i]=='('){
                st.push(S[i]);
                res.push_back(S[i]);
            }
            if(S[i]==')'){
                st.pop();
                res.push_back(S[i]);
            }
            if(st.empty()){//说明得到一个原语，现在给它脱衣服
                for(int j=1;j<res.size()-1;++j){ //脱掉每部分最外层括号
                    res1.push_back(res[j]);
                }
                res2+=res1;
                res="";
                res1="";
            }
        }
        return res2;
    }
};
```