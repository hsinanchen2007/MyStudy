### 解题思路
将数N拆成i和N-i(i取1到N-1之间)
选出目前阶段的乘机和拆成n-i和i的乘积和n-i再拆的乘积中的最大值返回
![求最大分解.jpg](https://pic.leetcode-cn.com/66d7c3b1e99f7241e2e3d175457e8402a013e8f41a0987afeec5f6f9012626d8-%E6%B1%82%E6%9C%80%E5%A4%A7%E5%88%86%E8%A7%A3.jpg)


### 代码

```python3
meno = {}

def breakInt(n):

    if n==1:
        return 1
    
    if n in meno.keys():
        return meno[n]
    i = 1
    maxRet = -1
    while(i<n):
        maxRet = max(maxRet, i*(n-i), i*breakInt(n-i))
        i = i + 1
    meno[n] = maxRet
    return maxRet

class Solution:

    def integerBreak(self, n: int) -> int:
        return breakInt(n)
    


```