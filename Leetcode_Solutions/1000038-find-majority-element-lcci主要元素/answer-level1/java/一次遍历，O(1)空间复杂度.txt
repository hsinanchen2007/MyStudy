有几个解决方法
1. 暴力法：int数组记录每个数字出现的个数，再循环int[]数组，找出最多的那个数字及个数，判断个数是否大于所给数组元素个数的一半。大于返回这个数字，小于返回-1。 时间复杂度 O(2N)，空间复杂度 O(N)
2. 排序，然后取中位数，判断中位数是否大于所给数组的一半。时间复杂度O(NlogN), 空间O(1)
3. 计数法：2个变量计数，一个变量k记录当前数字，一个变量v记录数量。循环所给数组，遇到相同的数，数量v加1，不同时数量v减1，当数量v减少到0时，k替换成新的数字。因为是大于一半的数字出现，所以v>1时，k就是结果。时间复杂度 O(n) 空间复杂度 O(1)

``` java
    public int majorityElement(int[] nums) {
        int k = nums[0], count = 1;
        for (int i=1; i<nums.length; i++) {
            if (count == 0) {
                k = nums[i];
                count = 1;
            }
            count = nums[i] == k ? count + 1 : count - 1;
        }

        return count == 0 ? -1 : k;
    }
```
