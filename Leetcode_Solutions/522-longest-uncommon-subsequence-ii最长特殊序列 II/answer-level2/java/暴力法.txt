### 解题思路

理解题意，如果a不是b的子串，那a本身就是一个特殊序列，所以问题可以简化成，只要求出不是其他字符串的子序列的子字符串就可以了。

![image.png](https://pic.leetcode-cn.com/310531a24ee7d761f73388e6c93811322c4b84bb77e55bd7ed2d21862c7219a1-image.png)

### 代码

```java
class Solution {
    public int findLUSlength(String[] strs) {
        int result = -1;
        for (int i = 0; i < strs.length; i++) {
            boolean isSubstr = false;
            if (strs[i].length() <= result) continue;
            for (int j = 0; j < strs.length; j++) {
                if (i == j) continue;
                if (isSubstr(strs[j], strs[i])) {
                    isSubstr = true;
                    break;
                }
            }
            if (!isSubstr) {
                result = Math.max(result, strs[i].length());
            }
        }

        return result;
    }

    private boolean isSubstr(String str1, String str2) {
        int i = 0;
        int j = 0;
        while (i < str1.length() && j < str2.length()) {
            if (str2.charAt(j) == str1.charAt(i)) {
                j++;
            }
            i++;
        }
        return j == str2.length();
    }
}
```