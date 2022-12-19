### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int nthUglyNumber(int n) {
        int[] nums = new int[n];
        nums[0] = 1;

        int i2 = 0, i3 = 0, i5 = 0;
        int temp = 1;

        for (int i = 1; i < n; i++) {
            temp = Math.min(Math.min(nums[i2] * 2, nums[i3] * 3), nums[i5] * 5);
            nums[i] = temp;
            //注意这里if分开写有去重作用
            if (temp == nums[i2] * 2) {
                i2++;
            } 
            if (temp == nums[i3] * 3) {
                i3++;
            }
            if (temp == nums[i5] * 5) {
                i5++;
            }
        }

        return nums[n - 1];
    }
}
```