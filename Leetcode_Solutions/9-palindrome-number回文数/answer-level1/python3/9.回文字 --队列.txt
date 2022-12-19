### 解题思路
1.将数字转换为字符数组
2.对字符数组进行pop(0),pop()操作，最多len(x)//2次，比较弹出来的值是否相等，若不相等，则直接返回，否则进行下一次弹出。

### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        def splitstr(x):
            res=[]
            for item in x:
                res.append(item)
            return res
        x=splitstr(str(x))
        for i in range(len(x)//2):
            head=x.pop(0)
            tail=x.pop()
            if head !=tail:return False
        return True


```