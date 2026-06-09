### 解题思路
从后面往前遍历，如果是空字符，并且长度为0则为末尾空串，继续循环，如果不为空串则开始length++，直到碰到空串表示已经计算完字符串长度，退出循环。

### 代码

```java
class Solution {
    public int lengthOfLastWord(String s) {
       if (s == null || s.length() == 0) {
            return 0;
        }
        int length = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            Character temp = s.charAt(i);

            if (temp.equals(' ')) {
                if (length != 0) {
                    break;
                }

            }else {
                length++; 
            }


        }
        return length;
    }
}
```