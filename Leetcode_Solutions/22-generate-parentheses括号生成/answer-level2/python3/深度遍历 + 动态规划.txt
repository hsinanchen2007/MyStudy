### 解题思路1
将左右括号都比喻成两个库存，每次从库存调用所需，并根据情况来决定是否从库存调用。
### 代码

```python3
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        #库存
        ls = ['('] * n
        rs = [')'] * n
        #记录结果
        total = set()

        #recursion函数内部可以访问到这两个变量，因为形成闭包
        choose_left = True
        choose_right = False
        
        def recursion(action, noter, lefts, rights, totalset, sofar):
            '''
                action：代表加左括号还是有括号，choose_left代表左，choose_right代表右
                noter：记录目前左右括号的情况，添加左括号noter+1，添加右括号noter-1，防止右括号比左括号多
                lefts：左括号库存
                rights：右括号库存
                totalset：记录结果，用set结构防止重复
                sofar：记录目前积攒的字符串
            '''
            if len(lefts) == 0:
                if len(rights) == 0:
                    #库存都用完，代表以及积攒了一个结果，添加到结果集中
                    totalset.add(sofar)
                    return
                if action == choose_left:
                    #左括号库存用完就不能再添加左括号了
                    return
            #拷贝，分别传给二叉树的两个分支，防止互相影响
            temp_lefts = lefts[:]
            temp_rights = rights[:]
            if action == choose_left:
                sofar += temp_lefts.pop(0)
                noter += 1
            elif action == choose_right:
                if noter == 0:
                    #现有的左括号与右括号数量对等的情况下不能再添加右括号
                    return
                sofar += temp_rights.pop(0)
                noter -= 1
            #二叉树深度优先递归
            recursion(choose_left, noter, temp_lefts, temp_rights, totalset, sofar)
            recursion(choose_right, noter, temp_lefts, temp_rights, totalset, sofar)
        recursion(choose_left, 0, ls, rs, total, '')
        return list(total)
```

### 解题思路2
动态规划
参考：[精选题解](https://leetcode-cn.com/problems/generate-parentheses/solution/zui-jian-dan-yi-dong-de-dong-tai-gui-hua-bu-lun-da/)

### 代码

```python3
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        dp = [['']] + [[] for i in range(n)]
        for i in range(1, n+1):
            for j in range(i):
                for k in range(len(dp[j])):
                    for p in range(len(dp[i-j-1])):
                        dp[i].append('('+ dp[j][k] +')'+ dp[i-j-1][p])
        return dp[n]