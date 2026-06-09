### 解题思路
申请一个hashmap，遍历nums，把每个num对应的target-num作为字典的key，下表作为value。遍历下一个num如果在字典中，返回该下标与对应value。

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        if(nums.size() < 2) return res;
        unordered_map<int, int> dict;
        for(int i = 0; i < nums.size(); i++){
            if(dict.find(nums[i]) != dict.end()){
                res.push_back(dict[nums[i]]);
                res.push_back(i);
                return res;
            }
            else{
                dict[target - nums[i]] = i;
            }
        }
        return res;
    }
};
```
```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        if len(nums) < 2:return []
        buff_dict = {}
        for i in range(len(nums)):
            if nums[i] in buff_dict.keys():
                return [i, buff_dict[nums[i]]]
            else:
                buff_dict[target - nums[i]] = i
        return []
```