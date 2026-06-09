![image.png](https://pic.leetcode-cn.com/c665d24c60814cfc55a8c11fb1b08ae11c4ff015650f28ebf902b5ff2bc37135-image.png)

思路：
1、看到这题的第一印象就是找最大的三个值，前提是没有负数的存在。
2、如果全部是正数，那确实是三个最大值相乘
3、但是包含负数怎么办，比如这种情况：[-5,-4,0,1];按上面的想法输出的是错误的0，但是正确答案应该是20；
4、所以我们想的就是，三个数的最大乘积最大值出现无非有两种情况：
①：两个最小的负数 X 一个最大的整数
②：三个最大的正数相乘
5、取其最大值就行
```
class Solution {
    public int maximumProduct(int[] nums) {
        int max1 = -1000;
        int max2 = -1000;
        int max3 = -1000;
        int min1 = 0;
        int min2 = 0;
        for (int i = 0; i < nums.length; i++){
            if (nums[i] >= max1){
                //找到当前最大，所以倒着开始更新最大的三个值
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            }else if (nums[i] >= max2){
                //假设max1已经找到最大，但是max2没有
                //因此还得更新max2
                max3 = max2;
                max2 = nums[i];
            }else if (nums[i] >= max3){
                //更新max3
                max3 = nums[i];
            }
            if (nums[i] <= min1){
                //同理找最小值
                min2 = min1;
                min1 = nums[i];
            }else if (nums[i] <= min2){
                //更新
                min2 = nums[i];
            }
        }
       //返回这两种情况的最大值
        return (int)(Math.max(max1*max2*max3,min1*min2*max1));
    }
}

```

