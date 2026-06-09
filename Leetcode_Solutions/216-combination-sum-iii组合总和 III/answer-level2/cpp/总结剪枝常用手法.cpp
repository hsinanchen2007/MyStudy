### 解题思路
终于有一次双100%，c++选手不要面子的吗
# 总结剪枝常用手法：

1. **不能重复使用同一数字： vis[i] **

2. **防止组合数字重复如123==231：for(int i = cur;i < n; ++i) dfs(i+1);**
![clipboard.png](https://pic.leetcode-cn.com/4d14042df63d8690c5432861c48a30e40d4f4b5a169b7b611e92dc8daebbba5a-clipboard.png)


3. **(需要先排序)数组中有重复数字1,1',2 但组合时1 1'2 == 1'1 2 :if(i > 0 && nums[i] == nums[i-1] && !vis[i-1]) continue;**

 

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    int vis[10] = {0};
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1,k,n,0);
        return ans;
    }

    void dfs(int cur,int k, int n,int sum){
        if(n == sum && tmp.size() == k){
            ans.push_back(tmp);
            return;
        }
        for(int i = cur; i <= 9; ++i){
            if(!vis[i]){
                vis[i]= 1;
                tmp.push_back(i);
                dfs(i+1,k,n,sum+i);
                tmp.pop_back();
                vis[i] = 0;
            }
        }
    }
};
```