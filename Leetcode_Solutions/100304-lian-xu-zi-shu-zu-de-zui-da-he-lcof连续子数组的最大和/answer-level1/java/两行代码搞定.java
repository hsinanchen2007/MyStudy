### 解题思路
顺序遍历数组，并累加，对任何一个元素而言：
1. 如果前面累计的和是小于0的，那么从这个元素重新开始累加
2. 如果前面累计的和是大于0的，那么继续累加
3. 每次累加都判断是否产生了最大值，并更新max
4. 返回最后的max值。

### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        int max = Integer.MIN_VALUE;
        int sum = 0;
        for(int e : nums){
            sum = sum <= 0 ? e : sum + e;
            max = sum > max ? sum : max;
        }
        return max;
    }
}
```