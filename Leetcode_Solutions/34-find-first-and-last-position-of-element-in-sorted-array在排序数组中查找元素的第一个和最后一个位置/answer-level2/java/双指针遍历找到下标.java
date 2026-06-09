### 解题思路
首先针对于数组的长度进行判断，对于有序数组可以通过判断开端和末尾与 target 进行大小判断，从而返回[-1,-1]
然后对于 target 属于数组的大小范围内，则分两种情况：
    1. 当 target 在数组内时，通过双指针遍历当nums[i] 和 nums[j] 都等于 target 时，退出循环，返回数组
    2. 当 target 不在数组内时，当双指针中尾指针小于起始指针时，返回 [-1,-1]


### 代码

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int len = nums.length;
        if(len == 0 || nums[0] > target || nums[len-1] < target )
            return new int[]{-1,-1};

        int i = 0;
        int j = len - 1;
        while(nums[i] != target || nums[j] != target) {

            if(nums[i] != target) 
                i++;
            if(nums[j] != target)
                j--;
            if(j<i)
                return new int[]{-1,-1};
        }
        return new int[]{i,j};
    }
}
```