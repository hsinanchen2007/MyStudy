```from math import factorial


class Solution(object):
    def climbStairs(self, n):
        """
        x + 2y == 4
        if x == 0:
            y = 4/2==2 # 整数，可以，0个1，2个2
        elif x == 1:
            y = (4 -1)/2==1.5 # 小数，不要
        elif x == 2:
            y = (4-2)/2==1 #整数，可以.2个1，1个2
            进行排列：
            1和2的排列有:(1+2)!/(2!*1!)
        elif x == 3:
            y = (4-3)/2 == 0.5 # 小数，不要
        elif x == 4:
            y = 0/2==0 # 整数，可以。4个1，0个2,y等于0,停止
        """
        x = 0
        sum = 0
        while True:
            if (n-x)%2 == 0:
                y = (n-x)/2
                m = factorial(x+y)/(factorial(x)*factorial(y))
                # print(m)
                sum += m
                if y == 0:
                    break
            x += 1
        return int(sum)

if __name__ == "__main__":
    s = Solution()
    a = s.climbStairs(10)
    print(a)


# 代码块
```
