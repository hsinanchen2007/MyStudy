### 1.左移运算
![image.png](https://pic.leetcode-cn.com/7baf9b0e36949b012bb9870c0f644455a034ec260b48a125ec81e597fffbea20-image.png)

- 我们设置一个标志 `flag = 1`,然后每次将`flag` 与 `n` 进行与运算,然后再将`flag`左移一位
- 代码中的 `flag < 32`代表二进制有 32 位
```
class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        result = 0
        temp = 1
        flag = 0
        while flag < 32 :
            if n & temp:
                result += 1
            temp = temp << 1
            flag += 1
        return result
```



### 2.原数减一再做与运算
![image.png](https://pic.leetcode-cn.com/938fe10fec2d2f30194a001a2879ac8863a2277aaabd0fe83c46b995239d4ee5-image.png)

- 假设我们有一个二进制数 `n = 1100`,`n-1 = 1011 `,我们让`n & (n-1) = 1000`,可以看到会把最右边的 1 变成 0
- 所以总结起来就是: 把一个整数减去 1 ,再和原来的数做与运算,会把该整数最右边的 1 变成 0. 那么一个整数二进制表示中有多少个 1 ,就可以进行多少次这样的操作

### 代码

```python
class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        result = 0
        while n:
            result += 1
            n = n & (n-1)
        return result
```