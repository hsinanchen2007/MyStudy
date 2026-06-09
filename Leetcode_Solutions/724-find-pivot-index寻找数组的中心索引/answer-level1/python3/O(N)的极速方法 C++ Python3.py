该方法可击败90%以上的时间和空间。

思路是这样，设置两个变量left和right，一个记录从左边开始的和，一个记录从右边开始的和。
当遍历的时候，中心索引左边的和即left,中心索引右边的和即right，左边和右边不相等时，遍历进入数组的下一项，left增加一项，right减少一项。

看代码的话，由两次遍历数组组成。首先需要遍历从第二项到最后一项的和，记录在right里。left是0。此时假定的中心索引为第一项。

第二次遍历即判断left是否等于right，不相等进入数组的下一项，left需要增加这一项的和，right需要减少下一项的和。

最开头和最后做了针对数组长度为0以及中心索引在最后的处理。

当然也可以认为left只要等于(和-遍历的当前项)/2即可，只是上面的好理解一点，原理都差不多，复杂度也是一样的，这个记录在了python3的代码里。

C++ 代码如下：
```c++
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.size() == 0) return -1;
        int left
        int right = 0;
        for (int i=1;i<nums.size();i++){
            right += nums[i];
        }
        for (int i=0;i<nums.size() -1 ;i++){
            if (right == left) return i;
            right = right - nums[i+1];
            left += nums[i];
        }
        if (left==right) return nums.size() - 1;
        else return -1;
    }
};
```
Python3 代码如下：
```python
class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        total = sum(nums)
        part_sum = 0
        for i, j in enumerate(nums):
            if part_sum == (total - j) / 2:
                return i
            part_sum += j
        return -1
```