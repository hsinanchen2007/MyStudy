### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        numStack = []
        
        # Construct a monotone increasing sequence of digits
        for digit in num:
            #按照顺序，把小的持续放到前面,
            while k and numStack and numStack[-1] > digit:
                numStack.pop()
                k -= 1
            #都比较完了，确定比前面的小之后再添加进来
            numStack.append(digit)
        
        # - Trunk the remaining K digits at the end
        # - in the case k==0: return the entire list
        #如果加多了，要把多加的元素去掉
        finalStack = numStack[:-k] if k else numStack
        
        # trip the leading zeros
        return "".join(finalStack).lstrip('0') or "0"
```

再补充DFS算法：
class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        n = len(num)                           
        if k >= n:                             
            return "0"
        if k == 0:
            return num                           
        minRes = [-1]                           
                                        
        def dfs(index, path):                  
            # print(path)
            if  minRes[0] != -1 and  int(path)> minRes[0]:    
                return                                                              
            if len(path) == n - k:             
                if minRes[0] == -1:             
                    minRes[0] = int(path)      
                elif int(path) < minRes[0]:    
                    minRes[0] = int(path)      
                return                         
                                                
            for i in range(index + 1, n):      
                dfs(i, path + num[i])          
                                                
        for i in range(0, n):              
            dfs(i, "" + num[i])                
        return str(minRes[0])