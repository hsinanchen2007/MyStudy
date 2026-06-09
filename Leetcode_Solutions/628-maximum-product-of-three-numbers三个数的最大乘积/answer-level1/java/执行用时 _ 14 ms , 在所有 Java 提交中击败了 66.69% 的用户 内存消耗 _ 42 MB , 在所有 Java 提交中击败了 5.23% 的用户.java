### 解题思路
如果该题全是正数，那么会非常容易，只需一次排序即可，但如果出现负数，会因为再大的负数也不大于0，所以针对负数，我们选取两最小负数和最大数相乘，无论该最大数为正或为负（即使全为负，将并入第一种全是正数的情况），因此我们可以尝试比较这两个值，返回较大值即可，本题需要先对整型数组进行排序操作处理。

### 代码

```java
class Solution {
    public int maximumProduct(int[] nums) {
        Arrays.sort(nums);
        for(int i = 0;i<nums.length/2;i++) {
            int temp = nums[i];
            nums[i] = nums[nums.length-i-1];
            nums[nums.length-i-1] = temp;
        }
        return nums[0]*nums[1]*nums[2]>nums[0]*nums[nums.length-1]*nums[nums.length-2]?nums[0]*nums[1]*nums[2]:nums[0]*nums[nums.length-1]*nums[nums.length-2];
    }
}
```