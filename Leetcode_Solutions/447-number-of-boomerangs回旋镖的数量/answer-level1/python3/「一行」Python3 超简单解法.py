## 思路
+ 首先理解题意。
+ 组成回旋镖的条件是这样。
    1. 先找到一个点。
    2. 如果对这个点来说，存在两个点，它们到回旋镖的距离一样，那么这三个点组成一个回旋镖。
    3. 注意这两个点交换位置也算另一种回旋镖。
+ 所以我们就有了一个这样的思路
+ 遍历所有点
    + 统计它和所有点之间的距离
    + 按照频率为键组成哈希表。值是这个距离出现的次数。（这里用`Counter`类别简化操作） 
    + 如果这个次数大于等于 2，那么计算`P(次数，2)`，即排列组合当中的知识，计算所有这些点中取出两个点总共有多少个组合，位置是相关的。这里用`perm()`函数简化操作。
+ 把所有点的次数加起来即可
## 分步代码
+ 因为把所有的步骤写在一行有点长，不太容易理解，所以这里先分步写下。一行版在后面。
```python
from collections import Counter
from scipy.special import perm

class Solution:
    def numberOfBoomerangs(self, points: List[List[int]]) -> int:
        count = 0
        for point in points:
            
            # distance2 记录对这个点来说的所有的距离
            distance2 = []
            for neighbor in points:
                distance2.append((point[0] - neighbor[0]) ** 2 + (point[1] - neighbor[1]) ** 2)
            
            frequency = Counter(distance2)
            
            for dist,num in frequency.items():
                if num >= 2:
                    count += perm(num,2)
                    
        return int(count)
```
## 一行版
```python
from collections import Counter
from scipy.special import perm
class Solution:
    def numberOfBoomerangs(self, points: List[List[int]]) -> int:
        return int(sum(sum(perm(num,2) for dist,num in Counter([(point[0] - neighbor[0]) ** 2 + (point[1] - neighbor[1]) ** 2 for neighbor in points]).items() if num >= 2) for point in points))
```
+ 确实有点丧心病狂......