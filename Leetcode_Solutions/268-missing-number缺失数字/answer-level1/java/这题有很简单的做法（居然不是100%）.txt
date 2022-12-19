执行用时 :
2 ms
, 在所有 Java 提交中击败了
94.64%
的用户
内存消耗 :
39.2 MB
, 在所有 Java 提交中击败了
97.09%
的用户


因为题目的特殊性，其实只要计算1-n的前n项和再减去参数数组的各项之和就行了。所以，直接用n项和公式可能更快。

```
class Solution {
    public int missingNumber(int[] nums) {
        int result = 0;
        for (int i = 1,length=nums.length; i <= length; i++) {
            result += i - nums[i-1];

        }
        return result;
    }
}
```



