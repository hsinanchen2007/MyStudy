### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //由于不能重复利用，所以容易想到hash
        vector<int>res;
        if(nums.size() <= 0) return res;
        unordered_map<int,int>hashMap;

        for(int i = 0; i < nums.size(); i++)
        {
            //在map中查找x+y=target
            if(hashMap.find(target - nums[i]) != hashMap.end())
            {
                res.push_back(hashMap[target-nums[i]]);
                res.push_back(i);
            }
            
            hashMap[nums[i]] = i;
        }
        return res;
    }
};
```