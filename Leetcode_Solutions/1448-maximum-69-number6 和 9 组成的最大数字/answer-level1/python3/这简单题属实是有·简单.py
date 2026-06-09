### 解题思路
找到第一个6，替换成9
![QQ截图20200218160135.png](https://pic.leetcode-cn.com/2e4aa8f53f8fe710087d8dfe289f9127b5d4aa9d92946356bce5961cbc22ccdf-QQ%E6%88%AA%E5%9B%BE20200218160135.png)


### 代码

```python3
class Solution:
    def maximum69Number (self, num: int) -> int:
        the_first_6=str(num).find("6")
        res=""
        if the_first_6!=-1:
            for i in range(len(str(num))):
                if i!=the_first_6:
                    res+=str(num)[i]
                else:
                    res+="9"
        else:
            return num
        return int(res)
```