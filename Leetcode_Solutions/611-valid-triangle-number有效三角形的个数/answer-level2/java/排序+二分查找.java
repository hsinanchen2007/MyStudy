### 解题思路

先排序，然后选定两个点，由于三角形的两边之和大于第三边，这样就可以使用二分查找来定位第边可以取到哪个数值。
这样做的复杂度是n^2logn

![image.png](https://pic.leetcode-cn.com/9002bd71bdd645fd82e8b73120fa038825321a6ec2528161443fb835f5ba7d47-image.png)

### 代码

```java
class Solution {
    public int triangleNumber(int[] nums) {
        Arrays.sort(nums);
        int result = 0;
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                int sum = nums[i] + nums[j];
                int k = binarySearch(nums, sum, j + 1);
                result += k - j;
            }
        }

        return result;
    }

    private int binarySearch(int[] nums, int target, int from) {
        int l = from, r = nums.length - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return r;
    }
}
```