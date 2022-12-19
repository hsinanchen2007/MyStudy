1.未剪枝时
```
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        this->k = k;

        dfs(1);
        return res;
    }
    vector<vector<int>> res;
    vector<int> item;
    int k;
    int n;
    void dfs(int i)
    {
        if (i > n){
            if (item.size() == k)
                res.push_back(item);
            return;
        }
        item.push_back(i);
        dfs(i + 1);
        item.pop_back();
        dfs(i + 1);
    }
};
```
执行用时 :
164 ms
, 在所有 cpp 提交中击败了
36.7%
的用户

2.加入剪枝

```
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        this->k = k;

        dfs(1);
        return res;
    }
    vector<vector<int>> res;
    vector<int> item;
    int k;
    int n;
    void dfs(int i)
    {
        if (k - item.size() > n - i + 1)
            return;
        if (i > n){
            if (item.size() == k)
                res.push_back(item);
            return;
        }
        item.push_back(i);
        dfs(i + 1);
        item.pop_back();
        dfs(i + 1);
    }
};
```
执行用时 :
80 ms
, 在所有 cpp 提交中击败了
93.36%
的用户

就一句话，如果剩下的数比还需放入的数量小，剪去这一分支。
