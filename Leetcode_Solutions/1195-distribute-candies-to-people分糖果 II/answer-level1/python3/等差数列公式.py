### 解题思路
题目目标：
- 把n个糖果，分给m个人，每个人比上个人多一个，不够则全给
解题思路：
1. 最多可以发多少轮
- m个人
- 第一轮，要((1+m)m)/2个糖果：  ((1+m)1m)/2)
- 第二轮，要((1+2m)2m/2)个糖果：((1+2m)2m/2)
- 第三轮，要((1+3m)3m/2)个糖果：((1+3m)3m/2)
- 判断n个糖果，最多可以发k轮
2. 取max_round-1进行初始化
- 取k-1轮初始化，
- 第1个人：(0*m+1)+(1m+1)+(2m+1)+(3m+1)+...+((k-2)m+1)=(1+((k-2)m+1))(k-1)/2
- 第2个人：(0*m+2)+(1m+2)+(2m+2)+(3m+2)+...+((k-2)m+2)=(2+((k-2)m+2))(k-1)/2
- 开始第k轮，现剩余n - ((1+5m)m/2) = j
3. 第i个人第max_round轮需要(max_round-1)*num_peoples+i
- 循环，递减，小于，终止

### 代码

```python3

class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        #最多可以发多少轮
        max_round = 10**9
        for i in range(1,max_round):
            if (1+i*num_people)*i*num_people/2 >= candies:
                max_round = i
                break
        #取max_round-1进行初始化
        res = [0 for i in range(num_people)]
        if max_round > 1:
            for i in range(1,num_people+1):
                curr = int(( i + ( (max_round-2)*num_people+i) ) * (max_round-1) / 2)
                res[i-1] = curr
        left_candies = int(candies - (1+(max_round-1)*num_people)*(max_round-1)*num_people/2)
        #第i个人第max_round轮需要(max_round-1)*num_peoples+i
        for i in range(1,num_people+1):
            curr = (max_round-1)*num_people+i
            if left_candies >= curr:
                res[i-1] += curr
                left_candies -= curr
            else:
                res[i-1] += left_candies
                break

        return res
```