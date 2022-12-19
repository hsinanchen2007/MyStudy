### 解题思路
方法一：遍历
一次遍历，递减candies，直到分完为止
时空复杂度O(max(根号c,n)) O(1)

### 代码

```python3
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        disCandies=[0]*num_people
        i=1
        while candies>0:
            if candies<i:
                disCandies[i%num_people-1]+=candies
                candies=0
            else:
                disCandies[i%num_people-1]+=i
                candies-=i
                i+=1
        return disCandies
```

### 解题思路
方法二：数学
解一元二次方程，得到满额分发的次数

### 代码
```python3
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        n = num_people
        p = int((2 * candies + 0.25)**0.5 - 0.5) 
        remaining = int(candies - (p + 1) * p * 0.5)
        rows, cols = p // n, p % n
        d = [0] * n
        for i in range(n):
            d[i] = (i + 1) * rows + int(rows * (rows - 1) * 0.5) * n
            if i < cols:
                d[i] += i + 1 + rows * n      
        d[cols] += remaining
        return d
```