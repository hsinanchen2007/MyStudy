### 解题思路
统计‘L’和'R'的序列，start中的L只允许左移，R只允许右移，判断一下idx就可以了

### 代码

```python3
from collections import Counter
class Solution:
    def canTransform(self, start: str, end: str) -> bool:
        def get_restRL(start):
            re=''
            idx_array=[]
            for idx,it in enumerate(start):
                if it =='R' or it=='L':
                    re=re+it
                    idx_array.append(idx)
            return re,idx_array
        count_start=Counter(start)
        count_end=Counter(end)
        if not (count_start['X'] == count_end['X']and count_start['R'] == count_end['R'] and count_start['L'] == count_end['L']):
            return False
        start_LR,start_array=get_restRL(start)
        end_LR,end_array=get_restRL(end)
        #print(start_LR,start_array)
        #print(end_LR,end_array)
        if len(start_LR)!= len(end_LR):
            return False
        for st_idx,st_itm in enumerate(start_LR):

            if st_itm != end_LR[st_idx]:
                return False
            else:
                if st_itm =='R' and start_array[st_idx]>end_array[st_idx]:
                    return False
                if st_itm =='L' and start_array[st_idx]<end_array[st_idx]:
                    return False
        return True 
```