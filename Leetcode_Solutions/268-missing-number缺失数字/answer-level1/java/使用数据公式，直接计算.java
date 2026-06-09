
### 代码

```java
class Solution {
    public int missingNumber(int[] nums) {
        int n = nums.length;
        int sumN = n * (n + 1) /2;
        int sumNums = 0;
        for(int i:nums){
            sumNums += i;
        }
        return sumN - sumNums;
    }
}
```