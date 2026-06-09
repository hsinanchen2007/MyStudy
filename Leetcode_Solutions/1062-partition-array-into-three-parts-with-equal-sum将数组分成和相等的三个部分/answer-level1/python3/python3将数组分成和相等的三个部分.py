### 解题思路
依次遍历数组，找到两个三分之一和时即可跳出循环

### 代码

```python3
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        sumt=sum(A)/3
        cursum=0
        pn=0
        for i in A:
            cursum+=i
            if cursum==sumt:
                cursum=0
                pn+=1
                if pn==2:
                    return True
        return False
```
![image.png](https://pic.leetcode-cn.com/7c2585729312bac8d3a1e824a974a39721fb0c595248eea113361437be4a6923-image.png)
