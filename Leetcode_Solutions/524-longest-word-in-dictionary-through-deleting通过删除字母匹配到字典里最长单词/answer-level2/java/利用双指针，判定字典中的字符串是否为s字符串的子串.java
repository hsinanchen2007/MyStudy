### 解题思路
利用双指针，判定字典中的字符串是否为s字符串中的子串，用一个变量用来暂存长度最长的字典序。

### 代码

```java
class Solution {
    public String findLongestWord(String s, List<String> d) {
        String longStr = "";
        int len;
        int dicLen;
        for (String dic : d) {
            len = longStr.length();
            dicLen = dic.length();
            if (len > dicLen || (len == dicLen && longStr.compareTo(dic) < 0)) {
                continue;
            }

            if (isSubStr(s, dic)) {
                longStr = dic;
            }
        }

        return longStr;
    }

    private boolean isSubStr(String s, String dic) {
        int si = 0;
        int di = 0;
        while (si < s.length() && di < dic.length()) {
            if (s.charAt(si) == dic.charAt(di)) {
                ++di;
            }
            ++si;
        }
        return di == dic.length();
    }
}
```