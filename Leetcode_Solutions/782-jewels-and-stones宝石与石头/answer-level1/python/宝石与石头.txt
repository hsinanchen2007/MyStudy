### 解题思路
由于J中的字母不重复，故可以遍历J的字符，然后统计每个字符在S中的次数，最后累加求和所有次数即可。

### 代码

```python3
class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        i = 0
        count = 0
        l =len(J)
        while i < l:
            count +=S.count(J[i])
            i +=1
        return count
优化后的代码
class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        return sum([S.count(i) for i in J])
提交过后发现，代码虽然简洁了，但是效率却降低了。
```