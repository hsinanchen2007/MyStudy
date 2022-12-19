### 解题思路
先用正则把除字母外数字替换，翻转字符串后忽略大小写比较。
这是第一反应的思路，性能不是最优，但是能最快想到解决。

### 代码

```java
class Solution {
    public boolean isPalindrome(String s) {
        s=s.replaceAll("[^0-9a-zA-Z]+","");

        StringBuffer str = new StringBuffer(s);
        String reverse = str.reverse().toString();
        if(s.equalsIgnoreCase(reverse)) {
            return true;
        }else{
            return false;
        }
    }
}
```