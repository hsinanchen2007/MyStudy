### 解题思路
此处撰写解题思路
牛顿迭代法：x(n+1)=1/2(xn+a/xn)
### 代码

```python3
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        # 牛顿迭代法
        # 随机选取一个数
        pre=1
        while 1:
            cur=pre
            pre=(pre+num/pre)/2
            if abs(cur-pre)<1e-8:
                  break
        pre=int(pre)
        return True if abs(pre*pre-num)<1e-4 else False
            
        
    

```