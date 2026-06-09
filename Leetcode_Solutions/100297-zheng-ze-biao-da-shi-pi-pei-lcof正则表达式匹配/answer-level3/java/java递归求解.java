采用递归去匹配
步骤：
1. 退出递归的条件：p长度为0（即p匹配完），返回s长度是否为0（s是否匹配完）
2. 按p的下一个符号是不是*分情况
    2.1. 如果p的下一个是*，按是否跳过当前*分情况
			2.1.1. 跳过当前*，返回查询当前s和跳过*后的p
			2.1.2. 不跳过当前*，返回匹配当前字符&&匹配当前字符进1后的s和p（因为有*）
	2.2. 如果p的下一个不是*，则返回匹配当前字符&&匹配当前字符进1后的s和进1后的p（因为无*）
```
class Solution {
    public boolean isMatch(String s, String p) {
        if(s==null||p==null){
            return false;
        }
        return match(s,p);
    }
    private boolean match(String s,String p){
      //如果p长度为0，则返回s是否匹配完
        if (p.length() == 0) {
            return s.length() == 0;
        }
        //如果p当前匹配位置有下一个位置，且下一个是'*'
        if (p.length() > 1 && p.charAt(1) == '*') {
            //按是否跳过当前*分情况
            //一种情况，跳过当前*，匹配s和跳过*后的p
            //第二种情况，不跳过当前*，进行匹配，返回当前s的第一个和p的第一个匹配，并且s之后的也和p匹配
            return match(s, p.substring(2)) 
                    || (s.length() > 0 && (s.charAt(0) == p.charAt(0) || p.charAt(0) == '.')) && match(s.substring(1), p);
        } else {
            //如果当前位置下一个不为*，那么返回当前s的第一个和p的第一个匹配，并且s之后的也和p之后（因为没有*）匹配
            return s.length() > 0 && (s.charAt(0) == p.charAt(0) || p.charAt(0) == '.') && isMatch(s.substring(1), p.substring(1));
        }
    }
}
```