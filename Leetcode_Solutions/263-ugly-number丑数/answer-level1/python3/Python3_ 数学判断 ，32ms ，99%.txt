### 3个数学判断方法：
<br>
判断2：末尾是否能被2整除
判断3：所有数位加起来能否被3整除
判断5：末位是否能被5整除
<br>
![截屏2019-11-2614.55.59.png](https://pic.leetcode-cn.com/f312f851e2e349ea8548f2b66e83684c2978cd8ce9ff8f1860ef49a405463037-%E6%88%AA%E5%B1%8F2019-11-2614.55.59.png)


```python []
class Solution:
    def isUgly(self, num: int) -> bool:
        if num < 0 or num == 0:return False
        while num!= 1:
            # 判断 2
            if int(str(num)[-1]) % 2 == 0:
                num = num // 2
            # 判断 3
            elif sum([int(c) for c in str(num)]) % 3 == 0:
                num = num // 3
            # 判断 5
            elif str(num)[-1] in ["0","5"]:
                num = num // 5
            else:
                return False
        return True
```

