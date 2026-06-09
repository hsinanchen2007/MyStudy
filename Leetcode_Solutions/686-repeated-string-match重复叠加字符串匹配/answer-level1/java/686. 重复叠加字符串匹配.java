/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/30
 * 
 * 解题思路: 使用lastIndexOf 和 indexOf 来进行 字符串匹配 测试数据的问题 lastIndexOf会快很多 (可尝试KMP)
 * 
 */
```
public int repeatedStringMatch(String A, String B) {
    int i = 1;
    StringBuilder s = new StringBuilder(A);
    int blength = B.length();
    while(s.length() < blength){
        s.append(A);
        i++;
    }
    return s.indexOf(B) == -1?((s.append(A)).indexOf(B)==-1?-1:i+1):i;
}

class Solution {
    public int repeatedStringMatch(String A, String B) {
        int i = 1;
        StringBuilder s = new StringBuilder(A);
        int blength = B.length();
        while(s.length() < blength){
            s.append(A);
            i++;
        }
        return s.lastIndexOf(B) == -1?((s.append(A)).lastIndexOf(B)==-1?-1:i+1):i;
    }
}
```