### 解题思路
此处撰写解题思路

+ 记录最大值的2倍和索引k
+ 最大值的2倍必须大于其他值的4倍才满足条件

### 代码

```java
class Solution {
 public int dominantIndex(int[] nums) {
        int max = 0;
        int k =0;
        for (int i = 0; i < nums.length; i++) {
            if (max/2<nums[i]){
                max = nums[i]*2;
                k=i;
            }
        }
        for (int j = 0; j < nums.length; j++) {
            if (j!=k&&nums[j]*4>max){
                return -1;
            }
        }
        return k;
    }
}
```