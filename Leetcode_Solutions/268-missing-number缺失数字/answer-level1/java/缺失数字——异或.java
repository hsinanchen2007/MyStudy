使用位运算。遍历数组元素，将0异或当前元素再异或下标，最后异或数组长度n即可。
```java
    public int missingNumber(int[] nums) {
        int ans = 0;
        for (int i = 0; i < nums.length; i++) {
            ans ^= nums[i] ^ i;
        }
        return ans ^ nums.length;
    }
```
![image.png](https://pic.leetcode-cn.com/1785c64f7206d6ab2d9aa7becd7b16d92395cddc978eb173ad0d44f7018ed897-image.png)
