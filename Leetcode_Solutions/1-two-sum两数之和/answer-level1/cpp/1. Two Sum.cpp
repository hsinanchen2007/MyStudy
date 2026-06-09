### 解题思路
一次遍历数组，如果不存key target-nums[i]，就作为键加入哈希表，如果存在，就返回[i, map[target-nums[i]]]

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>vectMap;
        vector<int> ret;
        for(int i = 0; i < nums.size(); i++){
            if(vectMap.count(target - nums[i])){
                ret.push_back(i);
                ret.push_back(vectMap[target-nums[i]]);
                return ret;     
            }
            vectMap[nums[i]] = i;
        }
        return ret;
    }
};
```