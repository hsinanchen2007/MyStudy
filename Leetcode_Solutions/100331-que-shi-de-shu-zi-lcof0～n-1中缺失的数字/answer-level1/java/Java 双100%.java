### 解题思路
等差数列前n项和，然后递减就好。

### 代码

```java
class Solution {
    public int missingNumber(int[] nums) {
        int n = nums.length;
        int sum = n*(n+1)/2;
        for(int i:nums){
            sum -= i;
        }
        return sum;
    }
}
```