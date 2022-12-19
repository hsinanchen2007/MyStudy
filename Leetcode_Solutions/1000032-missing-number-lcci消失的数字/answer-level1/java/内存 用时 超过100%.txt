### 解题思路
比较简单的一个方法


### 代码

```java
class Solution {
    public int missingNumber(int[] nums) {
        int sum = 0;
        for (int num :nums) {
            sum +=num;
        }
        int len = nums.length;
        int sum2 = (1+len)/2*len;
        if (len%2 == 0) {
            sum2 =  sum2 + len/2 ;
        }
        return sum2 - sum;
    }
}
```