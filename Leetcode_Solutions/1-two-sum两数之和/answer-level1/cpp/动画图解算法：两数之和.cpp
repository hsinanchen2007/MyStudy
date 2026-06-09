### 视频讲义

![LeetCode001.mp4](79923d2c-3d87-442f-b56b-9f58b1a05040){:width=500}
{:align=center}

---

### 题目解析

使用查找表来解决该问题。

设置一个 `map` 容器 `record` 用来记录元素的值与索引，然后遍历数组 `nums`。

- 每次遍历时使用临时变量 `complement` 用来保存目标值与当前值的差值。
- 在此次遍历中查找 `record`，查看是否有与 `complement` 一致的值，如果查找成功则返回查找值的索引值与当前变量的值 `i`。
- 如果未找到，则在 `record` 保存该元素与索引值 `i`。

### 动画描述

[![img](https://pic.leetcode-cn.com/07d033999c1bae86eb830070c3caf24ae1ef05c28486cf985a1dcecb737ce845)](https://pic.leetcode-cn.com/07d033999c1bae86eb830070c3caf24ae1ef05c28486cf985a1dcecb737ce845){:width=400}
{:align=center}

### 代码实现

```cpp [-C++]
// 1. Two Sum
// https://leetcode.com/problems/two-sum/description/
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> record;
        for(int i = 0 ; i < nums.size() ; i ++){
       
            int complement = target - nums[i];
            if(record.find(complement) != record.end()){
                int res[] = {i, record[complement]};
                return vector<int>(res, res + 2);
            }

            record[nums[i]] = i;
        }
    }
};
```

