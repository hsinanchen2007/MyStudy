### 解题思路

1. 从左往右找偶数，从右往左找奇数。
2. 交换
3. 继续找

### 代码

```java
class Solution {
    public int[] exchange(int[] nums) {
        return exchangeO1(nums);
        // return exchangeON(nums);
    }

    public int[] exchangeON(int[] nums) {
        int[] nn = new int[nums.length];
        int left = 0;
        int right = nums.length - 1;
        for(int i = 0; i < nums.length; i ++) {
            if(nums[i] % 2 == 0) {
                nn[right --] = nums[i];
            } else {
                nn[left ++] = nums[i];
            }
        }
        return nn;
    }

    public int[] exchangeO1(int[] nums) {
        int left = 0;
        int right = nums.length - 1;
        while(left < right) {
            while(nums[left] % 2 == 1 && left < right) {
                left ++;
            }
            while(nums[right] % 2 == 0 && left < right) {
                right --;
            }
            int tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;
        }
        return nums;
    }
}
```