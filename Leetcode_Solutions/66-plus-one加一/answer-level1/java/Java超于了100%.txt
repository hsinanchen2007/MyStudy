### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/149250f9222d4d6a56f73a76dc7999bfeb8401adaeed09c12cac23aa3e96a1eb-image.png)

### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {
        int len = digits.length - 1;
        // 当个位小于9那么只需要动最后一个数
        if ( digits[len] < 9 ) {
            digits[len] += 1;
            return digits;
        }
    // 全场中需要增加数组长度的，全为9系类，9 99 999 9999
        int j;
        for ( j = 0; j < len+1; j++ ) {
            if ( digits[j] != 9 )
                break;
        }
        if ( j == len+1 ) {
            int[] arr = new int[len + 2];
            arr[0] = 1;
            return arr;
        }
    // 常规不增长原始数组长度
        int val = 1;
        for ( int i = len; i >= 0; i-- ) {
            int p = val;
            val = (digits[i]+val)/10;
            digits[i] = (digits[i]+p)%10;
        }
        return digits;
    }
}
```