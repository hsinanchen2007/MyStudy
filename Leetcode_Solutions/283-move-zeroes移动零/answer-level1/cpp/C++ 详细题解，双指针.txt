## 思路
- 0 移动到数组的末尾，相当于将非零数字全部移到第一个 0 的前面。
- 找到第一个零，将第一个零之后的第一个非零数字与该 0 交换，从此之后令 nums[i] 永远等于数组内的第一个 0，nums[j] 永远等于第一个 0 后面的第一个非零数字，交换他们俩即可
- 这样，既保持了非零元素的相对顺序，也将所有的 0 移动到了数组末尾
```
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for(i = 0; i < nums.size() && nums[i] != 0; ++ i); //找到第一个0；
        for(int j = i + 1; j < nums.size(); ++ j) //将第一个零之后的第一个非零数字与该0交换
        {
            if(nums[i] == 0 && nums[j] != 0)
            {
                swap(nums[i],nums[j]);
                ++ i;
            }
        }
    }
};
```