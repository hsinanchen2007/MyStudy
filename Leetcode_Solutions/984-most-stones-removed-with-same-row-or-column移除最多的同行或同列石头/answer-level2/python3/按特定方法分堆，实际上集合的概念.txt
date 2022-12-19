### 解题思路
取出所有的石子，按一定的方式分成若干堆（注意：不是数据结构中所说的堆喔）。如果堆中有n个石子，那么可以移除其中的n-1个。实际上最终的解是石子的数量减去堆的数量。分堆的方式如下：
1，取出一个石子，构造第1个堆（用list表示）。堆的第1个元素是该石子的列数，用set表示，第2个元素是该石子的行数，也用set表示。
2，取出下一个石子，如果石子的列数已在已有的堆中的列数的set中，那么将该石子的行数放到该堆的行数的set中；如果石子的行数已在已有的堆中的行数的set中，那么将该石子的列数放到该堆的列数的set中。这就表示这个石子放入了该堆。（此处计数）
3，如果取出的石子可以放入同时满足放入两个堆的条件，那么应该合并这两个堆，并将石子放入。（此次计数）
4，如果取出的石子不符合条件放入已有的堆中，将其分为新的堆。
5，重复2~4直至所有取完所有石子。

1st time using LeetCood. So exciting! Even through the time-complexity is not so good. Analyze and imporve it.

### 代码

```python3
class Solution:

    def removeStones(self, stones) -> int:

        forest = []
        stone = stones.pop(0)
        forest.append([set([stone[0]]), set([stone[1]])])
        num_moves = 0

        while stones:
            len_forest = len(forest)
            i = 0
            first_match = -1
            second_match = -1
            stone = stones.pop(0)
            while i < len_forest:
                if stone[0] in forest[i][0] or stone[1] in forest[i][1]:
                    forest[i][0].add(stone[0])
                    forest[i][1].add(stone[1])
                    ismerged = True
                    if first_match < 0:
                        first_match = i
                    else:
                        second_match = i
                        break
                i += 1

            if first_match < 0:
                forest.append([set([stone[0]]), set([stone[1]])])
            elif second_match < 0:
                forest[i][0].add(stone[0])
                forest[i][1].add(stone[1])
                num_moves += 1
            else:
                forest[first_match][0].update(forest[second_match][0])
                forest[first_match][1].update(forest[second_match][1])
                del forest[second_match]
                num_moves += 1

        return num_moves
```

后记：
本题实际上是对应《算法导论》中的不相交集合。但在本题的情景下，无需实现其全部操作，甚至无需逐个将元素单独地保持在集合中。在遍历元素时，仅需将其坐在列和行的信息用来更新集合的属性即可。
集合元素对象（石子）用列表`List`表示，含2个元素，每个元素表示一个属性。第1个元素表示石子所在的列的编号，称其为column属性；第2个元素表示石子所在的行的编号，称其为row属性。例如：[2, 3], [1, 5]
如果两个元素的column属性相等或row属性相等，则这两个元素是连通的。如果第3个元素与这两个元素中的一个或两个都连通，那么他们三个属性同一个集合，也即是连通分量。以此类推。集合用列表`List`表示，含2个元素，称第一个属性为columns属性，不加区分地记录了该集合的所有元素所占的列；第二个属性为rows属性，不加区分地记录了该集合的所有元素作占的行。例如：[(0, 1), (2, 3)]