# 思路
因为这道题只问能给妹妹最大的**种类**，所以只考虑给妹妹的糖果种类。

---

`candyTypes`：保存糖果的种类
`canduNums`：保存糖果数量
糖果总类数一共就`candyTypes`，所以一门心思想着怎么给的多就好了。

1. 如果**糖果种类的两倍<=总糖果数**(`candyTypes*2 <= canduNums`)，我们可以给到妹妹**最多的糖果种类**，也就是所有糖果种类数，不能再多了(当然妹妹得到的糖果总数可能不止这些)。
2. 如果**糖果种类的两倍>总糖果数** 等价于(`candyTypes>canduNums/2`)，这时我们如果给妹妹`candyTypes`这么多颗不同种类糖果，那么剩下的糖就不够一半给弟弟，所以不行。但由于妹妹可以得到总糖果数量一半的糖果，并且`canduNums/2<candyTypes`，所以我们可以一个种类给一颗，直到`canduNums/2`颗，这也就是妹妹得到的最大种类数，也就是`canduNums/2`

# 举例
#### 第一种情况：candyTypes*2 <= canduNums，最多candyTypes类
```
总共5类，10个糖果，我们可以给妹妹最多5类
5
4
3 3
2 2 2 
1 1 1 
```
#### 第二种情况：candyTypes>canduNums/2
```
总共5类，8个糖果，可以给妹妹最多4类。
5
4
3 3
2 2
1 1
```


---
```python
class Solution:
    def distributeCandies(self, candies: List[int]) -> int:
        candyTypes, canduNums = len(set(candies)), len(candies)
        if candyTypes*2 <= canduNums: return candyTypes        
        return int(canduNums/2)
```
