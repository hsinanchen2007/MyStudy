### 解题思路
比较简单，基本上是将第i位字符串和第n - i - 1位进行交换，截止条件是遍历到中间的位置结束

### 代码

```java
class Solution {
    public void reverseString(char[] s) {
        if(s != null){
            int len = s.length;
            for (int i = 0;i < len ;i++){
                if (len > 2 * i){
                    char tmp = s[i];
                    s[i] = s[len - i - 1];
                    s[len - i - 1] = tmp;
                }
            }
        }
    }
}
```