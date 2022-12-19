### 解题思路

递归

### 代码

```python
class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
      
        init = '1'  # 第一个数

        while n-1>0:  # 外侧循坏递归n-1次
            frist,temp,count= init[0] ,'',1
            for j in range(1,len(init)): # 内侧循坏对于每个数字的报数
                if frist==init[j]:
                    count+=1
                else:
                    temp=temp+str(count)+frist
                    count=1
                    frist=init[j]
            n=n-1
            temp = temp+str(count)+frist # 每个数最后一个特列
            
            init = temp # 更新初始值
        return init
```