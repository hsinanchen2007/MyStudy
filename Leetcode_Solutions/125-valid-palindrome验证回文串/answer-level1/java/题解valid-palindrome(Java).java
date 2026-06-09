### 解题思路
1、只保留数字和字母（这里无需大小写转换）；
2、将处理后的字符串反转与原字符串比较是否一样（此处用equalsIgnoreCase函数忽略大小写字母差异）。

### 代码

```java
class Solution {
    public boolean isPalindrome(String s) {
        // 高层次主干逻辑，写好需要用的函数和实现逻辑
        // 1.filter out number & char; 2.reverse and compare

        String filteredS = _filterNonNumberAndChar(s);

        String reversedS = _reversedString(filteredS);
        //忽略大小写作比较
        return reversedS.equalsIgnoreCase(filteredS);
    }

    //枝叶1，实现函数细节
    private String _reversedString(String s) {
        return new StringBuilder(s).reverse().toString();
    }

    //枝叶2
    private String _filterNonNumberAndChar(String s) {
        //除字母数字外其他字符替换为""，即删除，正则表达式
        //https://www.runoob.com/java/java-string-replaceall.html
        return s.replaceAll("[^A-Za-z0-9]", "");
    }
}
```