### 解题思路
要不就是空间换时间 要不就是时间换空间，各取所需，执行效率较低，内存使用较少，随手一写仅供参考

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,j;
        vector<int>vec;
        for(i = 0; i<nums.size(); ++i )
        {
            int sub1=target -nums[i];
            for(j = (i+1);j<nums.size(); ++j){
              if(nums[j]==sub1){
                  vec.push_back(i);
                  vec.push_back(j);
                  return vec;
              }

            }
        }
        return vec;
    }
      
};
```