![image.png](https://pic.leetcode-cn.com/0c3c0ec972d14147114298bf7c280199b5786de7774669c04ea5fd40062bdbc7-image.png)

从空字符串开始，上面的（绿色）分别加0、1，下面的（红色）分别加1、0，直到长度达n

```python []
class Solution:
    def grayCode(self, n: int) -> List[int]:
        if n==0:
            return [0]

        res=[]
        def back(now,x):
            if len(now)==n:
                res.append(int(now,2))
            elif x==0:
                back(now+'0',0)
                back(now+'1',1)
            else:
                back(now+'1',0)
                back(now+'0',1)
        
        back('',0)
        return res
```