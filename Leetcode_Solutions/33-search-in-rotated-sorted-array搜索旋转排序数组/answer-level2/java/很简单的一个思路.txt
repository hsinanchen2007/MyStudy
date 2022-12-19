![image.png](https://pic.leetcode-cn.com/ab6e3ac5a3f9fa92ae01e7b8c4652849720575af41d4ecd1557f5c3dcc86d84b-image.png)

target>=第一个数时，从头至尾开始比较
target<第一个数时，从尾至头开始比较
当然比较策略可以稍微优化。

```
public int search(int[] nums, int target) {
        if (nums.length == 0) return -1;
        if (target >= nums[0]) {
            for (int i = 0; i < nums.length; i++) {
                if (target == nums[i])
                    return i;
                else if (target < nums[i])
                    return -1;
            }
        } else {
            for (int i = nums.length - 1; i >= 0; i--) {
                if (target == nums[i])
                    return i;
                else if (target > nums[i])
                    return -1;
            }
        }
        return - 1;
    }
```
