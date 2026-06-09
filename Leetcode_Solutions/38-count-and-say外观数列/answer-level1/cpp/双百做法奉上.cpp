![1.png](https://pic.leetcode-cn.com/e6c6bc2a4331c2275455f4bf2f35a722c52d0e371fd5df17d91ecd2d8c6c90c6-1.png)

```
class Solution {
public:
    string countAndSay(int n) {
        if(n==0)    return "0";
        string ans="1";
        for(int i=2;i<=n;i++)
        {
            string tp;
            int k=1;
            for(int j=0;j<ans.size();j++)
            {
                if(j+1<ans.size() && ans[j]==ans[j+1])
                {
                    k++;
                    continue;
                }
                else
                {
                    
                    tp += (k+'0');
                    tp += ans[j];
                    k=1;
                }
            }
            ans = tp;
        }
        return ans;
    }
};
```
