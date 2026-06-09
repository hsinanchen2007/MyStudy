### 解题思路
格雷编码的规律没看出来，参照了大神的解法。
![image.png](https://pic.leetcode-cn.com/2bbf005c59178de8609e837b94863911a5b39492a0404fb1a8e01997a66e1f53-image.png)

### 代码

```python3
import copy


class Solution:
    def grayCode(self, n: int) -> List[int]:
        if n == 0:
            return [0]
        
        initial = ['0', '1']
        for i in range(n-1):
            new = copy.deepcopy(initial)    
            new.reverse()
            for l, v in enumerate(initial):
                initial[l] = '0' + initial[l]
            for l, v in enumerate(new):
                new[l] = '1' + new[l]
            initial.extend(new)

        return [int(str_int, 2) for str_int in initial]
            
```