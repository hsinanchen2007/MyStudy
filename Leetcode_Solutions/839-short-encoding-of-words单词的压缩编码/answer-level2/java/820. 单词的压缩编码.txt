### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public static int minimumLengthEncoding(String[] words) {
    // 先按字符串长度进行排序
        Arrays.sort(words, (w1, w2) -> w2.length() - w1.length());

        // 然后在进行匹配的计算
        String sb = new String();
        for (String word : words) {
            if (!sb.contains(word + "#")) {
                sb = sb.concat(word + "#");
            }
        }
        return sb.length();
    }}
```