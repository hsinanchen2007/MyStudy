### 解题思路
基本上就是暴力解法，但一定记得不符合条件时就跳出循环，否则就会出现超时现象。

### 代码

```java
class Solution {
    public boolean queryString(String S, int N) {
        boolean flag = true;
        for(int i = Math.max(1,N/2); i < N + 1; i ++) {
            String s = Integer.toBinaryString(i);
                if(!S.contains(s)) {
                    flag = false;
                    break;
                }
        }
        return flag;
    }
}
```