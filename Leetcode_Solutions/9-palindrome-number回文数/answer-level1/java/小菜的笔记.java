### 解题思路
此处撰写解题思路
将整型转换为字符串，利用字符串的翻转，判断翻转后两个字符串是否相等

### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
        String s = Integer.toString(x);
        if(s.equals(new StringBuffer(s).reverse().toString())) return true;
        else return false;

    }
}
```