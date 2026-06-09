### 解题思路
这个题目意思只考虑缺失一个数，将0-n内的数累加求和，然后减去nums内的数，最后的差就是结果。

### 代码

```java
class Solution {
    public int missingNumber(int[] nums) {
        int res = 0;
        for(int i = 0; i <= nums.length; i++){
            res += i;
        }
        for(int i = 0; i < nums.length; i++){
            res -= nums[i];
        }
        return res;
    }
}
```