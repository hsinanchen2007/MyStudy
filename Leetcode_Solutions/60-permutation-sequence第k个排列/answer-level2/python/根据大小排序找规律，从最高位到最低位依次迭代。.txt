```
'''
以 n=4 为例 k=7为例子 由于k从1开始变为从0开始 k = k - 1 = 6 li = [1,2,3,4]：
1： 1234
2： 1243
3： 1324
4： 1342
5： 1423
6： 1432

7： 2134
8： 2143
9： 2314
10：2341
....
计算结果第一位li = [1,2,3,4] n = 4 k = 6
li = [1,2,3,4]
k/(n-1)! = 6/(3*2) = 1 
结果第一位为li[k/(n-1)!] = li[1] = 2 弹出li[1] 

计算结果第二位 li = [1,3,4] k = k%（n-1）! = 0 n = 3
li = [1,3,4]
k/(n-1)! = 0/(2*1) = 0
结果第二位为li[k/(n-1)!] = li[0] = 1 弹出li[0]

计算结果第三位li = [3,4] k = k%（n-1）! = 0 n = 2
li = [3,4]
k/(n-1)! = 0/1! = 0
结果第二位为li[k/(n-1)!] = li[0] = 3 弹出li[0] 

计算结果第四位li = [4] k = k%（n-1）! = 0 n = 1
li = [4]
k/(n-1)! = 0/0! = 0
结果第二位为li[k/(n-1)!] = li[0] = 4 弹出li[0] 

n  = 0 递归终止返回self.ans

'''
class Solution(object):
    def __init__(self):
        self.ans = ''
    def jiecheng(self,n):
        if n == 0:
            return 1
        return n*self.jiecheng(n-1)
    def get(self,n,k,li):
        if n == 0:
            return
        self.ans += str(li[int(k / self.jiecheng(n - 1))])
        li.pop(int(k / self.jiecheng(n - 1)))
        self.get(n-1,k % self.jiecheng(n-1),li)
    def getPermutation(self, n, k):
        k = k - 1
        li = list(range(1,n+1))
        self.get(n,k,li)
        return self.ans
```
执行用时 : 24 ms, 在Permutation Sequence的Python提交中击败了93.42% 的用户
内存消耗 : 11.6 MB, 在Permutation Sequence的Python提交中击败了48.78% 的用户

