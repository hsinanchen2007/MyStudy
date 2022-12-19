/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/22
 *
 * 解题思路: 看懂题意 查找不在对方子串集合的最长字串 相同的字符串则返回-1  不同的字符串则返回较长的字符串
 *
 */
```
public int findLUSlength(String a, String b) {
    if(a.equals(b)) return -1;
    else return a.length() > b.length() ? a.length():b.length();
}
```