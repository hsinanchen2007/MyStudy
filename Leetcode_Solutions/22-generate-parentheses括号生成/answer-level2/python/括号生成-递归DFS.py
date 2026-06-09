### 解题思路
**（1）文字思路**
**递归DFS**：访问节点，将该节点标记为已访问，同时对根节点的邻接结点中未访问过的结点递归调用DFS
**非递归DFS**：取栈顶元素（不出栈），找到栈顶元素的一个未被访问过的邻接结点（注意是一个就行，不需要所有邻接结点入栈，与BFS不同），访问、标记为已访问并入栈，直到栈顶元素的所有邻接结点都被访问过，栈顶元素出栈，直到栈空
此题使用前者
**（2）搜索图示**
![image.png](https://pic.leetcode-cn.com/c4898963a0cca81921b872df93b28d49e81c35e7a438dc902232f72055d60e54-image.png)
其中，左分支都是添加左括号，右分支都是添加右括号，括号底数字为左右括号剩余量
**（3）注意tips**
代码后面的判断条件都是 if，而不是 elif
满足两个条件的任意一个就可以继续向下搜索
而不是同时只能满足其中的一个

### 代码

```python3
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        queue = []
        ans = ''
        def DFS(ans,lnum,rnum):
            if lnum == 0 and rnum == 0:
                queue.append(ans)
                return
            if rnum < lnum:
                return
            if lnum > 0:
                DFS(ans+'(', lnum - 1, rnum)
            if rnum > lnum:
                DFS(ans+')', lnum, rnum - 1)
        DFS(ans,n,n)
        return queue
        


```