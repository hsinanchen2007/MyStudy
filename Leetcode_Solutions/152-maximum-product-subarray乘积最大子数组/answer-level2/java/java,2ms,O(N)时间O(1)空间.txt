### 解题思路
对于连续子序列的题，假设dp[i]为指定必须以i结尾的子序列，则该子序列的最优解对应的值为dp[i]。对所有dp[i]取最大值即可得到答案。

这里假设必须以i结尾，通过对例子分析：
     2  3  -2  4    -1   0    4
max  2  6  -2  4    -1    0   4
min  2  3  -12 -48   48   0    4

可以看出需要保留最小值，以便将来遇到负数的话，负负相乘可能得到最大值。

根据以上分析，max[i]有三种情况：
1. a[i]:max,min=0&&a>9时
2. max[i-1]*a[i]:max>0&&a>0时
3. min[i-1]*a[i] :min<0&&a<0时

类似的，min[i]也可能从这三个值里出现

在实现上，使用循环得到dp即可，由于只依赖于i-1，所以可以对一维dp进行压缩，压缩成常量的空间。

### 代码

```java
class Solution {
    public int maxProduct(int[] nums) {
        //dp
        if(nums==null||nums.length==0){
            return 0;
        }
        int n=nums.length;

        int max=nums[0];
        int min=nums[0];
        int result=max;
        for(int i=1;i<n;i++){
            int res1=max*nums[i];
            int res2=min*nums[i];
            int res3=nums[i];
            max=Math.max(Math.max(res1,res2),res3);
            min=Math.min(Math.min(res1,res2),res3);
            result=Math.max(max,result);
        }
        return result;
    }
}
```