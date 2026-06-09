### 解题思路
主要借助 map 结构，保存每个元素对应的索引数组，如果有重复元素，这对应的 vector<int> 就是重复元素的索引，其大小就是重复元素的度，其最后一个元素和第一个元素的差值 + 1 就是含有重复元素的子数组的长度。

逻辑有点绕，动手写下代码就懂了。

### 代码

```cpp
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        // 1. 利用 map 确定每个元素的度 (相同元素的所有索引)
        unordered_map<int, vector<int>> degree_map;
        
        // map 的 second 是 vector，所以用 push_back
        for (int i = 0; i < nums.size(); i++)
            degree_map[nums[i]].push_back(i);

        // 每个元素的度
        int n_degree = 0;

        // 数组的度
        int nums_degree = 0;

        // 与数组度数相同的最短子数组的长度
        int min_len = 0;

        int tmp_len = 0;

        // 2. 求跟原数组的度相同的最短子数组的长度
        for (auto n : degree_map) {
            // 3. 求每个元素 n 的度
            n_degree = n.second.size();
            
            if (n_degree >= nums_degree) {
                // 4. 求每个子数组的长度
                tmp_len = n.second[n_degree - 1] - n.second[0] + 1;

                if (n_degree == nums_degree) {
                    // 5. 找到度数相同子数组，每次取最小值
                    min_len = min(min_len, tmp_len);
                } else {
                    // 这是 degree > nums_degree 的情况
                    
                    // 求数组最大的度
                    nums_degree = n_degree;

                    // 更新子数组的长度
                    min_len = tmp_len;
                }
            }
        }

        return min_len;
    }
};
```