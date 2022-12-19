### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
private:
    vector<vector<int>> res;
    vector<int> cur;
public:
    vector<vector<int>> combine(int n, int k) {
        DFS(n,k,1);
        return res;
    }
    void DFS(int n, int k, int start){
        if(cur.size() == k){
            res.push_back(cur);
            return;
        }
        for(int i = start; i<= n; i++){
            cur.push_back(i);
            DFS(n, k, i+1);
            cur.pop_back();
        }
    }
};
```