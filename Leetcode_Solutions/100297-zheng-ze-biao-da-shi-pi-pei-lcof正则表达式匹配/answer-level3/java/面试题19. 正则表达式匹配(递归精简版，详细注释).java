### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isMatch(String s, String p) {
        //如果模板字符串为空，根据文本字符串是否为空返回结果
        if(p.isEmpty())return s.isEmpty();
        //设置个标志，该标志表示：1.如果文本字符串为空直接返回false。2.文本字符串非空，且和模板字符串匹配上返回true，反之false。
        boolean flag=(!s.isEmpty())&&(s.charAt(0)==p.charAt(0)||p.charAt(0)=='.');
        //模板字符串至少两个字符且下一位为*
        if(p.length()>=2&&p.charAt(1)=='*'){
            //两种情况：1.文本字符串不移动，模板字符串将*前面字符置0个，后移两位。2.文本字符串和模板字符串第一个字符如果匹配上，就将文本字符串后移一位，此时模板字符串不需要后移，因为可能需要继续使用*的功能（就是说如果文本字符串前n个字符都相同的情况）
            return isMatch(s,p.substring(2))||(flag&&isMatch(s.substring(1),p));
        }
        else {
            //分两种情况：1.模板字符串只有1个字符，如果文本字符串同样只有一个字符且相同则返回true，不相同返回false；如果文本字符串不止一个字符返回false。2.模板字符串有1个以上字符，但是第二个字符不是*，则根据文本字符串第一个字符和模板字符串第一个字符是否匹配决定是否递归下去。
            return flag&&isMatch(s.substring(1),p.substring(1));
        }
    }
}
```