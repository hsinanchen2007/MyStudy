### 解题思路
此处撰写解题思路
如代码注释
### 代码

```python3
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        i = 0 #表示集合的位置
        j = 1 #得到糖果的数量
        A=[0]*num_people #有几个小朋友
        while candies>0: 
            A[i] += j 
            candies -= j
            if i == num_people - 1: #如果到了最后一个小朋友则跳到第一个小朋友
                i=-1
            if candies<=j: #如果剩余的糖果没有前一次多 则全部给下一个小朋友 且结束循环
                A[i+1] +=candies
                break
            i+=1
            j+=1
        return A


```