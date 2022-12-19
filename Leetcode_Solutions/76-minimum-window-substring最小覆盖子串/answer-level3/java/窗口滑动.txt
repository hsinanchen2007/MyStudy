### 解题思路

两个数组，一个数组是t需要的字符，另一个是窗口内的字符



### 代码

```java
class Solution {
public static String minWindow(String s, String t) {
        if (s == null || s=="" || t == null || t == "" || s.length() < t.length()) {
            return "";
        }
        int[] tNChar = new int[128];
        for (int i=0;i<t.length();i++) {
            tNChar[t.charAt(i)]++;
        }

        int[] wNChar = new int[128];

        int left = 0;
        int right = 0;
        int count = 0;
        int minLength = s.length()+1;
        String res = "";

        while (right < s.length()){
            char schar = s.charAt(right);
            wNChar[schar] ++;
            // 满足t 需要的字符，count++，多了 不 加
            if (tNChar[schar] > 0 && tNChar[schar] >= wNChar[schar]) {
                count++; // 这个字符是 t 需要的，count++
            }
            // 剔除 左边 第一个字符，并把这个字符之前的无关字符去掉，其实就是缩小窗口，
            // 去掉左边第一个字符重复的，和重复字符之前的与t 无关字符
            while (count == t.length()) {
                
                if (right - left +1 < minLength) {
                    res = s.substring(left,right+1);
                    minLength = right - left +1;
                }
                char lchar = s.charAt(left);
                if(tNChar[lchar] > 0 && tNChar[lchar] >= wNChar[lchar]) {
                    count--;
                }
                wNChar[lchar]--;
                left++;
            }
            right++;
        }
        return res;
    }
}
```