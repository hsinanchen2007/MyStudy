### 解题思路
关键切入点在这句话：相邻的孩子中，评分高的孩子必须获得更多的糖果。


### 法一：
暴力解法，正向匹配，时间复杂度最坏的情况下O(n²),空间复杂度O(n)，这种方法会超时，最坏的是在有序的情况下产生。

### 法二：
正方向+反方向各匹配一次。首先建立两个列表，用于存放正反遍历的糖树。因为初始每个小朋友都有1个糖果，所以正方向向左遍历，只需要考虑右边的小朋友分数是否高于左边的小朋友，如果是则`reward[i] = reward[i-1] + 1`。正向遍历后，我们开始考虑反向遍历，反向遍历只需考虑右边的小朋友分数是否高于左边的小朋友。如果是则`reward[i] = reward[i+1] + 1`。最终取两个列表中对应小朋友获取糖果的最大值求和。

`时间复杂度为O(n),空间复杂度为O(n),但是需要建立两个链表`


**注：关于为什么取最大值，因为从左到右，是单调不减的，而从右到左，也是单调不减的，所以局部最优解也就成为了全局最优解**

### 法三:
分析法一和法二，发现调换顺序遍历可以有效减少时间复杂度。但是我们是否可以再优化法二的时间复杂度呢？根据法一的正向遍历，我们可以发现单向遍历时，要使一个分高小朋友的有效的比相邻小朋友获得更多的糖果，要满足的条件是:
`ratings[i] > ratings[i-1] and reward[i]<=reward[i-1]`或者`ratings[i] > ratings[i+1] and reward[i] <= reward[i-1]`
如果只采用一个数组的时候，可以从左到右遍历不变（因为此时所有小朋友都只有一个糖），但当从右到左遍历时，就需要贪心地满足获得糖果的所有条件。进而局部最优解  --->  全局最优解！

### 代码

```python
class Solution:
    def candy(self, ratings: List[int]) -> int:
        
        m = len(ratings)
        if m == 0:
            return 0
        reward = [1]*m
        flag= True # 状态
        while flag:
            flag = False
            for i in range(0,m):
                if i>0 and ratings[i] > ratings[i-1] and reward[i] <= reward[i-1]:
                    # 此时需要平衡糖,需要用与它比较的小孩的糖数+1
                    reward[i] = reward[i-1] + 1
                    print(reward[i])
                    flag = True
                if i != m-1 and ratings[i] > ratings[i+1] and reward[i] <= reward[i+1]:
                    reward[i] = reward[i+1] + 1
                    flag = True
                # 两者都不成立的条件为相邻的两个小孩分数一样
        return sum(reward)
```


```python    
class Solution:
    def candy(self, ratings: List[int]) -> int:
        # 同时满足左规则和右规则
        m = len(ratings)
        list_one = [1 for _ in range(m)]
        list_two = list(list_one)
        for i in range(1,m):
            if ratings[i-1] < ratings[i]:
                list_one[i] = list_one[i-1] + 1
        for j in range(m-2,-1,-1):
            if ratings[j] > ratings[j+1]:
                list_two[j] = list_two[j+1] + 1
        sum = 0
        for one, two in zip(list_one,list_two):
            sum += max(one,two)
        return sum
```


```python
class Solution:
    def candy(self, ratings: List[int]) -> int:
        '''优化法2，使用1个数组'''
        m = len(ratings)
        list_ = [1 for _ in range(m)]
        for i in range(1,m):
            if ratings[i-1] < ratings[i]:
                list_[i] = list_[i-1] + 1
        for i in range(m-2,-1,-1):
            if ratings[i] > ratings[i+1] and list_[i] <= list_[i+1]:
                list_[i] = list_[i+1] + 1
        return sum(list_)




```