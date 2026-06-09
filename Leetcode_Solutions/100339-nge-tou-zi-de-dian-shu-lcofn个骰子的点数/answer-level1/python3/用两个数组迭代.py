### 解题思路
设置两个6n+1长的数组，第i元用来储存和为i时的次数，第一个数组储存上一次，第二个储存这一次，基本思路就是；
假设要求和为s的次数，先来看最后一次投掷，若最后一次扔出了i,则和为s且最后一次扔i的次数为前几次扔出和为s-i的次数，i可以有1-6，把这些结果相加即可
例如：
n=2，
则若要和为5，则假如第二次扔1，第一次和要为4, 一次
                       扔2              3，一次
                       扔3              2，一次
                       扔4              1，一次
                       扔5              0，零次
                       扔6              -1 零次
                       在跌代里，可以直接设置比和小的
              

### 代码

```python3
class Solution:
    def twoSum(self, n: int) -> List[float]:
        p = [[0]*(6*n+1) for i in range(2)] 
        #p[0]前一轮循环时的和为某一个值的个数,p[1]下一轮，下一次时交换，
        flag = 0
        #第一次投递时，和为1-6的出现次数各为1
        for i in range(1,7):
            p[0][i] = 1
        #接下来对第2次,第3次，直至第n次投递进行迭代
        for k in range(2,n+1):
            #扔第k时，和最小为k，故而k-1一下的值出现次数均为0
            for i in range(k):
                p[1-flag][i] = 0 
            #扔第k时，和在k-6k之间
            for i in range(k,6*k+1):
                p[1-flag][i] = 0 #因为p[0],p[1]是交换的，后面迭代时，值不一定为0，故而初始化
                j = 1
                #这里表示，第k次要求和为i时，第k轮扔出j时，和为i的总次数为前一轮扔出i-k的次数之和
                while j<=i and j <=6:
                    p[1-flag][i] += p[flag][i-j]
                    j += 1
            flag = 1 -flag #交换，进行下一轮迭代
        total = pow(6,n)
        ratio = []
        for i in range(n,6*n+1):
            ratio.append(p[flag][i]/total)
        return ratio

                


```