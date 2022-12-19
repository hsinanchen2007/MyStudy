### 解题思路
因为不允许生成新数组,所以在原数组上做修改,考虑把循环到的元素如果符合要求和当前数组的最后一位进行交换,每次交换后维护一个变量以排除该元素,做一次循环,条件为当前数组个数减去相同元素的个数,当循环的元素相同时把该元素和最后一位元素进行交换并且相同个数+1,否则检测下一个元素,循环完毕获取到排序后的数组,根据数组的个数和变量的个数获取到最后的数组个数

### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        if(nums == null || nums.length == 0) return 0;
        int count = 0;
        int temp;
        for(int i = 0;i < nums.length - count;) {
            if(nums[i] == val) {
                temp = nums[nums.length - 1 - count];
                nums[nums.length - 1 - count] = nums[i];
                nums[i] = temp;
                count++;
            } else {
                i++;
            }
        }
        return nums.length - count;
    }
}
```