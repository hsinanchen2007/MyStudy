废话不多说,先贴代码
```java
class Solution {
    public void moveZeroes(int[] nums) {
        int snowBallSize = 0;
        for (int i = 0; i < nums.length; i++ ) {
            if( nums[i] == 0){
                snowBallSize++;
            }else if(snowBallSize > 0) {
                int temp = nums[i];
                nums[i] = 0;
                nums[i - snowBallSize] = temp;
            }
        }
    }
}
```
题解来自国际站的一位小姐姐的贡献.浏览了中国站的题解后,大部分都是以Swap交换或者是数组最后填充0的思想
这位小姐姐的思路很有意思,我只是搬运过来并附上我自己画的图解供大家参考
想法是我们遍历数组并收集道路上的所有零,就好像滚雪球一样,从一个小雪球沿路滚(遍历数组)占到路上的雪(元素为0)然后变成大雪球
![滚雪球.png](https://pic.leetcode-cn.com/0708ff27eeb8fab3d434de0ca924622e04a3e155058ed99f573ec31e2bcb9612-%E6%BB%9A%E9%9B%AA%E7%90%83.png)
步骤图解
![IMG_0340.jpg](https://pic.leetcode-cn.com/55a089df8bc7320151123d91f0863279b2d46f1d93475de62ca2568e5f2c56e6-IMG_0340.jpg)
自己画的,不是很好看.谅解谅解
附上链接:[传送门](https://leetcode.com/problems/move-zeroes/discuss/172432/THE-EASIEST-but-UNUSUAL-snowball-JAVA-solution-BEATS-100-(O(n))-%2B-clear-explanation)

