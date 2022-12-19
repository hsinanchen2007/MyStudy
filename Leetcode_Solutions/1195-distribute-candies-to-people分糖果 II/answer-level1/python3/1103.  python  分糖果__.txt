### 解题思路
因为每次向后分发的糖果都要比前一个小朋友多一个糖果，所以用额外的O(1)空间来记录每次应发放的糖果个数。如果剩余糖果数大于当前应发放的糖果个数，进行分发，反之，说明糖果不足，将剩余糖果全部分给这个小朋友，跳出循环。
因为是正向循环遍历，随着糖果越多，小朋友越少，时间复杂度越高。

### 代码

```python
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        list_ = [0 for i in range(num_people+1)]
        if candies == 0:
            return list_[1:]
        flag = True
        while flag:
            for i in range(1,num_people+1):
                if candies > list_[0]:
                    list_[0] += 1
                    list_[i] += list_[0]
                    candies -= list_[0]
                else:
                    list_[i] += candies
                    flag = False
                    break
        return list_[1:]


                
        
                
```