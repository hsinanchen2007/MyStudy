### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def generateParenthesis(self, n):
        ans=[]

        def help(temp,num_left,num_right, choose):

            if num_left==num_right and num_right+num_left==2*n:
                ans.append(temp)
                return
            if num_left<num_right or  num_right+num_left>2*n:
                return

            for i in choose:
                if i=='(':
                    help(temp+i,num_left+1,num_right,choose)
                else:
                    help(temp+i,num_left,num_right+1,choose)


        help("",0,0,['(',')'])
        return ans
```