### 解题思路
* 当前值等于前一个值的:频次+值
* 所以求解思路就变为,遍历上一个字符,使用prev记录上一个值，如果当前值等于上一个值,计数器就加一。当前值不等于上一个值，直接用生成器返回。

### 代码

```python3

class Solution:
    def countAndSay(self, n: int) -> str:
        if n<1 or n > 30:
            return None

        if n == 1:
            return "1"

        prev = "1"
        for i in range(2,n+1):
            curr = ""
            for k in self.parse(prev):
                curr += k["count"]
                curr += k["val"]
            prev = curr
            if i == n:
                return curr


    def parse(self, value):
        count = None
        prev = None

        for index,val in enumerate(value):
            if val == prev:
                count += 1
            else:
                if index != 0:
                    yield {'count':str(count),'val':prev}
                count = 1
            if index == len(value) - 1:
                yield {'count':str(count),'val':val}
            prev = val


```