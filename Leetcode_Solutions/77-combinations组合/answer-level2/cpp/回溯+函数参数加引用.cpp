### 解题思路
经测试，将函数参数加了引用以后速度提高了两倍多。因为如果不加，那么每次都要将一整个vector作为参数传入函数，这会非常慢。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        DFS(1, n, k, path);
        return ans;
    }
    void DFS(int st, int n, int k, vector<int> &path)
    {
        if(path.size() == k)
        {
            ans.push_back(path);
            return ;
        }
        for(int i = st ; i <= n ; ++i)
        {
            path.push_back(i);
            DFS(i + 1, n, k, path);
            path.pop_back();
        }
    }
private:
    vector<vector<int> > ans;
};
```