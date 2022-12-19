思考一个问题, 如果让B输掉比赛, 那么最后一步是B拿到的值为1, 往前推, A要拿到的值是2
所以已经确定了, 如果要让B输掉比赛, 最后几步一定是该节奏。
数字: 无非是奇数或者偶数
奇数可以除的是奇数或1, 但是可以确定的是, 下一个数一定是偶数。 例如 9 % 3 = 0, 下一个数是9-3 = 6
偶数可以除的是奇偶数或1, A为先出一方, 只要保证给B的是个奇数, B就一定输。

(1) 数学归纳法

```
class Solution(object):
    def divisorGame(self, N):
        """
        :type N: int
        :rtype: bool
        """
        return N % 2 == 0
```

(2) 动态规划法
自下而上求解。
L<Boolean> 代表输或赢, 例如某值3, 去判断是否是 3 / 1 开始 L[3-1] == false (下一个状态是输, 当前状态肯定是赢)
```
class Solution(object):
    def divisorGame(self, N):
        """
        :type N: int
        :rtype: bool
        """
        # 第一个false是占位
        L = [False, False, True] + [False] * (N - 2)
        if N < 3:
            return L[N]
        else:
            for i in range(3, N + 1):
                for j in range(1, i):
                    # 可以被整除, 且下一个状态是False, 说明让B输的状态
                    if i % j == 0 and L[i-j] == False:
                        L[i] = True
                        break
            print L
            return L[N]
```
