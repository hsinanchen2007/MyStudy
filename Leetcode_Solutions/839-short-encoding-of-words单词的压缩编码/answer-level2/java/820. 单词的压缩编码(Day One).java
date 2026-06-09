### 解题思路
单词反转后排序，这样属于后缀的单词就排在前面，计算长度的时候排除掉属于前缀的单词即可。

### 代码

```java
class Solution {
    public int minimumLengthEncoding(String[] words) {
        int N = words.length;
        // 反转单词
        String[] reverseWords = new String[N];
        for (int i = 0; i < N; i++) {
            String word = words[i];
            String rword = new StringBuilder(word).reverse().toString();
            reverseWords[i] = rword;
        }
        // 字典序排序    
        Arrays.sort(reverseWords);

        int res = 0;
        for (int i = 0; i < N; i++) {
            if (i + 1 < N && reverseWords[i + 1].startsWith(reverseWords[i])) {
                // 当前单词是下一个单词的前缀，丢弃
            } else {
                res += reverseWords[i].length() + 1; // 单词加上一个 '#' 的长度
            }
        }
        return res;
    }
}
```