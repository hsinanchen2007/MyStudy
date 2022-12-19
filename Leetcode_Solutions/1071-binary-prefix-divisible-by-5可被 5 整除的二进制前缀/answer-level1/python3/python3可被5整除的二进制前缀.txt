### 解题思路
求和取模并直接在原数组上修改得到的结果，内存消耗最小。

### 代码

```python3
class Solution:
    def prefixesDivBy5(self, A: List[int]) -> List[bool]:
        tsum=0
        for i,num in enumerate(A):
            tsum=(tsum*2+num)%5
            A[i]=(tsum%5==0)
        return A
```

![image.png](https://pic.leetcode-cn.com/66105d8fa886a9598642bb494cc29aee9d050c588593cb2980b7f0ae5e8fb9a7-image.png)
