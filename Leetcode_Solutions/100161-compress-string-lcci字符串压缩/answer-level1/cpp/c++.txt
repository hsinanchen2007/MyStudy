### 代码

```cpp
class Solution {
public:
    string compressString(string S) {
        string ans="";
        int n=S.size();
        int k=0;
        int num=0;
        for(int i=0;i<n;++i)
        {
            if(i==0)
            num=1;
            if(i!=0)
            {
                if(S[i]==S[i-1])
                num++;
                else 
                {
                    ans+=S[i-1];
                    ans+=to_string(num);
                    num=1;
                }
            }
        }
        ans+=S[n-1];
        ans+=to_string(num);
        if(ans.size()>=n)
        return S;
        return ans;
    }
};
```