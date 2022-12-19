## 思路
+ 首先理解题意
+ 给你一个数组
    + 下标表示第 i 个筹码
    + 值表示这个筹码的所在位置
+ 你的任务是，把所有筹码挪到相同的位置，计算最小移动的步数
+ 移动偶数步不消耗步数，移动奇数步，消耗一步
+ 所以为了最小化步数，我们先尽量使步数为0,也就是先偶数地挪动。
+ 我们可以把在偶数位的都挪到一起，把在奇数位的都挪到一起。
+ 这样，只要比较哪个多，把剩下的都挪过去即可。
+ 所以这道题目实际上就是让你计算一个数列中奇数和偶数的数量的最小值。

## 代码
```python
class Solution:
    def minCostToMoveChips(self, chips: List[int]) -> int:
        return min(sum(1 for i in chips if i%2==1),sum(1 for i in chips if i%2==0))
```
为了优化效率，建议写成这样
```python
class Solution:
    def minCostToMoveChips(self, chips: List[int]) -> int:
        odd = sum(1 for i in chips if i % 2 == 1)
        return min(odd,len(chips) - odd)
```