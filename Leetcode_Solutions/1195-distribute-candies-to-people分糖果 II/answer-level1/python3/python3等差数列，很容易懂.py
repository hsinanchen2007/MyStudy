1.思路1是直接遍历，直到糖果没了。

2.思路2:
利用等差数列。假设有n个人，
第一轮，每个人收到的糖果数量是：
1，2，3，......，n
第二轮，每个人收到的糖果数量是：
n+1,n+2,n+3,......2n
第三轮，每个人收到的糖果数量是:
2n+1,2n+2,2n+3,......3n
类推，低k轮，每个人收到的糖果数量是：
n(k-1)+1,n(k-1)+2,...n(k-1)+i-1,......,nk
那么，假设turns是这些糖果candies最大能发的轮数，那么根据等比数列求和，turns轮的总共糖果数量是
(turns * n + 1) * (n * turns) / 2
剩下的糖果是：
candies - (turns * n + 1) * (n * turns) / 2
则剩下的糖果，不够一轮的，那就从第0,1,2,...n开始遍历就行了。
需要做的事情：
（1）找到最大的turns，很简单，从0开始遍历就行了
（2）分配前turns轮的糖果，考虑到，第k轮，第i个人分到的糖果数量是 (turns - 1) * n + i+1，第一次分到的糖果数量是(i+1) ，那么根据等差数量求和，他分到的总数是：((i+1) + (turns - 1) * n + i+1) * turns // 2。
（3）分配剩下的candies - (turns * n + 1) * (n * turns) / 2个糖果，判断剩下的是否够按照(turns) * n + i+1分给他，够就分，不够就全部给他，即可。
代码：

```python
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        if(num_people == 1):
            return [candies]
        n = num_people
        turns = 1
        while((turns * n + 1) * (n * turns) // 2 < candies):
            turns += 1
        turns -= 1
        left = candies - (turns * n + 1) * (n * turns) // 2
        res = [0] * n
        for i in range(n):
            res[i] = ((i+1) + (turns - 1) * n + i+1) * turns // 2
        i = 0
        # return [turns]
        while(left > 0):
            if(left > turns * n + i + 1):
                res[i] += turns * n + i + 1
                left -= turns * n + i + 1
                i += 1
            else:
                res[i] += left
                left = 0
        return res
```
```
代码块
```
