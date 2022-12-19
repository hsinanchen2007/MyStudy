# 解题思路
1.进行排序，使得 a<b<c
2.最大步数取决于最大值c和最小值a之间除了b以外有多少空位：c-a-2
3.当c-a=2时，a，b，c一定是顺序排列的。此时最小步数等于0
当b-a<=2 或者 c-b<=2时，最小步数等于1
其余情况， 最小步数等于2
以上三种情况可以整合为 min(c-a-2, (b-a>2)+1, (c-b>2)+1)


```python3 []
class Solution:
    def numMovesStones(self, a: int, b: int, c: int) -> List[int]:
        a, b, c = min(a,b,c), a+b+c-min(a,c,b)-max(a,b,c), max(a,b,c)
        return [min(c-a-2, (b-a>2)+1, (c-b>2)+1), c-a-2]

