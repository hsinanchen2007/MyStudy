### 解题思路

两次预约之间不能多于3个预约，否则一定不是最优的。

![图片.png](https://pic.leetcode-cn.com/53f5e119b999767d0afa55575eee5f4031c8adc19b86d2a18ae2a3d1cedecee5-%E5%9B%BE%E7%89%87.png)

### 代码

```java
class Solution {
    public int massage(int[] nums) {
        int result = 0;
        for (int i = 0; i < nums.length; i++) {
            int val = 0;
            if (i >= 2) val = Math.max(val, nums[i - 2]);
            if (i >= 3) val = Math.max(val, nums[i - 3]);
            nums[i] = val + nums[i];
            result = Math.max(result, nums[i]);
        }

        return result;
    }
}
```