此题用正则表达式很好求，但要注意的是.这个符号，它的前方或者后方一定一方要有数字，不能两边同时没有
***中有一题同样判断是否为有效数字字符串时，我就没考虑到两方同时为空这种情况，但在牛X网上AC了
leetcode列子更加全面，补上这一点
```
class Solution {
    public boolean isNumber(String s) {
        s=s.trim();
        if(s.contains("[^\\de+-.]")) return false;
        return s.matches("([+-]?[0-9]+\\.?|[+-]?\\.?[0-9]+|[+-]?[0-9]+\\.[0-9]+)([Ee][+-]?[0-9]+)?");
    }
}
```
