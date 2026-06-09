### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(),reservedSeats.end(),[&](vector<int> a,vector<int> b)
             {
                 if(a[0]==b[0])
                     return a[1]<b[1];
                 return a[0]<b[0];
             });
        int vis[10];
        int k=1;
        int res=0;
        for(int i=0;i<reservedSeats.size();)
        {
            memset(vis,0,sizeof(vis));
            while(i<reservedSeats.size()&&reservedSeats[i][0]==k)
            {
                vis[reservedSeats[i][1]-1]=1;
                i++;
            }
            int ans=0;
            for(int j=1;j<9;j++)
            {
                if(!vis[j])
                {
                    ans++;
                    if(ans==4)
                    {
                        if(j==4||j==6||j==8)
                        {
                            res++;
                            ans=0;
                        }
                        else
                            ans--;
                    }
                }
                else
                {
                    ans=0;
                }
            }
            k++;
            if(i==reservedSeats.size())
                break;
        }
        res+=(n-k+1)*2;
        return res;
    }
};
```