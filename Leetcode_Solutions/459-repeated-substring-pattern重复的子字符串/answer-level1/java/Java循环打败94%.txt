### 解题思路

循环遍历整个字符串，然后加长比对字符串的长度，然后跟字符循环比对，优化点有两个

1. 只需要`c<s.length() + 1`
2. 子字符串必须能被字符长度整除

![image.png](https://pic.leetcode-cn.com/9f5d927108d4c29e212850f496463393c79f93d2da3d77fb0a3f62361ab653d2-image.png)

### 代码

```java
class Solution {
    public boolean repeatedSubstringPattern(String s) {
        int c = 1;
        char[] arr = s.toCharArray();
        while (c < arr.length / 2 + 1) {
            if (arr.length % c == 0) {
                int i = 0;
                int j = 1;
                while (i < arr.length) {
                    if (arr[i] != arr[j - 1]) {
                        break;
                    }
                    i++;
                    j = j < c ? j + 1 : 1;
                }
                if (i == arr.length) {
                    return true;
                }
            }
            c += 1;
        }
        return false;
    }
}
```