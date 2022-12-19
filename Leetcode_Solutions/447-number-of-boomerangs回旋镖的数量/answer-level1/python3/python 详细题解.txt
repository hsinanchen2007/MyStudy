### 解题思路
根据题意，组成回旋镖要求是 i 和 j 之间的距离和 i 和 k 之间的距离相等，且考虑顺序。
进言之，就是取点 i ，从点对中找出两个与它距离相等的点 j k，视为一个回旋镖。
题解如下：
1）首先，遍历 points ，对于每一个点 i，计算 i 与 points 中其余点的距离。

2）之后，统计各个距离出现的次数，若次数大于2，则说明存在2个以上点到点 i 的距离相等。

3）最后，对于次数大于2的点，由于考虑顺序，因此组成回旋镖的数量为 n*(n-1)

设置 num 记录次数，遍历完成，返回 num
 

### 代码

```python3
class Solution:
    def numberOfBoomerangs(self, points: List[List[int]]) -> int:
        num = 0
        for i in points:
            x = i[0]
            y = i[1]
            distance = []
            for j in points:
                distance.append((j[0]-x)*(j[0]-x)+(j[1]-y)*(j[1]-y))
            dic = {}
            for k in distance:
                if k not in dic:
                    dic.update({k:1})
                else:
                    dic[k] += 1
            for n in dic.values():
                if n > 1:
                    num += n*(n-1)
        
        return num



```