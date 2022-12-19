### 解题思路
首先排除两种情况：1.负数，2.结尾是0的非0数
接着来反转数字，只需将x的后一半拿出来反转，然后比较前一半和后一半是否相同即可。
如何取出反转：利用*10、%10、//10。
如何判断已经取出后一半了：当x不再大于反转的数字时即取出一半。
例1：x=123321，当x=123, reverse_num=123时即完成了取出一半反转，若reverse_num == x，即为回文；
例2：x=12321，当x=12, reverse_num=123时即完成了取出一半反转，奇数位数最中间的数无需考虑，所以若reverse_num//10 == x，即为回文。

### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if (x < 0) or (x != 0 and x%10 == 0):
            return False
        reverse_num = 0
        while x > reverse_num:
            reverse_num = reverse_num*10 + x%10
            x = x//10
        return (reverse_num == x) or (reverse_num//10 == x)
```