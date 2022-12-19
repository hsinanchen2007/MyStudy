### 解题思路
如：
['a','b','b','c','d']
E1:left 指向 'a',right指向'd';
E2:交换'a'和'd'；
E3:if left == right,则return;否则，跳回E1继续执行；

### 代码

```java
class Solution {
    public void reverseString(char[] s) {
        if (s == null || s.length == 0) return;
        int left = 0, right = s.length - 1;
        while (left < right) {
            char temp = s[left]; s[left ++] = s[right]; s[right --] = temp;
        }
    }
}
```