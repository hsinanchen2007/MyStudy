### 解题思路

**执行结果：**
执行用时 :8 ms, 在所有 Java 提交中击败了17.82%的用户
内存消耗 :41.8 MB, 在所有 Java 提交中击败了5.74%的用户

### 代码

```java
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        String result = "";
        for (int i = 0; i < str1.length() && i < str2.length(); i++) {
            String factor = str1.substring(0, i + 1);
            if (isFactor(str1, factor) && isFactor(str2, factor)) {
                result = factor;
            }
        }
        return result;
    }

    /**
     * 判断factor是否为str的因子
     * factor和str长度都大于0
     *
     * @param str
     * @param factor
     * @return
     */
    public boolean isFactor(String str, String factor) {
        int strLength = str.length();
        int factorLength = factor.length();
        int n = strLength / factorLength;
        if (n * factorLength != strLength) {
            return false;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < factorLength; j++) {
                if (factor.charAt(j) != str.charAt(i * factorLength + j)) {
                    return false;
                }
            }
        }
        return true;
    }
}
```