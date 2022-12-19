### 解题思路
md好激动，我完全自己解出来的。！！！
![image.png](https://pic.leetcode-cn.com/c394f8a41767e474e6bb9abe26cdcc5d9afca0c1c649e41ddc7ee0b2e1b15c86-image.png)
例如n=4,k=4
list_n = [1,2,3,4]
如果第一个数确定了，那么还剩下三个数，就会有3*2*1种排列组合。
则以1开头的数有6种情况，以2开头的数有6种情况，以3以4开头的都是6种情况
也就是4组6个，确定第一个数属于哪一组，则可以直接除6也就是(n-1)的阶乘。
这样就可以确定其中一组。4/6=0....4
所以第一个数应该属于第一组，直接str+list_n.pop(0)即可,list_n正好也弹出了第一个数字。
list_n = [2,3,4]
确定第一个数字再确定第二个数字
k等于上一步的余数4，n=n-1=2
4/2 = 2...0
如果余数为0，那么应该是以某个数开头的最后一个排列，则2是list_n种第二大的数，直接str+=pop(2-1)即可。
这时str='13',list_n=[2,4]
因为是以3开头的最后一个数，所以最后两个数应该是最大排列，按照4，2去排
所以答案是1342

### 代码

```python3
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        def factorial(num):
            res = 1
            for i in range(1,num):
                res = res*i
            return res

        # list_n = []
        # for i in range(1,n+1):
        #     list_n.append(i)
        list_n = [i for i in range(1,n+1)]

        reminder = 1
        ans = ''
        while(reminder!=0):
            n_factorial = factorial(n)
            reminder = k % n_factorial
            if reminder==0:
                fix_num = int(k/n_factorial) - 1
            else:
                fix_num = int(k/n_factorial)
            ans += str(list_n.pop(fix_num))
            
            n = n - 1
            k = reminder

        for i in range(len(list_n)-1,-1,-1):
            ans += str(list_n[i])
            
        return ans
        
        
        
```