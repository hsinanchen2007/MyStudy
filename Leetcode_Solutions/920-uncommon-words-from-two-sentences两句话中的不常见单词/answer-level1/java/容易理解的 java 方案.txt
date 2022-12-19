### 解题思路

1. 遍历两个句子中的单词，并使用 HashMap 缓存其数量，
2. 过滤出现频率为 1 的单词并组成数组返回

### 代码

```java
class Solution {
    public String[] uncommonFromSentences(String A, String B) {
        String[] arrayA = A.split(" ");
        String[] arrayB = B.split(" ");
        // 缓存单词以及出现频率
        HashMap<String, Integer> memo = new HashMap<String, Integer>();
        // 遍历 A 中的单词并记录其数量
        for (String word : arrayA) memo.put(word, memo.getOrDefault(word, 0) + 1);
        // 遍历 B 中的单词并记录其数量
        for (String word : arrayB) memo.put(word, memo.getOrDefault(word, 0) + 1);
        // 选取数量为 1 的单词组成数组返回
        return memo.entrySet().stream().filter(item -> item.getValue() == 1).map(item -> item.getKey())
                .toArray(String[]::new);
    }
}


```