### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int reverse(int x) {
        int y = 0;
        int tmp = 0;
        while(x != 0){
            tmp = x%10;
            if(y > Integer.MAX_VALUE/10 || (y == Integer.MAX_VALUE/10 && tmp > Integer.MAX_VALUE%10))
                return 0;
            else if(y < Integer.MIN_VALUE/10 || (y == Integer.MIN_VALUE/10 && tmp < Integer.MIN_VALUE%10))
                return 0;
            y = y*10 + tmp;
            x = x/10;
        }
        return y;
    }
}
```