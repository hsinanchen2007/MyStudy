### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int longestValidParentheses(string s) {
          int n=s.size();
          stack<int> s1;
          int ans=0;//最终解
          int start=-1;//左括号的前一个位置
          for(int i=0;i!=n;i++)
          {
              if(s[i]=='(') s1.push(i);
              else
              {
                  if(s1.empty()) start=i;
                  else
                  {
                      s1.pop();
                      if(s1.empty()) ans=max(ans,i-start);
                      else ans=max(ans,i-s1.top());
                  }
              }
          }
          return ans;
    }
};
```