![image.png](https://pic.leetcode-cn.com/0b6363312be7ab299b62b33b7dde471d12ffa4c08fae73182e71ba6701774883-image.png)

### 解题思路
    1、转换为char数组
    2、直接用双指针
    3、找出左右的字母，然后替换，再下一个循环

### 代码

```java
class Solution {
    public String reverseOnlyLetters(String s) {
        char[] chars = s.toCharArray();
        int i = 0;
        int j = chars.length - 1;
        while (i < j) {
            while (i < j && (chars[i] < 'A' || (chars[i] > 'Z' && chars[i] < 'a') || chars[i] > 'z')) i++;
            while (i < j && (chars[j] < 'A' || (chars[j] > 'Z' && chars[j] < 'a') || chars[j] > 'z')) j--;
            if(i < j) {
                chars[i] ^= chars[j];
                chars[j] ^= chars[i];
                chars[i++] ^= chars[j--];
            }
        }
        return String.valueOf(chars);
    }
}
 
```