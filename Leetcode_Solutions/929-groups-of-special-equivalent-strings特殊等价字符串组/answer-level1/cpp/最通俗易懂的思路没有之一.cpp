### 解题思路
判断每一个字符串的奇数位置与偶数位置是否相等即可，相等则为一组，不相等则单独一组

### 代码

```cpp
class Solution {
public:
    typedef struct st{
        string left;
        string right;
        st()
        {
            left="";
            right="";
        }
    }st;
    int numSpecialEquivGroups(vector<string>& A) {
        vector<int> vis(A.size(),0);
        vector<st> all(A.size());
        for(int i=0;i<A.size();++i)
        {
            for(int j=0;j<A[i].size();++j)
                if(j%2==0)
                    all[i].right+=A[i][j];
                else
                    all[i].left+=A[i][j];
            sort(all[i].left.begin(),all[i].left.end());
            sort(all[i].right.begin(),all[i].right.end());
        }
        int count=0;
        for(int i=0;i<A.size();++i)
        {
            if(vis[i]==0)
            {
                vis[i]=1;
                for(int j=0;j<A.size();++j)
                {
                    if(j!=i&&all[i].left==all[j].left&&all[i].right==all[j].right)
                    vis[j]=1;
                }
                count++;
            }
        }
        return count;
    }
};
```