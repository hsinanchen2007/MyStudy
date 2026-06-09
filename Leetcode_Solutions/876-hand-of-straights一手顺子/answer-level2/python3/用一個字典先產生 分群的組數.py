### 解题思路
先產生分群的組數 再依照順序放入list
當發生 放入的元素與之前相差不等於1 
或是 到最後一組都不法放入 表示 失敗

### 代码

```python3
class Solution:
    def isNStraightHand(self, hand: List[int], W: int) -> bool:
    
        if len(hand) % W != 0:
            return False
            
        hand.sort()
        divde = int(len(hand) // W)
        record = collections.defaultdict(list)

        while len(hand) > 0:
            v = hand.pop(0) 
            # get = False 
            for i in range(0, divde):
                if len(record[i]) == W:
                    continue
                elif len(record[i]) == 0:
                    record[i].append(v)
                    # get = True
                    break
                elif len(record[i]) != 0 and v - record[i][-1] == 1:
                    record[i].append(v)  
                    # get = True
                    break          
                elif (len(record[i]) != 0 and v - record[i][-1] > 1) or (i == divde-1 and v - record[i][-1] != 1):
                    return False     
            # if get == False:
            #     return False        
        return True    


```