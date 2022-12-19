### 解题思路

BFS模拟，用一个集合`myKeys`记录手上的钥匙，不断的把手头上的箱子打开，获取新的钥匙、箱子和糖果，没能成功打开的箱子保留到下一个箱子队列`initialBoxes`，如果某论尝试后队列没有变化，则输出当前获得的糖果`myCandies`。

### 代码

```python []
class Solution:
    def maxCandies(self, status: List[int], candies: List[int], keys: List[List[int]], containedBoxes: List[List[int]], initialBoxes: List[int]) -> int:
        myKeys, myCandies, pre = set(), 0, []
        while initialBoxes != pre:
            tmp = []
            for i in initialBoxes:
                if i in myKeys:
                    status[i] = 1
                if status[i]:
                    myKeys.update(keys[i])
                    myCandies += candies[i]
                    tmp.extend(containedBoxes[i])
                else:
                    tmp.append(i)
            pre = initialBoxes
            initialBoxes = tmp
        return myCandies
```
```python []
class Solution:
    def maxCandies(self, status: List[int], candies: List[int], keys: List[List[int]], containedBoxes: List[List[int]], initialBoxes: List[int]) -> int:
        myKeys, myCandies, count = set(), 0, 1
        while count:
            tmp, count = [], 0
            for i in initialBoxes:
                if i in myKeys:
                    status[i] = 1
                if status[i]:
                    count += 1
                    myCandies += candies[i]
                    myKeys.update(keys[i])
                    tmp.extend(containedBoxes[i])
                else:
                    tmp.append(i)
            initialBoxes = tmp
        return myCandies
```

![image.png](https://pic.leetcode-cn.com/00c3f447118ce40c7611b341f9aba43232ffada7caa07515cf409f278c1c7cde-image.png)
