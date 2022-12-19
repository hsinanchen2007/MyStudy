####  方法：比较计数
**算法：**
- 我们计算 `word` 和 `licenseplate` 中的字母数，转换为小写并忽略非字母字符。如果单词中每个字母的计数大于或等于 `licenseplate` 中的字母数，则该单词是 `licensePlate` 的完整词。
- 我们需要选择最短的完整词且最先出现的单词。

```Python [ ]
class Solution(object):
    def shortestCompletingWord(self, licensePlate, words):
        def count(itera):
            ans = [0] * 26
            for letter in itera:
                ans[ord(letter) - ord('a')] += 1
            return ans

        def dominates(c1, c2):
            return all(x1 >= x2 for x1, x2 in zip(c1, c2))

        ans = None
        target = count(c.lower() for c in licensePlate if c.isalpha())
        for word in words:
            if ((len(word) < len(ans) or ans is None) and
                    dominates(count(word.lower()), target)):
                ans = word

        return ans
```

```Java [ ]
class Solution {
    public String shortestCompletingWord(String licensePlate, String[] words) {
        int[] target = count(licensePlate);
        String ans = "";
        for (String word: words)
            if ((word.length() < ans.length() || ans.length() == 0) &&
                    dominates(count(word.toLowerCase()), target))
                ans = word;
        return ans;
    }

    public boolean dominates(int[] count1, int[] count2) {
        for (int i = 0; i < 26; ++i)
            if (count1[i] < count2[i])
                return false;
        return true;
    }

    public int[] count(String word) {
        int[] ans = new int[26];
        for (char letter: word.toCharArray()){
            int index = Character.toLowerCase(letter) - 'a';
            if (0 <= index && index < 26)
                ans[index]++;
        }
        return ans;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N)$。$N$ 指的是 `words` 的元素个数，比较 `licensePlate` 和 `words[i]` 的字母计数需要 $O(1)$ 的时间
* 空间复杂度：$O(1)$，使用常数的空间。