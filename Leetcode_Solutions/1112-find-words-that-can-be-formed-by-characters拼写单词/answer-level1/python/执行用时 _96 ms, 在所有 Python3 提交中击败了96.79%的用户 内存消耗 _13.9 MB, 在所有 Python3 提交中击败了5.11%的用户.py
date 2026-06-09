### 解题思路
执行用时 :96 ms, 在所有 Python3 提交中击败了96.79%的用户
内存消耗 :13.9 MB, 在所有 Python3 提交中击败了5.11%的用户
判断单词当前该字母个数是否小于等于chars中该字母的个数 若每个都成立则可以组词

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        c=0
        for p in words:
            for q in p:
                if p.count(q)>chars.count(q):
                    break
            else:
                c=c+len(p)
        return c




```