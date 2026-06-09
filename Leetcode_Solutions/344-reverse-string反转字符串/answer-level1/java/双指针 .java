### 解题思路
双指针

### 代码

```java
class Solution {
    public void reverseString(char[] s) {
        if (s.length < 2) return;

         for (int i =0;i<s.length;i++){
            int j = s.length - 1 - i;
            if (i>=j) break;
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
        }
    }
}
```