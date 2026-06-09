### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> ans; //用于存放最终结果
    vector<int> path; // 深度优先搜索路径

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());// 首先进行排序，方便后续处理
        dfs(nums, 0, path); // 深度优先搜索过程
        return ans;
    }

    void dfs(vector<int>& nums, int start, vector<int> tmp) {
        ans.push_back(tmp); // 每递归一层，先把当前路径放到结果中(因为是要拿到所有的子集)
        for (int i = start; i < nums.size() ; ++i) { // 对每一层进行遍历
           if (i > start && nums[i] == nums[i-1]) continue; // 这里的i > start是关键，一会讲
           tmp.push_back(nums[i]);
           dfs(nums, i + 1, tmp);
           tmp.pop_back(); // 恢复原状
        }
    }
};
```
此题是78题的变种，要求是不产生重复的子集，对于这种不产生重复元素的问题，一般来说，首先想到的就是排序。

在对数组进行了排序后，按照和78题一样的步骤进行。

**这里需要注意的是，每一层的重复元素只能取一个**，所以有 **nums[i] == nums[i-1]** 就continue。
下面讲解一下这个题目比较难想的地方，**i > start** 这个条件，这个条件是有两个作用的：
1. 保证i > 0，这样在判断nums[i] == nums[i-1]不会发生越界。
2. 如果这个条件换成i > 0，那么在递归到下一层时，重复元素就还是取不到，例如普通的用例{1,2,2},最终子集只能取到{1,2}，第三个位置的2被continue了，但是如果使用i > start，那么在i == start时，就不会continue，这样保证了每一个元素都会在递归时至少被取到一次，保证了子集的完整性。