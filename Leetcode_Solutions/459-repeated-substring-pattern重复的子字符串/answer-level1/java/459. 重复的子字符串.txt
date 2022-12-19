/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/17
 * 
 * 解题思路: 技巧题目 连接两个字符串 去头去尾还包含原来字符串则为重复字符串
*  例如：
* 
*  3*abc
*          
*  3*abc+3*abc => 去头去尾 => ..2*abc+2*abc... => 依旧包含3*abc
*          
*  如果是1*abc 
*          
*  1*abc+1*abc => 去头去尾 => ..0*abc+0*abc... => 不包含abc
 */
```
public boolean repeatedSubstringPattern(String s) {
    String s2 = s + s;
    s2 = s2.substring(1,s2.length() - 1);
    return s2.contains(s);
}
```