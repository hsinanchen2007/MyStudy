```
class Solution:
    def maxNumberOfFamilies(self, n: int, reservedSeats: List[List[int]]) -> int:
        a = {i[0]:7 for i in reservedSeats} #分别设定了3个二进制位分别代表坐下的三种情况。
        la = len(a)
        # print(a)
        cnt = (n - la)*2 #这些行没人坐 每排两个
        # print(cnt)
        for i in reservedSeats: #对有人坐的行进行标记
            if  2 <= i[1] <= 3:
                a[i[0]] = a[i[0]] & 6
            elif 8 <= i[1] <= 9:
                a[i[0]] = a[i[0]] & 5
            elif 4 <= i[1] <= 5:
                a[i[0]] = a[i[0]] & 2
            elif 6 <= i[1] <= 7:
                a[i[0]] = a[i[0]] & 1
            
            # print(i, a[i[0]])
        for i in a.items(): #对有人做的计数
            if i[1] == 7:
                cnt += 2
            elif i[1] == 0:
                cnt += 0
            else:
                cnt += 1
        return cnt
```
# 思路如下：
三个二进制位分别代表不同的坐法，用不同的位置去否掉其中的不能的坐法。
![搜狗截图20200322003724.png](https://pic.leetcode-cn.com/1a630d128be078167146cb07e71f1d8b83674d91c7d5974d9104b6ea851f456f-%E6%90%9C%E7%8B%97%E6%88%AA%E5%9B%BE20200322003724.png)


