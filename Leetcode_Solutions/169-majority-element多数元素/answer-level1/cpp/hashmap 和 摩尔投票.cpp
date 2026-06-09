### 解题思路
两种方法

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //hashmap
        /*unordered_map<int, int> hash;
        int res;
        for(int i = 0; i < nums.size(); i++){
            hash[nums[i]] += 1;
            if(hash[nums[i]] > nums.size() / 2){
                res = nums[i];
                break;
            }
        }*/
        //摩尔投票
        int res, count = 0;
        for(auto n : nums){
            if(count == 0){
                res = n;
                count += 1;
            }
            else{
                res == n ? count += 1 : count -= 1;
            }
        }
        return res;
    }
};
```