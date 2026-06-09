### 解题思路
一次遍历数组，使用额外空间。

### 代码

```python3
class Solution:
    def sortArrayByParityII(self, A: List[int]) -> List[int]:
        res=[0]*len(A)
        i=0
        j=1
        for a in A:
            if a&1:
                res[j]=a
                j+=2
            else:
                res[i]=a
                i+=2
        return res
```

![image.png](https://pic.leetcode-cn.com/645b2b0323d6f2cc2ff8715035e3b86f59c34c6826b837c7d8430968d51fd275-image.png)
