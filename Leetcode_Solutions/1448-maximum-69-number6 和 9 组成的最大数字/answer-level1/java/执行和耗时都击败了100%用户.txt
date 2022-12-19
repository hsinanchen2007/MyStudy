### 解题思路
转化为字符串，遇到第一个6直接替换

### 代码

```java
class Solution {
    public int maximum69Number (int num) {
        String strnum = String.valueOf(num);
        char[] charnum = strnum.toCharArray();
        for (int i = 0; i < charnum.length; ++i) {
            if (charnum[i] == '6'){
                charnum[i] = '9';
                break;
            }
        }
        return Integer.parseInt(String.valueOf(charnum));
    }
}
```