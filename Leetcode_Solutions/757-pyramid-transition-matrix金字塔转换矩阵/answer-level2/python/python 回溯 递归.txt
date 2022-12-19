思路：
1.将三元数组列表按前两位字符进行hash处理
例：
allowed = ["XXX", "XXY", "XYX", "XYY", "YXZ"] 
hashmap  = {'XX': ['X', 'Y'], 'XY': ['X', 'Y'], 'YX': ['Z']})

2.根据旧层（old_bottom）获取下一层可能的组成的字符串，然后逐层递归处理，直到该层长度为1，则返回true，
否则获取下一个可能组成的字符串，继续上续处理，遍历完还没有结果则返回false

```
from collections import defaultdict
class Solution:
    def pyramidTransition(self, bottom: str, allowed: List[str]) -> bool:
        #将allowed进行哈希映射
        #allowed = ["XXX", "XXY", "XYX", "XYY", "YXZ"] 
        #hashmap  = {'XX': ['X', 'Y'], 'XY': ['X', 'Y'], 'YX': ['Z']})
        hashmap = defaultdict(list)
        for brick in allowed:
            hashmap[ brick[0:-1] ].append( brick[-1] )

        # 开始回溯
        # old_brick_index是指old_bottom中第几个连续两块，范围为[1, len(old_bottom)]
        def backtrace(old_brick_index, old_bottom, new_bottom):
            #判断new_bottom是否已经建立好
            if len(new_bottom)==len(old_bottom)-1:
                #new_bottom长度为1，说明到顶
                if len(new_bottom)==1:
                    return True
                #否则，new_bottom作为底向上堆
                else:
                    return backtrace(1, new_bottom, "")
            
            old_brick = old_bottom[old_brick_index-1:old_brick_index+1]
            for j in hashmap[ old_brick ]:
                    new_bottom += j
                    if backtrace(old_brick_index+1, old_bottom, new_bottom):
                        return True
                    new_bottom = new_bottom[0:-1]
            
            return False

        return backtrace(1, bottom, "")
```
