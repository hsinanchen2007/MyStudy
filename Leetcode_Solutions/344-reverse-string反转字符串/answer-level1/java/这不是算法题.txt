### 解题思路
这个题目贼简单 不像算法

### 代码

```java
class Solution {
    public void reverseString(char[] s) {
        //双指针
        if (s.length < 2) {
            return;
        }

        int i = 0;
        int j = s.length - 1;

        while (i < j) {
            char temp = s[i];
            s[i]      = s[j];
            s[j]      = temp;
            i++;
            j--;
        }
    }
}
```