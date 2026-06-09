### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        dp = {(m,n):0}
        for s in strs:
            ms,ns = len([1 for si in s if si =='0' ]),len([1 for si in s if si =='1' ])
            for (key_m,key_n),value in dp.copy().items() :
                tmpm,tmpn =key_m-ms,key_n-ns
                if min(tmpm,tmpn)>-1:
                    dp[(tmpm,tmpn)] =  max(dp.get((tmpm,tmpn),0),value+1)
        return max( dp.values())



        
        

```