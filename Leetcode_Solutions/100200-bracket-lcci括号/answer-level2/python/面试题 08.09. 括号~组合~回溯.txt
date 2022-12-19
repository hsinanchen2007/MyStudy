### 解题思路
回溯算法的第一步就是如何把问题转换成树形图
需要自己手动模拟一遍，如下图

![image.png](https://pic.leetcode-cn.com/71fd6bfd9ec0167ec466657b876ed206d0c666bf27a30b8a2dca83448c65a030-image.png)

【我们用左右括号的数量来进行回溯】
注意要剪枝：如果你不剪枝，对最后生成的括号判断是否合法即可！

### 代码

```python3
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        path = ''
        origion_pair = [n, n]
        def backtrack(pair, path):
            ## 终止条件
            if pair[0] == pair[1] == 1:
                res.append(path)
                return 
            # 每个节点都会面临两种选择，要么增加“(”, 要么增加“)”
            left, right = pair[0], pair[1]

            if left <= right: # 剪枝
                # 下面两个判断条件哪个先随便
                if right > 0:
                    backtrack([left, right - 1], path + ')')
                if left > 0:
                    backtrack([left - 1, right], path + '(')
                

        backtrack(origion_pair, path)
        return res

```