### 解题思路
方法一：
字符串+自有函数
1、写法最简，不接受反驳
2、本质是暴力算法
3、时空复杂度：O(n)

### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        return True if str(x)==str(x)[::-1] else False
```

### 其他解题思路：
1、反转一半数字，时空复杂度均降低一半，双队列或者双端队列就很合适
2、取余去高位，负数全部False
3、适用于长数字：一半反转，分治比较（比如二分、分块等）
