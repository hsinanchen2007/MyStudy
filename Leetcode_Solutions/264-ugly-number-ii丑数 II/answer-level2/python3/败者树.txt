### 解题思路
败者树就是用叶节点表示选手队列，内部节点表示比赛并保存输掉的选手，由于每次更新的新选手只需要和其父亲结点比较，因此更新效率很快。这里的代码编写关键是，选手队列需要有序插入，也就是每次选出最优之后需要将与其有关的候补选手（这里也就是可以由当前最小丑数推出的三个丑数）添加到选手队列里面。因此我们可以将选手队列维持在三个：与2相关，与3相关和与5相关队列，每次得出当前最小丑数时，分别将其推出的三个丑数按序插入，这样可以保持选手队列的有序。但是这里有一个问题就是这样重复数字很多，虽然每次得出当前最小丑数的比较数不多，但是当n很大时，重复数字异常庞大。所以需要对丑数队列进行简单去重，简单来说就是，由与2相关的队列推出的当前最小丑数，更新候补丑数时，乘2、乘3和乘5全部插入；而由与3相关的队列和与5相关队列推出的当前最小丑数，更新候补丑数时，仅更新部分候补，即乘3，乘5或乘5需要插入相关队列。

### 代码

```python3
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        class Solution:
    def nthUglyNumber(self, n: int) -> int:
        if n == 1:
            return 1
        if n == 2:
            return 2
        n -= 2
        losertree = [3, 4, [4], [3,6], [5,10]]
        winner = 2
        pos = 2
        while n > 0:
            while pos != 0:
                pos = (pos - 1) // 2
                if losertree[winner][0] > losertree[losertree[pos]][0]:
                    losertree[pos], winner = winner, losertree[pos]

            top = losertree[winner].pop(0)
            if winner==2:
                losertree[2].append(top * 2)
                losertree[3].append(top * 3)
                losertree[4].append(top * 5)
            elif winner==3:
                losertree[3].append(top * 3)
                losertree[4].append(top * 5)
            else:
                losertree[4].append(top * 5)
            pos = winner
            n -= 1

        return top
```