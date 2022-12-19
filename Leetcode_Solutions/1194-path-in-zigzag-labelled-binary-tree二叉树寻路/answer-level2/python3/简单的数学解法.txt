看到本题的标签有个Math，就简单用了数学的解法。
```
import math

class Solution:
    def pathInZigZagTree(self, label: int) -> List[int]:    
        if label == 0: return []
        if label == 1: return [1]
        
        res = [label]
        while label > 1:
            # label所属level
            level = int(math.log2(label))
            # label行最小值
            level_start = 2 ** level
            # label与该行最小值的差值整除2， 用于得到上一行连接label的数字
            remain = (label - level_start) // 2
            
            # 迭代label
            label = level_start - 1 - remain
            res.append(label)
        
        return res[::-1]
```
