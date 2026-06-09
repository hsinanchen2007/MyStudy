### 解题思路
DFS，去重，剪枝
![image.png](https://pic.leetcode-cn.com/19e9f5174acde7caa8505bd63ca1b6e3b7d82a2acf373bd026ae3fc3db2851ec-image.png)

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    void dfs(int n,int k,int index,int level){
        if(level > k){
            res.push_back(tmp);
            return;
        }
        if(n-index < k-level) return;//剪枝，后面剩余的数都用上还不够待填补的数的个数
        for(int i=index;i<=n;i++){
            //从当前往后遍历，可以去重
            tmp.push_back(i);
            dfs(n,k,i+1,level+1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        if(n==0) return res;
        dfs(n,k,1,1);
        return res;
    }
};
```