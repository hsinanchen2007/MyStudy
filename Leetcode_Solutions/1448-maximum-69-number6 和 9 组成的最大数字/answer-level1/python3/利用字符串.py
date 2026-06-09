### 解题思路
将第一个6变为9 就能得到结果
本来想取巧的
但是忽略了全为9，找不到6 会报异常
和6在最后，会指针溢出
本来以为是段很简洁的代码，结果变成了这样

### 代码

```python3
class Solution:
    def maximum69Number (self, num: int) -> int:
        numStr = str(num)
        '''
        获得整数中第一个6的位置
        '''
        if '6' in numStr:
            index = numStr.index('6')
            if index != len(numStr)-1:
                result = numStr[:index]+ '9' +numStr[index+1:]
            else:
                result = numStr[:index]+ '9'
            return int(result)
        else:
            return num
```