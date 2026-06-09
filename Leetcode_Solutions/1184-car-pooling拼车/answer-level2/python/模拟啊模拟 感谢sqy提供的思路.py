### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        events = []
        for num,s ,e in trips:
            events.append((s,1,num)) #shangche
            events.append((e,0,num)) #xiache
        events.sort()
        print(events)
        cur = 0
        for time, typ,num in events:
            
            if typ ==0:
                cur -= num
            if typ ==1:
                cur+=num
                if cur>capacity:
                    return False
        return True

```