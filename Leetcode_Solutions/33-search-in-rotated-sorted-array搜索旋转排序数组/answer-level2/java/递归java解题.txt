 * 思路,还是递归.  数组为:[4,5,6,7,0,1,2]  target=6. l=0,h=7, m =7/2=3,mid = nums[m]=7.
 * mid>6,那么target可能出现在 数组下标[0,2] 或是[4,6]的范围内.
 * 如果mid<target=9,那么target还可能出现在 数组下标[0,2] 或是[4,6]的范围内.
 * 如果mid = target,直接返回m就行.


```java
    public int search(int[] nums, int target) {
        return search(nums, target, 0, nums.length);
    }

    private int search(int[] nums, int target, int l, int h) {
        int m = (l + h) / 2;
        if (l <= h && m < nums.length && m >= 0) {
            int mid = nums[m];
            if (mid == target) {
                return m;
            }

            return Math.max(search(nums, target, l, m - 1), search(nums, target, m + 1, h));

        }
        return -1;
    }
```
