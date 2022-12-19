### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        # 声明首次所分糖果数量
        i = 1
        # 声明一个小朋友list，长度为小朋友数量，初始糖果数量为0个
        Allist = [0] * num_people
        # 遍历小朋友list，挨个进行分糖果操作，直至糖果发完
        while candies >0:
            for x in range(num_people):
                # 判断当前剩余糖果是否大于要分配的糖果
                # 如果当前生于糖果大于要分配的糖果
                if candies >= i:
                    # 给对应小朋友分配要分配的糖果，统计当前小朋友累计糖果
                    Allist[x] += i
                    # 剩余糖果数量 = 分配前数量 - 分配数量
                    candies -= i 
                    # 下次分配糖果数量要+1
                    i += 1
                # 如果剩余糖果不足应该分配的糖果，直接把剩余糖果给当前小朋友
                else:
                    Allist[x] += candies
                    candies = 0
            # 返回每个小朋友获得糖果
        return Allist
```