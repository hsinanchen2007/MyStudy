### 解题思路
先拿出第一个数与目标比较决定数组的遍历顺序
情况1：第一个数比目标大
说明目标不可能在数组旋转的前半段，开始从后往前找；
情况2：反之

### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
        if(nums.length==0) return -1;
        //取出第一个与目标比较，如果目标大于该数值则倒序遍历。反之顺序遍历
        if (nums[0] > target) {  //逆序遍历
            int minv = Integer.MAX_VALUE;
            for (int i = nums.length - 1; i >= 0; i--) {
                if (nums[i] == target)
                    return i;
                else {
                    if (nums[i] < minv)
                        minv = nums[i];
                    else return -1;
                }
            }
        } else {
            int maxv = Integer.MIN_VALUE;
            for (int i = 0; i < nums.length; i++) {
                if (nums[i] == target)
                    return i;
                else {
                    if (nums[i] > maxv)
                        maxv = nums[i];
                    else return -1;
                }
            }
        }
        return -1;
    }
}
```