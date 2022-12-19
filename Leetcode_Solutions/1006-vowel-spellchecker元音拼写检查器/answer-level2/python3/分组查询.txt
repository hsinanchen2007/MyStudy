
-   首先将单词进行分组，将单词替换元音字母为`-`，变为小写以后作为键，将所有相同的键都放入一组中
-   然后针对需要查询的单词，先查找组，找不到组则直接将`""`放入结果集
-   在组中查找，如果遇到直接转换大小写即可相等的单词，直接放入结果中，继续查询下一个单词



```python

from collections import defaultdict


class Solution:
    def spellchecker(self, wordlist: List[str], queries: List[str]) -> List[str]:
        def get_consonants(word):
            temp_trans = str.maketrans("aeiouAEIOU", "----------")
            return str.translate(word, temp_trans)

        mapping = defaultdict(list)

        for w in wordlist:
            mapping[get_consonants(w).lower()].append(w)

        ans = []

        for q in queries:
            consonants = get_consonants(q).lower()
            if consonants not in mapping:
                ans.append("")
                continue

            if q in mapping[consonants]:
                ans.append(q)
            else:
                cur_ans = ""
                for check_word in mapping[consonants]:
                    if check_word.lower() == q.lower():
                        cur_ans = check_word
                        break
                    if not cur_ans:
                        cur_ans = check_word
                ans.append(cur_ans)
        return ans
```


