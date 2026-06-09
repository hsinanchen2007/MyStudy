### 解题思路
将数组的值看作是数组的下标，进行循环交换，这样重复的值会指向同一个下标

### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for(int i=0;i< nums.size();i++){
            int x = nums[i];
            while(x != i){
                if(nums[x] == x) return x;
                swap(nums[i], nums[x]);
                x = nums[i];
            }
        }
        return 0;
    }
};
```