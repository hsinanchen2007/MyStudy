### 解题思路
该题主要注意一个点：需要顺序匹配。因此在原先遍历列表answer判断里面的元素是否也存在列表guess中时，也应该注意顺序问题。
所以本题可以通过enumerate()函数进行遍历列表。（首先得声明一个变量count，来记录猜对的数字个数）
该函数能够在返回元素值i的同时，返回该元素值所在的索引值index（即位置）。通过获取到的索引值index在guess列表中取值，如果取到的值跟
该函数返回的元素值i相等，那就意味着猜对了，而且这个做法也考虑了顺序问题。

### 代码

```python3
class Solution:
    def game(self, guess: List[int], answer: List[int]) -> int:
        count = 0
        for index, i in enumerate(answer):
            if guess[index] == i:
                count += 1
        
        return count
```