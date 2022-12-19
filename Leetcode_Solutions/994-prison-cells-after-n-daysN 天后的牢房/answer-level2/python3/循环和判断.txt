# 成绩（2019.05.18）
执行用时 : 60 ms, 在Prison Cells After N Days的Python3提交中击败了93.65% 的用户

内存消耗 : 13.1 MB, 在Prison Cells After N Days的Python3提交中击败了82.05% 的用户


# 思路
套用评论区一位老哥的话，`n`个cell一共有$2^n$种可能组合，所以当`N`大于这个值时，必定存在循环。

所以我们的任务就变成了两种情况

1. 在第`N`天之前，循环没有出现

2. 在第`N`天之前，循环出现

对于第一种情况，很好说，直接返回即可

对于第二种情况又有两种小情况：

1. 第N天和第0天情况一样

2. 第N天和第１天情况一样

对于这时的第一种情况，设周期为t，我们需要返回的是第`Ｎ%t `天的情况（Python下标从0开始，所以应是`Ｎ%t-1`）

对于这时的第二种情况，设周期为t，我们需要返回的是第`Ｎ%t +1`天的请况（Python下标从0开始，所以应是`Ｎ%t `）


```Python
class Solution:
    def prisonAfterNDays(self, cells: List[int], N: int) -> List[int]:
        i, l = 0, len(cells)
        if l == 1:
            return [0]
        elif l == 2:
            return [0, 0]
        else:
            i, cur, history = 0, [0]*l, [cells] 
            while (i < N) and (cur not in history[:-1]):
                i += 1
                for j in range(1, l-1):
                    cur[j] = int(history[-1][j-1] == history[-1][j+1])
                history.append(cur.copy())
            # print(history, i, N)  these three lines are for debugging
            # print(N%(i-1), N, i) 
            # print(history[0] == history[-1])
            if (i == N) or (i == 1):
                return history[-1]
            elif history[0] == history[-1]:
                return history[N%i]
            else: # history[1] == history[-1] and i = t+1
                if i == 2:
                    return history[1]
                elif N%(i-1): 
                    return history[N%(i-1)]
                else:
                    return history[-2] 
```