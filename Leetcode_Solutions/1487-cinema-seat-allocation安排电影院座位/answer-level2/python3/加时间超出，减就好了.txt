### 解题思路
如题目所述，不难，代码如下
### 代码

```python3
class Solution:
    def maxNumberOfFamilies(self, n: int, reservedSeats: List[List[int]]) -> int:
        # reservedSeats = sorted(reservedSeats, reverse = True)
        # print(reservedSeats)
        def row_num(x):
            first_tel = True
            second_tel = True
            third_tel = True
            if not x:
                return 0
            if 0 in x:
                first_tel = False
            if 1 in x:
                first_tel = False
                second_tel = False
            if 2 in x:
                second_tel = False
                third_tel = False
            if 3 in x:
                third_tel = False
            
            if first_tel and third_tel:
                return 0
            if first_tel:
                return 1
            if second_tel:
                return 1
            if third_tel:
                return 1
            return 2
        reserved = {}
        # tel = [False]*(n+1)
        for i in reservedSeats:
            if i[0] not in reserved.keys():
                reserved[i[0]] = []
                # tel[i[0]] = True
            if i[1] in [2, 3]:
                reserved[i[0]].append(0)
            if i[1] in [4, 5]:
                reserved[i[0]].append(1)
            if i[1] in [6, 7]:
                reserved[i[0]].append(2)
            if i[1] in [8, 9]:
                reserved[i[0]].append(3)
        # print(reserved)
        re = 2*n
        for i, l in reserved.items():
            re -= row_num(l)
            
        return re
                    
```