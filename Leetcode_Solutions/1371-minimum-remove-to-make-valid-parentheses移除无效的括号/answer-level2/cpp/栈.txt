### 解题思路
用栈匹配括号---》》  当遇见（入栈，遇见）匹配（，然后出栈（
输出字母，匹配的括号（用flag数组记录）

### 代码

```cpp
class Solution {
    
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        string s1=s;
        int n=s.length();
        vector<int> flag(n,0);
        for(int i=0;i<n;i++){
            if(s[i]>=97&& s[i]<=122) flag[i]=1;
            if(s[i]=='(')   st.push(i);  
            if(s[i]==')' && !st.empty())   {
                flag[st.top()] = 1;
                flag[i]=1;
                st.pop();
            }
            
        }
        
        int j=0;
        for(int i=0;i<n;i++){
            if(flag[i]) {
                
                s1[j++]=s[i];
                
            }
        }
        
        s1[j]='\0';
        
        return s1;

    }
};
```