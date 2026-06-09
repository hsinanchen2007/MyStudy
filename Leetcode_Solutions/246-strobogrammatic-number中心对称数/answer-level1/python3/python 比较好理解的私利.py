### 解题思路
把中心对称的数字记下来，然后头尾判断一下是不是对应的，如果不是中心对称数肯定不可以旋转，如果是的话，
还需要一一对应关系，6对9，8对8

### 代码

```python3
class Solution:
    def isStrobogrammatic(self, num: str) -> bool:
        centre={"9":"6","6":"9","8":"8","0":"0","1":"1"}
        i=0
        n=len(num)
        while i <= n//2:
            if num[i] not in centre:
                return False
            if centre[num[i]]!=num[n-1-i]:
                return False
            i+=1
        return True


      
```