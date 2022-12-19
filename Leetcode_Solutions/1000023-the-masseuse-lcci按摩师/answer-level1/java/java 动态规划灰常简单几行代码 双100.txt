### 解题思路
![image.png](https://pic.leetcode-cn.com/31111372363fb722c96bb1638a02ae1d1fdf475f202cdc5239a69b95bf9a22db-image.png)
因为题目要求不能相邻，所以当前i的最优值是它前一个位置i-1的最优值，或者是它前2个位置i-2的最优值加上当前位置的数值，取两者最大值即可。
即如果将位置i的最优值记为r[i],则r[i]=max(r[i-1],r[i-2]+nums[i]), 只用到最近的两个位置所以不用保留整个r数组。

### 代码

```java
class Solution {
    public int massage(int[] nums) {
        if(nums.length<=0) return 0;
        int a=0;
        int b=0;
        int curmax = 0;
        for(int i=0;i<nums.length;i++){
            curmax = Math.max(a+nums[i], b);
            a = b;
            b = curmax; 
        }
        return curmax;
    }
}
```