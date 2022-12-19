实现search方法的时候不要直接按照字典树的正经search写，而是按照异或的性质，1找0，0找1（没有ghs，我不是，我没有）
powcai大佬的字典树实现-> [字典树](https://leetcode-cn.com/problems/implement-trie-prefix-tree/solution/pythonjian-dan-shi-xian-by-powcai/)
```python
class Trie:
    def __init__(self):
        self.lookup = {}

    def insert(self, s):
        tree = self.lookup
        for c in s:
            if c not in tree:
                tree[c] = {}
            tree = tree[c]
        tree["#"] = "#"

    def search_grad(self, s):
        tree = self.lookup
        res = ""
        for c in s:
            if c == "1":
                if "0" in tree:
                    tree = tree["0"]
                    res += "0"
                else:
                    tree = tree["1"]
                    res += "1"
            else:
                if "1" in tree:
                    tree = tree["1"]
                    res += "1"
                else:
                    tree = tree["0"]
                    res += "0"
        return res


class Solution:
    def findMaximumXOR(self, nums: List[int]) -> int:
        nums_str = list(map(lambda x: bin(x)[2:].zfill(32), nums))
        tree = Trie()
        for num in nums_str:
            tree.insert(num)
        max_val = float("-inf")
        for num in nums_str:
            max_val = max(max_val, int(num, 2) ^ int(tree.search_grad(num), 2))
        return max_val


```