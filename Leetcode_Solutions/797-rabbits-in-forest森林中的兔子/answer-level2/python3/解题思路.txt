```
class Solution:
    def numRabbits(self, answers):
        # 示例[1,0,1,0,0]
        # 遍历[1,0,1,0,0] 构建出这样的数组res1=[[1,2],[0,1],[0,1],[0,1]]
        # res1数组记录了说1的兔子有几只，最多为1+1只，说0的兔子最多有1只
        # 最后统计一下 res1数组
        res1 = [[answers[0],1]]
        for answer in answers[1:]:
            for i in range(len(res1)):
                # 满足条件就记录一下
                if answer == res1[i][0] and res1[i][1] <= res1[i][0]:
                    res1[i][1] += 1
                    break
                # 如果遍历完整个数组都没有满足上面的条件，则为res1数组添加新的记录。
                if i == len(res1)-1:
                    res1.append([answer,1])
                
        result = 0
        for res in res1:
            result += (res[0]+1)
        return result
```
