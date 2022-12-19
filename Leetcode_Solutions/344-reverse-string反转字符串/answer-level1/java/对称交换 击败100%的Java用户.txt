代码如下：
```
class Solution {
    public void reverseString(char[] s) {
        int maxIndex = s.length-1;
        for (int i=0; i<s.length/2; i++) {
            char tmp = s[i];
            s[i] = s[maxIndex-i];
            s[maxIndex-i] = tmp;
        }
    }
}
```