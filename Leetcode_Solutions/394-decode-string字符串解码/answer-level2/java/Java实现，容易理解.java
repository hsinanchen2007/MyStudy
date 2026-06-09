### 解题思路
先找到最后的“[”，再找到相应的“]”，接着用正则表达式提取出重复的次数k，进行字符串拼接
### 代码

```java
class Solution {
    public String decodeString(String s) {
        int startIndex, endIndex;
        while (s.indexOf("[") != -1) {
            startIndex = s.lastIndexOf("[");
            endIndex = startIndex + s.substring(startIndex).indexOf("]");
            String tmpString = s.substring(startIndex + 1, endIndex);
            String startString = s.substring(0, startIndex);
            // 匹配得到所有的重复数字
            String[] spiltString = startString.split("[a-z]|]|\\[");
            // 提取出重复的次数k
            int times = Integer.valueOf(spiltString[spiltString.length - 1]);
            s = s.substring(0, startIndex - String.valueOf(times).length()) + helper(times, tmpString)
                + s.substring(endIndex + 1);
        }
        return s;
    }

    // 拼接重复的字符串
    private String helper(int times, String tmpString) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < times; i++) {
            sb.append(tmpString);
        }
        return sb.toString();
    }
}
```