### 解题思路
# **方法3、4行最优数学解 **
他山之石不在赘述。
具体题解见[数学思维题的简单易懂解释](https://leetcode-cn.com/problems/task-scheduler/solution/shu-xue-si-wei-ti-de-jian-dan-yi-dong-jie-shi-by-w/)
参考学习后，python实现如下
### 代码

```python3
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        tnum=[]
        for i in set(tasks):tnum.append(tasks.count(i))
        maxt=max(tnum)
        return max((n+1)*(maxt-1)+tnum.count(maxt),len(tasks))
```
###  解题思路
# **方法1、排序：待执行次数为正，多执行次数为负**
执行用时 :764 ms, 在所有 Python3 提交中击败了13.62%的用户
内存消耗 :13.6 MB, 在所有 Python3 提交中击败了28.90%的用户
**基本思路：**
1、梳理出需要执行的任务以及每个任务对应的次数；
2、每次对需要执行的任务按需要执行的次数排序，优先执行次数多的，直到所有任务执行完。实际我们只关心任务的次数，因此只对次数队列操作即可。用每一个正数代表需要执行的任务对应的次数。
2.1、执行一次，对应次数减1。
2.2、如果任务种类len(tnum)<n+1,说明单次执行小循环需要多待命1次。
2.2.1、为了方便起见，在这种执行时仍然存在下一轮循环，即tnum[0]>0的情况下，后面待执行的任务的次数不管是正数，还是0或负数。都统一减1，并将执行结果加1
2.2.2、如果执行时不在下一轮循环，即tnum[0]=0的情况下，只有当后面待执行的任务的次数是正数，才减1，并将执行结果加1。因为0或负数代表没有任务要执行，这是以前执行待命的一种标记。
2.3、为了能保证2.2.1和2.2.3能正常操作，我们必须保证初始len(tnum)>=n+1
### 代码

```python3
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        rst,tnum=0,[]
        #1、梳理出需要执行的任务以及每个任务对应的次数；
        for i in set(tasks):tnum.append(tasks.count(i))
        #2.3、为了能保证2.2.1和2.2.3能正常操作，我们必须保证初始len(tnum)>=n+1
        if n+1>len(tnum):tnum.extend((n+1-len(tnum))*[0])
        
        #2、每次对需要执行的任务按需要执行的次数排序，优先执行次数多的，直到所有任务执行完。
        #2.1、执行一次，对应次数减1。
        tnum.sort(reverse=True)
        while tnum[0]>0:
            for i in range(n+1):
                #2.2.1、为了方便起见，在这种执行时仍然存在下一轮循环，即tnum[0]>0的情况下，后面待执行的任务的次数不管是正数，还是0或负数。都统一减1，并将执行结果加1    
                if tnum[0]>0: 
                    tnum[i]=tnum[i]-1
                    rst=rst+1
                #2.2.2、如果执行时不在下一轮循环，即tnum[0]=0的情况下，只有当后面待执行的任务的次数是正数，才减1，并将执行结果加1。因为0或负数代表没有任务要执行，这是以前执行待命的一种标记。
                elif tnum[0]==0 and tnum[i]>0:
                    tnum[i]=tnum[i]-1
                    rst=rst+1
            tnum.sort(reverse=True)
        return rst
```
### 解题思路
# **方法2：栈+待执行任务种类少于n场景优化 **
执行用时 :540 ms, 在所有 Python3 提交中击败了45.89%的用户
内存消耗 :13.7 MB, 在所有 Python3 提交中击败了28.90%的用户
**在方法1的基础上，做了两点优化：**
1、发现实际上n+1>=len(tnum)时，所需要执行的时间，取决于队列中最多需要执行的次数tnum[0].因为前tnum[0]-1轮每次耗时（n+1），最后一轮需要执行的个数由队列中有多少个数和tnum[0]一样大。
2、需要实现优化1的话，len(tnum)必须实时反映队列中正数的个数，但队列中出现1时要及时提出，同时执行次数+1。类似于栈的实现
### 代码

```python3
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        rst,tnum=0,[]
        for i in set(tasks):tnum.append(tasks.count(i))
        tnum.sort(reverse=True)
        while tnum[0]>0:
            #1、发现实际上n+1>=len(tnum)时，所需要执行的时间，取决于队列中最多需要执行的次数tnum[0].因为前tnum[0]-1轮每次耗时（n+1），最后一轮需要执行的个数由队列中有多少个数和tnum[0]一样大。
            if n+1>=len(tnum):return rst+(n+1)*(tnum[0]-1)+tnum.count(tnum[0])
            #2、需要实现优化1的话，len(tnum)必须实时反映队列中正数的个数，但队列中出现1时要及时提出，同时执行次数+1。类似于栈的实现
            if n+1<len(tnum):
                t=i=0
                while t<n+1 :
                    t=t+1
                    if tnum[i]==1:tnum.pop(i)
                    else:
                        tnum[i]=tnum[i]-1  
                        i=i+1
                rst=rst+n+1        
            tnum.sort(reverse=True)
        return rst
```
解题思路end