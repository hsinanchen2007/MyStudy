### 解题思路
利用stringBuilder翻转

### 代码

```java
class Solution {
    public String reverseStr(String s, int k) {
        if (s.isEmpty() || s.length() == 1) {
            return s;
        }

        int length = s.length();
        int div = length / (2 * k);
        int mod = length % (2 * k);

        StringBuilder stringBuilder = new StringBuilder();

        if (div == 0) {
            String result = processLittle(s, k);
            return result;
        }

        for (int i = 0; i < div; i++) {
            String currentString = s.substring(i * 2 * k, 2 * (i + 1) * k);
            String frontSub = currentString.substring(0, k);
            String backSub = currentString.substring(k, 2 * k);
            stringBuilder.append(reverseStr(frontSub)).append(backSub);
        }

        if (mod != 0) {
            String lastSub = s.substring(div * 2 * k);
            stringBuilder.append(processLittle(lastSub, k));
        }
        return stringBuilder.toString();
    }

    private String processLittle(String s, int k) {
        StringBuilder stringBuilder = new StringBuilder();
        if (s.length() <= k) {
            stringBuilder.append(reverseStr(s));
        } else {
            stringBuilder.append(reverseStr(s.substring(0, k))).append(s.substring(k));
        }
        return stringBuilder.toString();
    }

    /**
     * 翻转字符串
     *
     * @param str
     * @return
     */
    private String reverseStr(String str) {
        // 翻转字符串  
        StringBuilder stringBuilderTmp = new StringBuilder();
        for (int i = str.length() - 1; i >= 0; i--) {
            stringBuilderTmp.append(str.charAt(i));
        }
        return stringBuilderTmp.toString();
    }
}
```