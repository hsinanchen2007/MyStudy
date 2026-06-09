利用双指针，分别记录字符串s、t的索引位置：(i, j)
- 索引j从0开始，不断递增，直至j索引处的字符等于字符串s的i处字符；
- 返回i == s.length();

```java []
class Solution {
    public static boolean isSubsequence(String s, String t) {
        int i = 0, j = 0;
        while(i < s.length() && j < t.length()){
            if(s.charAt(i) == t.charAt(j)){
                i++;                
            }
            j++;
        }
        return i == s.length();
    }
}
```


