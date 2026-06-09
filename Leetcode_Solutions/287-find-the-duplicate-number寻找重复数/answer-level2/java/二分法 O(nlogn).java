### 解题思路
二分法牛逼,关键是要找到要二分什么东西

### 代码

```java
class Solution {
   public int findDuplicate(int[] nums) {
        int start = 1;
        int end = nums.length - 1;
        int mid=0;
        while (start < end) {
            mid = (start + end) / 2;
            int count = 0;
            for (int i = 0; i < nums.length; i++) {
                if (nums[i] <= mid) {
                    count++;
                }
            }
            if (count <= mid) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }

        return end;
    }
}
```