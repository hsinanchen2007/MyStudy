![image.png](https://pic.leetcode-cn.com/687e964166869e6858773acff488777b92d2ad6264faba3e852a576c1c603330-image.png)

```
class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int len = s1.length();
        for (int i = 0; i <= s2.length()-len; i++) {
            String subStr = s2.substring(i, i+len);
            if (isInclude(s1, subStr)) {
                return true;
            }
        }
        return false;
    }

    private static boolean isInclude(String s1, String subStr) {
        char[] char1 = s1.toCharArray();
        char[] char2 = subStr.toCharArray();
        Arrays.sort(char1);
        Arrays.sort(char2);
        for (int i = 0; i < char1.length; i++) {
            if (char1[i] != char2[i]) {
                return false;
            }
        }
        return true;
    }
}
```
