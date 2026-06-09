### 解题思路
开始在思考有没有什么数学解法，不如暴力来的简单啊

### 代码

```python3
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        ans=[0]*num_people
        i=0      #计数方法
        candy=0 #每回发的糖

        while candies>0:
            if i==0:
                candy +=1
                if candies >=candy:
                    candies -= candy
                    ans[i] +=candy
                    i +=1
                else: return ans
            else:
                b= i%num_people #对分糖人数取于得到索引值
                candy +=1
                i +=1
                if candies>=candy:
                    candies -= candy
                    ans[b] += candy
                else:
                     ans[b] += candies
                     candies=0
        return ans

```