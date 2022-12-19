```
class Solution:
    def totalNQueens(self, n: int) -> int:
        def set1(li):
            for x in range(len(li)-1):                                        #3.判断皇后在该行的位置li[-1]是否会出现冲突，因为只需要和前面几行的比较，判断条件较简单。
                if li[-1] == li[x] or len(li)-x-1 == abs(li[-1]-li[x]):return #4.有冲突则停止，没有则说明皇后可以放在该位置（把每行可以放置的位置筛选出来）
            if len(li)==n:return ans.append(1)                                #5.皇后位置全部确定时，让结果列表长度加一，否则继续确定下一行皇后位置
            for j in range(n):set1(li+[j])                                    #6.继续确定下一行所有可放置的位置
        ans = []                                                              #1.定义一个全局列表，用以保存结果（为什么我用number类型的全局变量不行？求大神告知）
        for j in range(n):set1([j])#2.set1每次确定一行的皇后位置，这里是第一行。传递的数组记录了皇后的位置信息，比如数组[1,3]表示第0行皇后在1号位，第1行在3号位
        return len(ans)
```
