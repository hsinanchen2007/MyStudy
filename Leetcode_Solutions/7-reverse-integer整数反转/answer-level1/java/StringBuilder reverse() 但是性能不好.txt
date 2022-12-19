### 解题思路
使用 reverse 方法对整个字符串进行翻转

### 代码

```java
class Solution {
    public int reverse(int x) {
        int b = 1;
        StringBuilder sb = new StringBuilder(x+""); 

        if(sb.charAt(0) == '-'){
            sb.deleteCharAt(0);
            b=-1;
        }
        sb = sb.reverse();
        
        long rev = Long.parseLong(sb.toString());
        if(rev > Integer.MAX_VALUE || rev < Integer.MIN_VALUE){
            return 0;
        }

        return (int)rev*b;
    }
}

```