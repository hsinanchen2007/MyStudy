### 解题思路
判断每个点的出度与入度的情况即可～
### 代码

```cpp
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        unordered_set<int> vis;
        vector<int> num(N+1,0);
        for(int i=0;i<trust.size();++i)
        {
            int l=trust[i][0],r=trust[i][1];
            vis.insert(l);
            num[r]++;
        }
        int count=0;int temp=-1;
        for(int i=1;i<=N;++i)
        {
            if(vis.find(i)==vis.end()&&num[i]==N-1)
            {
                temp=i;++count;
            }
        }
        if(count==1)
            return temp;
        return -1;
    }
};
```