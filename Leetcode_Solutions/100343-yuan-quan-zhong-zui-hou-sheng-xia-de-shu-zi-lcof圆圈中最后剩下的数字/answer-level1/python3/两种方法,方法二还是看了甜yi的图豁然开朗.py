### 解题思路
方法一:不断删除,取余,直到最后一个元素
方法二:数学方式反推,最后一轮剩余的最后一个数字下标一定是0,那么倒数第二轮数字下标就是(0+3)%2=1,这个2是倒数第二轮的数组长度,以此类推,直到这个数组长度为n时,表示推到了初始第一次这个值的位置下标 
#公式(index+m)%len(list)=index

### 代码
```
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        lists=[i for i in range(n)]
        k=0 #进行移动的指针
        m=m-1
        while len(lists)>1:
            n=len(lists)
            k+=m #每次向前m步
            if k>n-1: #如果K大于步长,就取余
                k=k%(n)
            lists.pop(k)
        return lists[0]
```

```
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        lists=2
        index=0
        while lists<=n:
            index=(index+m)%lists
            lists+=1
        return index
```