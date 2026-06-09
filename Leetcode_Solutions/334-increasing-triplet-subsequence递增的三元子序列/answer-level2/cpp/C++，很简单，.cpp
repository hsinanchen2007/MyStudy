### 解题思路
用两个flag来保存最小和次小的数字，有第三个大于他们两个的就返回true；
很简单，不知道问什么中等；有的中等看半天都不会，菜哭我了

### 代码

```cpp
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min_1=INT_MAX,min_2=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<min_1) {
                min_1=nums[i];
            }
            if(nums[i]<min_2&&nums[i]>min_1){
                min_2=nums[i];
            }
            if(nums[i]>min_2&&min_2>min_1) {
                return true;
            }
        }
        return false;
    }
};
```