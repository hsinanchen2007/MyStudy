### 解题思路
得到upper上界后，count列表，为列表中有重复元素的位置找空缺，并且返回他们之间和的差即可
在中间空缺不够的时候再往后依次递补

还有一种排序的思想，更直接一点，把排序后的每一个前后相等的元素变为差1，就不写了
### 代码

```python3
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        if len(A) == 0:
            return 0
        upper = max(A)
        ans = [0 for _ in range(upper+1)]
        for i in A:
            ans[i] += 1
        
        wait = 0
        num = 0
        available = 0
        for i in range(upper+1):
            if ans[i] > 1:
                wait += (ans[i]-1)*i
                num += (ans[i]-1)
            elif ans[i] == 0 and num > 0:
                available += i
                num -= 1
        
        if num == 0 :
            return available - wait
        else:
            k = 1
            while(num):
                available += (upper + k)
                k += 1
                num -= 1
                
            return available - wait
                
                
        
                
        
        
        
            
```