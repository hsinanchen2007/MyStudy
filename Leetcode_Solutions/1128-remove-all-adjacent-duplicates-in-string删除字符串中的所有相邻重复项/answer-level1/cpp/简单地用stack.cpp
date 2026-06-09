### 解题思路很简单的题，用stack即可解决

### 代码class Solution {
public:
    string removeDuplicates(string S) {
        string ans="";
        stack<char>res;
        int n=S.size();
        res.push(S[n-1]);
        for(int i=n-2;i>=0;i--)
        {if(!res.empty()&&res.top()==S[i])res.pop();
else res.push(S[i]);
            
        }
        int m=res.size();
        for(int i=0;i<m;i++)
       { ans+=res.top();
       res.pop();
       }
       return ans;
    }
};
```

```cpp
class Solution {
public:
    string removeDuplicates(string S) {
        string ans="";
        stack<char>res;
        int n=S.size();
        res.push(S[n-1]);
        for(int i=n-2;i>=0;i--)
        {if(!res.empty()&&res.top()==S[i])res.pop();
else res.push(S[i]);
            
        }
        int m=res.size();
        for(int i=0;i<m;i++)
       { ans+=res.top();
       res.pop();
       }
       return ans;
    }
};
```