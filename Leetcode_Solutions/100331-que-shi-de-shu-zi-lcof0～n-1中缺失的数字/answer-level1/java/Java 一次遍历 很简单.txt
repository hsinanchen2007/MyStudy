### 解题思路
因为数组递增排序且数字唯一，并且每个数字都在范围0～n-1之内，那么数组没有缺失的情况下数组下标和值是相等的
那只需要找出第一个数组下标和值不相等的数就是缺失的数字

### 代码

```java
class Solution {
    public int missingNumber(int[] nums) {
        for(int i=0;i<nums.length;i++){
            if(i!=nums[i])return i;
        }
        //特殊情况:当前面都没有缺失只能是缺失了最后一个数
        return nums.length;
    }
}
```