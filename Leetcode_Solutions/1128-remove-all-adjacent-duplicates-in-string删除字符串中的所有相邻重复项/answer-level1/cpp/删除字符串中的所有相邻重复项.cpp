### 解题思路
利用栈

### 代码

```cpp
class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> st;
        string ans = "";

        for(int i=0; i<S.size(); i++){
            if(!st.empty() && st.top()==S[i]){   //当前字符与栈顶元素相同，出栈
                st.pop();   
            }
            else{
                st.push(S[i]);     //否则，当前元素入栈
            }
        }

        //最后，栈中保存的即为删除相邻重复项后的字符串
        //将栈中元素出栈，并保存到ans中
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        //由于栈先进后出的特性，此时ans中保存的字符串与源字符串顺序相反
        //反转ans
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
```