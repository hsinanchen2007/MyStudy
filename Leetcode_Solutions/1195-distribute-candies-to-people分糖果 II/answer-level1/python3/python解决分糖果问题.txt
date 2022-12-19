### 解题思路
1. `给每一个小朋友都分一个碗`
2. `只要糖果>0，则判断糖果数量和i+1的大小 取其中最小的那个`
3. `然后从糖果中将已经分到的糖果给减去`
4. `最后返回最终的kids`

### 代码

```python3
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        #给小朋友发碗
        kids = [0] * num_people
        #从0开始
        i = 0
        while candies > 0:
            #i % num_people就是每个小朋友的索引
            kids[i % num_people] += min(i+1,candies)
            #将分到的从糖果中减去
            candies -= i+1
            #继续给下一个小朋友分发糖果
            i += 1
        return kids
```