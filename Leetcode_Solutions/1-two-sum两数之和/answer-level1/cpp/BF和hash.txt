### 解题思路
方法1: BF
两个for 循环，当nums[i] + num[j] == target时，输出i,j

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size(), i, j;
        for(i = 0; i< len; ++i){
            for(j = i + 1; j < len; ++j){
                if(nums[i] + nums[j] == target){
                    return {i, j};
                }
            }
        }
        return {};
    }
};

### 解题思路
方法2: hash
建立一个hash Table，key为nums[i],value为i； 然后find进行查找，如果target减去nums[i]能在hash中查找到，且不是他本身（例如4=2+2，6=3+3这种情况）；直接return两个值，i和hash[target - nums[i]]。

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        map<int, int> hash;
        for(int i = 0; i < len; ++i){
            hash[nums[i]] = i;
        }
        for(int i = 0; i < len; ++i){
            if(hash.find(target - nums[i]) != hash.end() && hash[target - nums[i]] != i)
            return {i, hash[target - nums[i]]};
        }
        return {};
    }
};
```