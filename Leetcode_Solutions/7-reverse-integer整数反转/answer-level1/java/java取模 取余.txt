### 解题思路
两个点：
1. 使用一个rev (long型) 来存储最终翻转的数字，如果最终结果超出Integer的取值范围，说明有益处，则返回0.
2. 重复对x取余数，余数 + rev*10, 使得数字翻转
   ```JAVA
    rev = rev*10 + x % 10;
    x = x / 10;
    ```

### 代码

```java
class Solution {
    public int reverse(int x) {
        long rev = 0; // store a long value
        while(x != 0){
            rev = rev*10 + x % 10;
            x = x / 10; 
        }
        // if the long value > Integer.MAX_VALUE or < Integer.MIN_VALUE, means it overflows, then return 0
        if(rev > Integer.MAX_VALUE || rev < Integer.MIN_VALUE){
                return 0;
        }
        return (int)rev;
    }
}

```