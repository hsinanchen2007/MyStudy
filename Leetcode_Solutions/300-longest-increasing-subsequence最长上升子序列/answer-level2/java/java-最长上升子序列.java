~~目前只明白时间复杂度为N^2的：~~
现在已经明白动态规划+二分法的解法了。
##### 方法一：动态规划法
新建一个数组dp,初始化为1， for(i->nums)不断地与i之前的nums中的元素进行比较，并且更新dp[i],如果i大于前面的元素，比较此时dp[i]的大小和dp[j] + 1的元素的大小，选择更大的数来更新dp[i]，直到i遍历完nums为止，每次比较之后都要保存最大的dp值，与之前没b更新过的最大dp值进行比较。
### 代码

```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        int dp[] = new int[nums.length];
        Arrays.fill(dp, 1);
        int res = 0;
        for(int i = 0; i < nums.length; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j])
                    dp[i] = Math.max(dp[i], dp[j] + 1);
            }
            res = Math.max(dp[i], res);
        }
        return res;
    }
}
```

##### 方法二：动态规划+二分法
这道题的解法写得很长，最开始看不进去也看不懂，找了一个比较简单的讲解方法，[参考地址](https://blog.csdn.net/zjwreal/article/details/91049705)
再简单记录一下：
维护一个数组tails,遍历nums数组，使用二分法每次都要将num与tails数组进行比较，如果是num>tails中所有的数，就将num插入到最后一个元素，否则将tails数组中比num大的最小的一个数用num替代，更新res的大小（即tails的长度），最后res的值即最长上升子序列的长度。
```
class Solution {
    public int lengthOfLIS(int[] nums) {
       int tails[] = new int[nums.length];
       int res = 0;
       for(int num: nums){
           int i = 0, j = res;
           while(i < j){
               int m = (i + j) / 2;
               if(tails[m] < num) i = m + 1;
               else j = m;
           }
           tails[i] = num;
           if(j == res) res++;
       }
       return res;
    }
}
```
