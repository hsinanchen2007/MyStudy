### 解题思路
思路比较直接，也比较好理解

### 代码

```java
class Solution {
     public int search(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) { //中间值等于查找值，向左右移动找查找值并记录个数。
                int count = 1;
                int temp = mid - 1;
                while (temp >= left && nums[temp] == target) { //temp >= left！防止越界。
                    count++;
                    temp = temp - 1;
                }
                temp = mid + 1;
                while (temp <= right && nums[temp] == target) {
                    count++;
                    temp = temp + 1;
                }
                return count;
            } else if (nums[mid] > target) { //中间值大于查找值。
                right = mid - 1;
            } else { //中间值小于查找值。
                left = mid + 1;
            }
        }
        return 0;
    }


}
```