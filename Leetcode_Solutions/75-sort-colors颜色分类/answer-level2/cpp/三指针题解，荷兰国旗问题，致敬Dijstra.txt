```c++
//记住，这道题是dijstra提出的，用三指针法解决，用于优化快速排序。按照以下流程，任意数字都可以选为轴值。
// [0, l - 1] 存储小于轴值的元素
// [l, i - 1] 存储等于轴值的元素
// [i, g]还未排序
// [g + 1, N - 1]存储大于轴值的元素，N为nums数组长度。
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int i = 0;
        while(i <= r)
        {
            if(nums[i] == 0)
                swap(nums[i++], nums[l++]); // l在执行l++之前，存储的元素等于轴值，故交换i位置、l位置的数值后，i元素位置的新数值一定等于轴值，所以i元素也可以执行i++
            else if(nums[i] == 2)
                swap(nums[i], nums[r--]);   // 交换i、r位置的数值后，由于r位置的数值未知，所以i位置保持不变，下一次继续判断i位置的新数值。
            else
                i++;
        }
    }
};
```
解法借鉴了jianshu.com/p/d70aeccaee19
