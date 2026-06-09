'''
面试题62. 圆圈中最后剩下的数字
0,1,,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字。求出这个圆圈里剩下的最后一个数字。

例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。

 

示例 1：

输入: n = 5, m = 3
输出: 3
示例 2：

输入: n = 10, m = 17
输出: 2
'''

'''
this method cost too much time in large tests
'''

```

class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        li = list(range(n))
        while len(li) > 1:
            for i in range(1,m):
                li.append(li.pop(0))
            li.pop(0)
        return li[0]
```

'''
the answer is confusing.......
'''


```
def f(n, m):
    if n == 0:
        return 0
    x = f(n - 1, m)
    print('f(', n-1, ',', m, ') = ', x)
    return (m + x) % n

print(f(5,3))
```

'''understand! very hard
you know the index of the alive one of the next round.
how to get the alive index of the current round?
the fomula is:
((the next result) + (shoot interval)) % the current length

**(ni + delta) % l = ci
ci + n * l = ni + delta**

because if the current alive index is n
the next alive index would be:

**ci + n * l - delta = ni
ci - delta = ni**

_____here is explanation_____

asume that we know the alive number from the beginning.
after a shoot (as your first solution),
the alive index will move to left for delta steps,
because the list is reshulffled for that times.
![image.png](https://pic.leetcode-cn.com/0fd301eb50878da8f7a224313156ca5ad7b2fc1b728c29712285c70ca1c17228-image.png)

ci - delta = ni

but you can't have a index out of the list
so the needle will keep moving like a stack
there for, 
ci + n * l - delta = ni
n is the least number which can keep ni a positive number...

now, we know the final index is 0, we know the top length, we know the delta. 
can we get the initial alive index from these informations?
yes you can.
**ci = (ni + delta) % l**

just recurse it

'''


'''
recursion
'''

```
sys.setrecursionlimit(100000)

class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        def YourselfLoop(n,m):
            if n == 0:
                return 0
            lastindex = YourselfLoop(n-1,m)
            return (lastindex + m) % n
        return YourselfLoop(n,m)
```

'''
or other
'''


```
def YourselfLoopAnother(n,m):
    i = 0
    for t in range(2,n+1):
        i = (i + m) % t
    return i
```
