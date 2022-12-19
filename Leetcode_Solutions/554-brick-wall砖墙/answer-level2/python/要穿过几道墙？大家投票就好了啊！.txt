### 解题思路
把wall的每一行里的每个数字n看成是一块高度是n的砖头。现在让每一行里的砖头竖着叠罗汉，每经历一个高度，就给这个高度投上一票！
遍历所有行，最后看看投票系统ruler的结果，谁的票最高，说明这个高度缝隙最多，答案自然就是：len(wall)-最高票数！
ps: 没人投票 就说明大家一般高嘛

### 代码

```python3
class Solution:
    def leastBricks(self, wall):
        ruler={}
        for row in wall:
            inc=0
            for i in range(len(row)-1):
                inc+=row[i]
                if inc in ruler:
                    ruler[inc]+=1  # makers in  inc tall position!
                else:
                    ruler[inc]=1
            #print('ruler row :',row,' is ',ruler)
        if ruler=={}:return len(wall)
        else:return len(wall)-max(ruler.values())
```