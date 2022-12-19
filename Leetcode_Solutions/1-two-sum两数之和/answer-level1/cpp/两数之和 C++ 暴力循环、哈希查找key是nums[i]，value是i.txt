### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    // 暴力循环
    vector<int> twoSum1(vector<int>& nums, int target) {
        int len = nums.size();
        for (int i=0;i<len-1;i++) {
            for (int j=i+1;j<len;j++) {
                if (nums[i]+nums[j] == target) {
                    return {i,j};
                }
            }
        }
       return {};
    }

    // 两遍哈希
    vector<int> twoSum2(vector<int>& nums, int target) {
        // 哈希map
        unordered_map<int,int> m;
        // 向map中添加元素，添加的是nums[i]的下标i
        for (int i=0; i<nums.size(); i++) {
            m[nums[i]] = i;
        }     
        for (int i=0; i<nums.size(); i++) {
            // 如果m中存在nums[i]的另一个加数，并且不为i，则输出下标
            if (m.find(target-nums[i]) != m.end() && m[target-nums[i]] != i) {
                return {i , m[target-nums[i]]};
            }
        }
        return {};
    }

    // 一遍哈希
    vector<int> twoSum(vector<int>& nums, int target) {
        // 哈希map
        unordered_map<int,int> m;
        for (int i=0; i<nums.size(); i++){
            // 如果m中存在nums[i]的另一个加数
            if (m.find(target-nums[i]) != m.end()) {
                // 因为不是先加入元素再查找，而是一边查找一边加入元素
                // 所以添加进去的value都还小于i，所以i在后面
                return {m[target-nums[i]] , i};
            }
            // 每一次循环都向map中添加元素，添加的是nums[i]的下标i
            m[nums[i]]=i;       
        }
        return {};
    }
};
```