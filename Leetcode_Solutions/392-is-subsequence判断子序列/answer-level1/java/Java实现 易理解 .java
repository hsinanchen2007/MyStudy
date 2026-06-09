定义一个index变量表示找到s字符串变量中第index个字符，i变量是表示从t中的哪一个索引开始找
```
class Solution {
    public boolean isSubsequence(String s, String t) {
        int index = 0,i = 0;
        while(index < s.length() && t.indexOf(s.charAt(index),i) >= i){
            i = t.indexOf(s.charAt(index),i) + 1;
            index++;
        }
        
        
        return index == s.length();
    }
}
```
