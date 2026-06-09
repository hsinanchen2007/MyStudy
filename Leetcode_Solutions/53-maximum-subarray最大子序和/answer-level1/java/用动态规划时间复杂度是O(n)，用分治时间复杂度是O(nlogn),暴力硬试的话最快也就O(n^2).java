### 解题思路
![QQ截图20200311152957.png](https://pic.leetcode-cn.com/b2513c84e657c64ee7d63903829bfb7d0321e25d6fb4beddb12e8eae4a1ca016-QQ%E6%88%AA%E5%9B%BE20200311152957.png)

动态规划方程给您摆这了，爷：
最大子序和=max(sum(nums[i]...nums[j])),其中0<=i<=j<=nums.length
         =max(b[j]),其中0<=j<=nums.length
而b[j]=max{b[j-1]+nums[j],nums[j]},当b[j-1]>0时b[j]=b[j-1]+nums[j];否则,b[j]=nums[j]
b[j]的实际意义是从任意i处加到j,包括nums[j]这个元素在内的最大和，即b[j]=max(sum(nums[i]...nums[j])),此时j固定，i<=j
sum就是最大的那一个b[j]
### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
       int sum=nums[0],b=nums[0];
        for(int j=1;j<nums.length;j++){
            if(b>0) {b+=nums[j];}
            else {b=nums[j];}
            if(b>sum) {sum=b;}
        }
        return sum;

    }
}
```