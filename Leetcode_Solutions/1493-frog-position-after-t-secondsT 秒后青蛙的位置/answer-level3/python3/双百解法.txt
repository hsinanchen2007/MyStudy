### 解题思路
![Snipaste_2020-03-08_12-47-28.png](https://pic.leetcode-cn.com/509e014b95460d9450aadfd0c16342077d47c58ad9128b99c8679ec21d0769a1-Snipaste_2020-03-08_12-47-28.png)
比赛卡在第三题一直超时，最后一题没写 难受
用两个辅助数组记录时间和概率 bfs进行时间和概率的更新
用了一个小trick 如果是叶子节点 时间变为负数 
最后返回的时候需要满足时间恰好相等 
或者 
数组中记录的时间为负数（即可以停留）而且给出的时间大于记录时间的绝对值(时间足够走到叶子节点)

其他就都很直观了
### 代码

```python3
class Solution:
    def frogPosition(self, n: int, edges: List[List[int]], t: int, target: int) -> float:
        if n ==1:
            return 1
        gl = [0 for _ in range(n)]
        gl[0]=1
        time = [0 for _ in range(n)]
        helper = []
        helper.append(1)
        while helper:

            for _ in range(len(helper)):
                dangqian = helper.pop(0)
                zong = 0
                ttmp = []
                for i in edges:
                    if dangqian in i:
                        tmp = i[0]-1 if dangqian == i[1] else i[1]-1
                        #print(tmp)
                        if gl[tmp] == 0:
                            zong = zong+1
                            ttmp.append(tmp)
                if zong == 0:
                    time[dangqian-1] = -1 *time[dangqian-1] 
                    
                else:
                    for ii in ttmp:
                        gl[ii] = (1/zong)*gl[dangqian-1]
                        time[ii] = 1+time[dangqian-1]
                        helper.append(ii+1)

                        

        print(time)
        print(gl)
        if t == abs(time[target-1]) or (t > abs(time[target-1]) and time[target-1]<0) :
            return  gl[target-1]
        else:
            return 0
```