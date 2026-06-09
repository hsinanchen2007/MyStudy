### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int> f(n+1,0);
        for(int i=0;i<=n;i++)
        {
            if(0==i)
              {
                  f[i]=1;
                  if(s[0]=='0')
                  return 0;
              }
              else if(1==i)
              {        
                f[i]=1;   

              }else{
                  string temp=s.substr(i-2,2);
                  int num=stoi(temp);
                  if(num>0&&num<=26)
                  {
                      if(s[i-1]=='0')
                      {
                        f[i]=f[i-2];
                      }else if(s[i-2]=='0')
                      {
                          f[i]=f[i-1];

                      }else
                      {
                          f[i]=f[i-1]+f[i-2];
                      }
                  }
                  else
                 {
                      if(s[i-1]=='0')
                      {
                        return 0;
                      }else
                      {
                         f[i]=f[i-1]; 
                      }

                 }
              }
        }
        return f[n];
    }
};
```