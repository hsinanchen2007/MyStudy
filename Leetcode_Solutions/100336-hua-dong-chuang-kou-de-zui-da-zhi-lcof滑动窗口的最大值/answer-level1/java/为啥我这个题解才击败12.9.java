```
public int[] maxSlidingWindow(int[] nums, int k) {
        if(nums == null || nums.length == 0) {
            return new int[] {};
        }
        boolean flag = false;
        int[] res = new int[nums.length + 1 - k];
        for (int i = 0; i < nums.length; i++) {
            int max = nums[i];
            for (int j = 0; j < k; j++) {
                if(i+j >= nums.length) {
                    flag = true;
                    break;
                }
                if(nums[i+j] > max) {
                    max = nums[i+j];
                }
            }
            if(!flag) {
                res[i] = max;
            }
        }
        return res;
    }
```
![image.png](https://pic.leetcode-cn.com/9d8fedd3e1bad56960482360a772cae2e484f35799cdf790934b221d2f8e9592-image.png)

