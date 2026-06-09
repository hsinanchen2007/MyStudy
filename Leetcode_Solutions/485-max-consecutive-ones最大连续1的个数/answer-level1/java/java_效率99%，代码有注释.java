![image.png](https://pic.leetcode-cn.com/f887647518088df2b8f5d801b57445dbe89779ad9f5a0112dc30c1086ddf521a-image.png)
```
class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        // 记录最大连续值，记录当前连续长度，进行比较
        // 遇到0，则将当前连续长度清零
        int max = 0;
        int succession = 0;

        for(int i = 0; i < nums.length; i++) {
            if(nums[i] == 1) {
                succession++;
                if(succession > max) {
                    max = succession;
                }
            } else {
                succession = 0;
            }
        }
        return max;
    }
}
```

