### 解题思路
1.**存储符号"&" "|" "^" 的计算方式**存储为dict(dict(list))=>Symbol[sym][res]=(leftRes,rightRes)
2.**递归基**:判断长度为1的表达式
3.**遍历**整个字符串**找到所有的symbols**，
若遇到Symbol，取出使式子结果为result的左结果和右结果`for leftRes,rightRes in Symbol[expression[i]][result]`
4.**递归**：返回总的表达式在**所有**symbols处的结果：
`count+=DFS(expression[:i],leftRes,memorydict)*DFS(expression[i+1:],rightRes,memorydict)`
总的表达式在**每一**symbol处的结果为**左右表达式各自结果相乘（组合数）**
5.通过记忆化减少重复递归中间计算，（不通过记忆化会超时）
`memorydict[(expression,result)]=count`
`if (expression,result) in memorydict:return memorydict[(expression,result)]`

### 代码

```python3
class Solution:
    def countEval(self, s: str, result: int) -> int:
        #Symbol: & | ^ 的计算方式存储为dict
        Symbol=dict()#{'&':andSymRes,'|':orSymRes,'^':xorSymRes}
        andSymRes=dict()#{True:judgeList,False:judgeList}
        orSymRes=dict()#{True:judgeList,False:judgeList}
        xorSymRes=dict()#{True:judgeList,False:judgeList}
        andSymRes[True] =[(True,True)]
        andSymRes[False]=[(True,False),(False,True),(False,False)]
        orSymRes[True]  =[(True,False),(False,True),(True,True)]
        orSymRes[False] =[(False,False)]
        xorSymRes[True] =[(True,False),(False,True)]
        xorSymRes[False]=[(True,True),(False,False)]
        Symbol={"&":andSymRes,"|":orSymRes,"^":xorSymRes}#Symbol[sym][res]=(leftRes,rightRes)
        #DFS：
        def DFS(expression,result,memorydict):#返回表达式为result的加括号的种类
            if (expression,result) in memorydict:return memorydict[(expression,result)]#记忆化防止重复计算
            if len(expression)==1:#递归基
                val=int(expression)#长度为1的表达式应为数字
                return 1 if val==result else 0
            count=0
            #递归计算左右子式
            for i in range(len(expression)):#遍历整个字符串找到所有的symbols
                if expression[i] in Symbol:#若遇到Symbol
                    for leftRes,rightRes in Symbol[expression[i]][result]:#取出使得式子结果为result的左结果和右结果
                        #总的表达式在该symbol处的的结果为左右表达式各自结果相乘（组合数）==>要求出所有的symbol处的结果
                        count+=DFS(expression[:i],leftRes,memorydict)*DFS(expression[i+1:],rightRes,memorydict)
            memorydict[(expression,result)]=count#记忆化防止重复计算
            return count
        return DFS(s,result,{})








```