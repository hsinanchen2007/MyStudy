### 题目描述
![image.png](https://pic.leetcode-cn.com/1b784152ec42aaa786a28f7bfefcd619fea8a39e8a64623a242709205ddbd694-image.png)


### 代码

```cpp
// 一次哈希
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int ,int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (res.find(target - nums[i]) != res.end() && res[target - nums[i]] != i) {
                return { res[target - nums[i]], i};
            }
            res[nums[i]] = i;
        }
        return {};
    }
};


// 两次哈希
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]] = i;         //向map中添加元素
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(target-nums[i]) != m.end() && m[target-nums[i]] != i)     //如果m中存在对应的键值，并且不为i
                return {i , m[target-nums[i]]};
        }
        return {};
    }
};


//  暴力循环查找
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int len = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < len; j++) {
                while(nums[j] + nums[i] == target) {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
        return res;
    }
};
```

### 三次代码运行效率分析：
![image.png](https://pic.leetcode-cn.com/0d2fda68a552906d97205102c82589f3a0f8b5b6d4bd0463cca8625bab9a2415-image.png)
