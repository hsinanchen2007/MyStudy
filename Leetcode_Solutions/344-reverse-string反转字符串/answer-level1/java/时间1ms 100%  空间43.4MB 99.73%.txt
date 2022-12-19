### 解题思路

就当消遣一下吧！

### 代码

```java
class Solution {
    public void reverseString(char[] s) {
        int right  = s.length-1;
        int left = 0 ; 
        while(left < right){
            char ch = s[left];
            s[left++] = s[right];
            s[right--] = ch;
        }
    }
}
```