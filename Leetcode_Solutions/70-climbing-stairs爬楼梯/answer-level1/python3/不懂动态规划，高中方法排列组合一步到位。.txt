### 解题思路


### 
![截屏2020-04-10 下午2.38.26.png](https://pic.leetcode-cn.com/8839d5f5e577068070f138e5384504922c56a05fde7614c4e9a416a253c5c200-%E6%88%AA%E5%B1%8F2020-04-10%20%E4%B8%8B%E5%8D%882.38.26.png)



```python
   #假设有n个台阶
    #n = 1*a + 2*b （n个台阶需要上 a个1阶 和 b个阶梯）
    #假设b已经确定，那么所有可能的组合为:从a+b个位置中选择b个两阶梯的（或者选a个一阶的也可
    #总数kb = c(a+b,b) a+b=n-b(由上柿可知) kb = c(n-b,b)
    #对于所有可能的b，求和kb即可  
def fact(x): #做个阶乘函数
    k = 1
    for i in range(1,x+1):
        k = k*i
    return k
def c(y,x):  #做个排列组合函数,y中选x个
    fenzi = fact(y)
    fenmu = fact(x)*fact(y-x)
    return fenzi/fenmu
class Solution(object):
    def climbStairs(self, n):
        ans = 0
        for i in range(0,n//2+1): 
            ans = ans + c(n-i,i)  #i是每一个可能的b，组合为 kb = c(n-b,b)，求和kb
        return ans




```