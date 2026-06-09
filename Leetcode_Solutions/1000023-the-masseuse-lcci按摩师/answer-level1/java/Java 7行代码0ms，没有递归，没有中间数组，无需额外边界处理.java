### 解题思路
出自大神rational irrationality在官方题解中的回复，代码苗条至极，没有一丝赘肉，佩服！
———————————————————————————————————————
牛逼之处：
1、正向思维，计算前k个数的最大和时，仅使用前k-2和k-1的最大和即可（动态变化，无需额外数组）；
2、两个初始值设在索引-2和-1的位置，不用再考虑nums是否为空的情况。
计算过程：
在遇到第k个数时，需要保存前k-1个数的最大和(已知)，与前k个数的最大和(简单计算)；
当k = nums.length时，直接得到前k个数的最大和。

### 代码

```java
class Solution {
    public int massage(int[] nums) {
        int tmp, before2Max = 0, before1Max = 0;
        for(int curr: nums){
            tmp = before1Max;
            before1Max = Math.max(before2Max + curr, before1Max);
            before2Max = tmp;
        }
        return before1Max;
    }
}
```