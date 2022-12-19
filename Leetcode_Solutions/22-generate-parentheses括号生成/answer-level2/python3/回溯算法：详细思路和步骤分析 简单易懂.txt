解题思路：
1、n表示生成括号的对数，因此一共有2n个括号。
2、一共有效的组合中，左括号数n_left和右括号数n_left都为n。
3、在一对括号'()'中，左括号一定要在有括号前面，因此在递归的时候n_left不能少于n_left

解题方法：回溯算法
a.判断是否满足一共有效的组合：n_left + n_right == 2*n
b.遍历所有的情况：'（）'
c.将遍历的括号加入到solution的尾部
d.剪枝判断：对于不满足解题思路中2&3条件的需要进行剪枝
e.递归：进入下一层的括号生成中
f.回溯：执行到这一步，表明已经生成了一个有效的组合，因此，solution需要弹出尾部一个元素，同时括号数n_left和n_left也要进行更新。

![1.png](https://pic.leetcode-cn.com/19dca47c80e1d49c9b21cc213956ca53a5f737a050e9cb1df6f5d6a7468dbad7-1.png)



```
class Solution:
    def generateParenthesis(self, n):
        # 边界条件判断
        if n == 0:
            return []
        # 返回列表
        res = []

        def backtracking(n_left, n_right, solution):
            # 判断目标满足条件
            if n_left + n_right == 2*n:
                res.append(''.join(solution))

            # 遍历所有情况
            for k in '()':
                solution.append(k)  # 加入一个括号
                if k == '(':
                    n_left += 1
                else:
                    n_right += 1
                # 剪枝
                if n_left < n_right:
                    solution.pop()
                    n_right -= 1
                    continue
                elif n_left > n:
                    solution.pop()
                    n_left -= 1
                    continue

                # 递归
                backtracking(n_left, n_right, solution)

                # 回溯
                k1 = solution.pop()
                if k1 == '(':
                    n_left -= 1
                else:
                    n_right -= 1

        backtracking(0, 0, [])
        return res
```