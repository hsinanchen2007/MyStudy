### 解题思路
此处撰写解题思路
分情况讨论
1.如果开始的时候所有的苹果重量小于等于5000，那么苹果的总个数就符合题意
2.如果不是第一种情况，就排序后利用循环不断的将重量大的苹果弹出，然后做判断直到满足条件剩余的苹果个数就是符合题意的
思路比较直接，效率低下
### 代码

```python3
class Solution:
    def maxNumberOfApples(self, arr: List[int]) -> int:
        arr.sort()
        if sum(arr)<=5000:
            return len(arr)
        else:
            while True:
                arr.pop()
                if sum(arr)<=5000:
                    return len(arr)
```