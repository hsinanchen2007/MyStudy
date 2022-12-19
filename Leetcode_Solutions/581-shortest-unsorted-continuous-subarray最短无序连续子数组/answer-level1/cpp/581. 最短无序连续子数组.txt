## 一次循环，双指针，分别找出左右边界
```cpp
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int len = nums.size();
        int left=0, right=-1, _min=nums[len-1], _max=nums[0];
        //max和min是遍历过的值里面的最大和最小值
        //left和right是无序数组的左右边界
        for(int i=0, j=len-1; i<len; i++, j--){
            if(nums[i]<_max) right = i;
            else _max = nums[i];
            if(nums[j]>_min) left = j;
            else _min = nums[j];
        }
        return right-left+1;
    }
};
```
## 两次循环，分别找出左右边界
```cpp
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int len = nums.size();
        //_max和_min是遍历过的值里面的最大和最小值
        //left和right是无序数组的左右边界
        //找出right位置
        int _max=nums[0], right=-1;
        for(int i=1; i<len; i++){
            if(nums[i]<_max) right=i;
            else _max=nums[i];
        }
        //找出left位置
        int _min=nums[len-1], left=0;
        for(int i=len-2; i>=0; i--){
            if(nums[i]>_min) left=i;
            else _min=nums[i];
        }
        return right-left+1;
    }
};
```