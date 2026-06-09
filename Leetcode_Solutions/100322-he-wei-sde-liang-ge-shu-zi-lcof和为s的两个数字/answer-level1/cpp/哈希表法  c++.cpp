### 解题思路
此处撰写解题思路
用一个哈希表作为辅助，哈希表的键为target-nums[i],值为nums[i];遍历nums，查找nums[i]，如果有以nums[i]为键的元素，则说明其值为target-nums[i]，于是将nums[i]与target-nums[i]放进结果向量，否则将nums[i]放进辅助表。
### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mymap;
        vector<int> res;
        int i;
        for(i = 0;i < nums.size();i++){
            if(mymap.find(nums[i]) != mymap.end()){
                res.push_back(nums[i]);
                res.push_back(target-nums[i]);
                break;
            }
            else
                mymap[target-nums[i]] = nums[i];
        }
        return res;
    }
};
```