拓扑排序并不难，只要之前做过一次类似的题。
其实前面获得字典序的过程，还是稍微有点麻烦的，同样做过类似题最好。
按照列遍历单词获得字典序，存入dict，key是前序，value是后序。
只需要遍历删除掉不在 value 里的 key 就可以了。

```python
import collections
import itertools
# from pprint import pprint


class Solution:
    def alienOrder(self, words: List[str]) -> str:
        alphabet, not_compared = collections.defaultdict(list), [True] * (len(words) - 1)
        for column in itertools.zip_longest(*words):
            for i in range(len(words) - 1):
                if column[i] is None or column[i + 1] is None:
                    not_compared[i] = False
                if column[i] is not None and (column[i + 1] is None or not not_compared[i]):
                    alphabet[column[i]]
                if not_compared[i] and column[i] != column[i + 1]:
                    alphabet[column[i]].append(column[i + 1])
                    not_compared[i] = False
            if column[-1] is not None:
                alphabet[column[-1]]
        # pprint(alphabet)
        no_parent, res = alphabet.keys() - set(itertools.chain.from_iterable(alphabet.values())), ''
        while no_parent:
            for k in no_parent:
                res += k
                alphabet.pop(k)
            no_parent = alphabet.keys() - set(itertools.chain.from_iterable(alphabet.values()))
        # print(alphabet)
        if alphabet:
            return ''
        return res
```