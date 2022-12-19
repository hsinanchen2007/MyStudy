### 解题思路
又是熟悉的首尾互换，不纠结，双指针搞定

### 代码

```java
class Solution {
    public void reverseString(char[] s) {
        int begin = 0;
        int end = s.length - 1;
        while (begin < end) {
            // 相等，不用交换
            if (s[begin] == s[end]) {
                begin++;
                end--;
                continue;
            }
            // 交换，借助中间变量
            char tmp = s[begin];
            s[begin] = s[end];
            s[end] = tmp;
            begin++;
            end--;
        }
    }
}
```