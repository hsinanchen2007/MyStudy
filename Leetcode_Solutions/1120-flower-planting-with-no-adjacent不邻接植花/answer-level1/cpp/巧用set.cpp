### 解题思路
因为set有自动排序功能，所以我们可以通过遍历此点连接的边将已用的花删去，最后取set中首元素即可得到这点应该放的花朵。

### 代码

```cpp
class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> ans(N);
        vector<vector<int> > hash(N + 1);
        if(paths.size() == 0)
        {
            for(int i = 0 ; i < N ; ++i)
                ans[i] = 1;
            return ans;
        }
        for(int i = 0 ; i < paths.size() ; ++i)
        {
            int a = paths[i][0];
            int b = paths[i][1];
            hash[a].push_back(b);
            hash[b].push_back(a);
        }
        ans[0] = 1;
        for(int i = 2 ; i <= N ; ++i)
        {
            int cnt = 1;
            set<int> s;
            for(int j = 1 ; j <= 4 ; ++j)
                s.insert(j);
            for(auto j:hash[i])
            {
                s.erase(ans[j - 1]);
            }
            ans[i - 1] = *(s.begin());
        }
        return ans;
    }
};
```