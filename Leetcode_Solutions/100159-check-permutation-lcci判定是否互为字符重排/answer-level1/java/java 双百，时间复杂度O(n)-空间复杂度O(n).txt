问题分析：
只要两个字符串包含相同的字符，且字符个数相等，那么返回true。
解题思路：
1.分别统计两个字符串中元素的个数。
2.比较相同索引下，元素的个数是否相等，不相等的话，肯定不能够重排，返回false。

```
class Solution {
    public boolean CheckPermutation(String s1, String s2) {
        if (s1.length() != s2.length()) return false;
        int len = s1.length();
        int[] sCnt = new int[100];
        int[] ssCnt = new int[100];
        for (int i = 0; i < len; i++) {
            sCnt[s1.charAt(i) - 'a']++;
            ssCnt[s2.charAt(i) - 'a']++; 
        }
        for (int i = 0; i < sCnt.length; i++){
           if(sCnt[i] != ssCnt[i]) {
               return false;
           } 
        }
        return true;
    }
}
```
