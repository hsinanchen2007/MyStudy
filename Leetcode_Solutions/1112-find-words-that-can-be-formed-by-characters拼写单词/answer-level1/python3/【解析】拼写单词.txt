### 解题思路
思路是跟着题解走的，自己写的时候出现了问题，在第10个测试点没有通过测试，后面发现是因为else写错了位置，也没有用上collections.Counter这个东西。
思路就是首先建立一个chars的哈希表，记录每个字母所对应的次数，接着对每一个单词，都建立一个该单词每个字母对应次数的哈希表。如果该单词对某个字母的使用次数大于chars中该字母的个数，则循环结束。否则，一直循环到该单词的末尾后，将答案加上该单词的长度。

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        chars_count = collections.Counter(chars)
        ans = 0
        for word in words:
            word_count = collections.Counter(word)
            for i in word:
                if chars_count[i] < word_count[i]:
                    break
            else:
                ans += len(word)
        return ans

```