### 解题思路
现将每个正确的数放到自己对应的位置，剩下在重头扫描一遍，与位置不对应的数就是消失的数。

### 代码

```cpp
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i = 0;i<nums.size();i++){
            while(nums[i]!=i+1){
                if(nums[nums[i]-1]==nums[i])
                    break;
                else{
                    int temp = nums[nums[i]-1];
                    nums[nums[i]-1]=nums[i];
                    nums[i]=temp;
                }
            }
        }
        vector<int> res;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]!=i+1)
                res.push_back(i+1);
        }
        return res;
    }
};
```