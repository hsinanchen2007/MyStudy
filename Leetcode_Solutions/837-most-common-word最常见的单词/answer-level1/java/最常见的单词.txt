#### 简单计数：

我们统计出每个单词出现的次数，忽略所有的标点符号和大小写，答案即为出现次数最多且不在禁用列表中的那个单词。

统计单词的方法有两种。在第一种方法中，我们首先对整个段落按照空格进行分词（split），然后对于分出的每个单词，我们移除标点符号并忽略大小写。在第二种方法中，我们逐字符扫描整个段落，如果遇到一个非字母的符号，那就把之前遇到的字母作为一个单词。

对于每一个单词，我们会放入哈希映射（`Java` 中的 `HashMap` 或者 `Python` 中的 `Counter`）中进行计数。在每次放入单词之后，如果这个单词不在禁用列表中，我们就可以更新一次答案。


```Java [sol1]
class Solution {
    public String mostCommonWord(String paragraph, String[] banned) {
        paragraph += ".";

        Set<String> banset = new HashSet();
        for (String word: banned) banset.add(word);
        Map<String, Integer> count = new HashMap();

        String ans = "";
        int ansfreq = 0;

        StringBuilder word = new StringBuilder();
        for (char c: paragraph.toCharArray()) {
            if (Character.isLetter(c)) {
                word.append(Character.toLowerCase(c));
            } else if (word.length() > 0) {
                String finalword = word.toString();
                if (!banset.contains(finalword)) {
                    count.put(finalword, count.getOrDefault(finalword, 0) + 1);
                    if (count.get(finalword) > ansfreq) {
                        ans = finalword;
                        ansfreq = count.get(finalword);
                    }
                }
                word = new StringBuilder();
            }
        }

        return ans;
    }
}
```

```Python [sol1]
class Solution(object):
    def mostCommonWord(self, paragraph, banned):
        banset = set(banned)
        for c in "!?',;.":
            paragraph = paragraph.replace(c, " ")
        count = collections.Counter(
            word for word in paragraph.lower().split())

        ans, best = '', 0
        for word in count:
            if count[word] > best and word not in banset:
                ans, best = word, count[word]

        return ans
```

**复杂度分析**

- 时间复杂度：$O(P + B)$，其中 $P$ 是段落 `paragraph` 的长度，$B$ 是禁用列表 `banned` 的长度。

- 空间复杂度：$O(P + B)$，用来进行计数以及存储禁用列表 `banned`。