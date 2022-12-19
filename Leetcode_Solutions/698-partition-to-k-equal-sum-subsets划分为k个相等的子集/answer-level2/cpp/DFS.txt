### 解题思路
DFS

### 代码

```cpp
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sum = accumulate(nums.begin(), nums.end(), 0);  //求总和
        if(sum % k != 0) 
            return false;  //如果总和不能被平均分配到k份，就返回false
        vector<bool> visited(nums.size(), false);  //记录元素是否已经被划分过

        return dfs(nums, visited, 0, sum/k, 0, k);
    }
    bool dfs(vector<int>& nums,vector<bool>& visited,int start,int target, int cursum, int k)
    {
        if(k == 1) return true;  //只剩下一个待分集合，就可以直接返回true了

        else if(cursum > target) return false;

        else if(cursum == target) return dfs(nums, visited, 0, target, 0, k-1); //找到一个分配集合，则要将搜索起始位置start重置为0，待分配子集剩下k-1个
        else
        {
            for(int i = start; i < nums.size(); i++)
            { 
                //从start开始找
                if(visited[i] == false)
                {  //看是否已被访问过
                    visited[i] = true;  //访问当前元素
                    if(dfs(nums, visited, i+1, target, cursum+nums[i], k)) 
                        return true;
                    visited[i] = false;
                }
            }
            return false;
        }
    }
};
```