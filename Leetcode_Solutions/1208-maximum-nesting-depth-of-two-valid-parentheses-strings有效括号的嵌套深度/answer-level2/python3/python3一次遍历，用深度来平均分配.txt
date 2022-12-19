### 解题思路
此处撰写解题思路
要两个子序列的深度均衡，所以我们尽量深度平均分配。
所以一层第0组，一层第1组，一层一层来，最后最多深度相差1
需要记录一下深度
### 代码

```python3
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        deep = 0                    #嵌套深度
        ans=[]
        for i in seq:
            if i=='(':
                deep +=1            #左括号，深度++
                if deep%2==1:       #深度为奇数，归入第0组
                    ans.append(0)
                else:               #否则归入第1组
                    ans.append(1)
            else:                   #右括号，深度--
                deep -=1
                if deep%2==0:       #深度为偶数，归入第0组，注意和上面的情况匹配
                    ans.append(0)
                else:               #否则归入第1组
                    ans.append(1)
        return ans                  #可以用（）和（（））练习一下理解算法
```