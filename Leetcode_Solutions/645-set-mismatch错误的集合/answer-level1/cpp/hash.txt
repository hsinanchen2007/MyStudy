### 解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int hashTable[nums.size() + 1] = {0};
        vector<int> ans;
        for(int i = 0 ; i < nums.size() ; ++i)
        {
            hashTable[nums[i]] += 1;
            if(hashTable[nums[i]] > 1)
            {
                ans.push_back(nums[i]);
            }
        }
        for(int i = 1 ; i <= nums.size() ; ++i)
        {
            if(hashTable[i] == 0)
            {
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};
```