
### 代码

```cpp
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans=0;
        int n=words.size();

        for(int i=0;i<n-1;i++)
        {
            int l1=words[i].size();
            for(int j=i+1;j<n;j++)
            {
                int flag=true;
                int l2=words[j].size();
                for(char c:words[i])
                    if(words[j].find(c)!=-1)
                    {
                        flag=false;
                        break;
                    }
                if(flag) ans=max(ans,l1*l2);
            }
        }

        return ans;
    }
};
```