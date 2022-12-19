### 解题思路
这道题最优解应该是贪心，我先用动态规划解答一下
题型：动态规划－存在性问题
思路：
第一步：确定状态
    最后一步：最后一步就是跳到终点的前一个落点
    子问题：假设终点为n,终点前的落点为j,则我们的子问题就是是否可以到达j点
第二步：列出转换方程
    根据上一步分析的，可以得出，f[j］＝f[i]&&j-i>＝nums[i],其中数组f[]为boolean类型，这个方程的意思就是，是否可以到达j点，需要保证两个条件：i点(j点的前一个落点)必须可达；而且i点和j点之间的距离不能超过青蛙在i点最远可以跳到的距离
第三步：确定初始状态和边界情况
    初始状态：f[0]=true
    本题没有边界问题
由于boolean类型的变量，在Java中默认为false，所以f[j]=false，可以省略
### 代码

```java
class Solution {
    public boolean canJump(int[] nums) {
        int n=nums.length;
        boolean[] f=new boolean[n];
        f[0]=true;
        for(int j=1;j<n;++j){
            //f[j]=false;
            for(int i=0;i<j;++i){
                if(f[i]&&j-i<=nums[i]){
                    f[j]=true;
                    break;
                }
            }
        }
        return f[n-1];
    }
}
```