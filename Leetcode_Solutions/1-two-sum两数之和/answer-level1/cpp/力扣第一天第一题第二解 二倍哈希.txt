### 解题思路
力扣第一天第一题第二解 二倍哈希

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     
        unordered_map<int,int> m;
        //两遍哈希

        for(int i=0;i<nums.size();i++)
            m[nums[i]] = i; //向map中添加元素
        
        for(int i=0;i<nums.size();i++)
        {
                if(m.find(target-nums[i])!= m.end() && m[target-nums[i]] != i) //如果m中存在对应的键值，并且不为i
                    return {i , m[target-nums[i]]};
        }
        return {};
    }
};
```