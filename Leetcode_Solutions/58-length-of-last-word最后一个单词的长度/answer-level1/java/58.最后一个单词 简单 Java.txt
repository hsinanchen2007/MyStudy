### 解题思路
本题关键在于对空格的处理，去除尾空格，并设尾指针为end，设置头指针为start，一直向前，直到遇到空格，并返回end - start，细节在于边界条件的控制。

### 代码

```java
class Solution {
    public int lengthOfLastWord(String s) {
        int length = s.length();
        int end = length - 1;
        while(end >= 0 && s.charAt(end) == ' ') end--;
        if(end < 0)
            return 0;
        int start = end;
        while(start >= 0 && s.charAt(start) != ' ') start--;
        return end - start;
    }
}
```