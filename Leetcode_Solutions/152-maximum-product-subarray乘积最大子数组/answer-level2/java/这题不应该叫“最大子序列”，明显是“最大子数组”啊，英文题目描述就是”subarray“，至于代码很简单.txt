### 解题思路
![QQ截图20200317143857.png](https://pic.leetcode-cn.com/00576c45d5dd271e82ed85efb480044572ae4de7f7dcc2e2aa8b1aaf14bdd700-QQ%E6%88%AA%E5%9B%BE20200317143857.png)

思路也很简单，类比53.最大子段和的问题即可，
只是最大子段和的问题中，状态转移只有一种可能，那就是当m[i-1]>0时，m[i]一定是m[i-1]+nums[i]，否则m[i]=nums[i]
因为一个数，不管他正的负的，加上一个正数，一定比原来大，加上一个负的，一定比原来小

只是乘法涉及到变号的问题，稍微复杂点，要考虑两种情况，同号或者异号
我这里偷了懒，没有判断nums[i-1]和nums[i]的符号问题，直接让一个dp表元素同时记录两个值：最大值和最小值
因为m[i-1]的最大值，可能和nums[i]相乘后就成了m[i]的最小值，而m[i-1]的最小值，有可能相乘变号以后就成了m[i]的最大值,
还有可能m[i]的最大值就是nums[i]自己
所以共有三种情况
动态规划方程即：
m[i][0]=max{
nums[i],
nums[i]*m[i-1][1],
nums[i]*m[i-1][0]
}
m[i][0]记录的就是到下标位i处的子数组(必须包括nums[i])的最大乘积
nums.length个m[i][0],其中的最大值就是问题的解
### 代码

```java
class Solution {
    public int maxProduct(int[] nums) {
        int [][] m=new int[nums.length][2];
        m[0][0]=nums[0];
        m[0][1]=nums[0];
        int max_prod=m[0][0];
        for(int i=1;i<nums.length;i++){
            m[i][0]= Math.max(Math.max(nums[i],nums[i]*m[i-1][0]),nums[i]*m[i-1][1]);
            m[i][1]=Math.min(Math.min(nums[i],nums[i]*m[i-1][0]),nums[i]*m[i-1][1]);
            max_prod=Math.max(m[i][0],max_prod);
        }
        return max_prod;
    }
}
```