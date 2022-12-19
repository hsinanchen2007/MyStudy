### 解题思路
这题视角很独特，
 1、如果是一系列数组串，那么肯定 数组串前后 数字 肯定都是正数，所以有 min < 0 ;
 2、如果都是负数，那么肯定是一个最小的数
     这里最大的负数 ，通过 思路 3 的比较 就可以得到最大的负数
  3、 结果实在过程中，而不是在最终的形态上
     所以才有sum 与 min的比较
   




### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        int n = nums.length;
    
        int min = nums[0];
        int sum = min;
        for (int i=1;i<n;i++) {
            if (min<0) {
                min = nums[i];
            } else {
                min += nums[i];
            }

            if (sum<min) {
                sum = min;
            }
        }
        return sum;
    }
}
```