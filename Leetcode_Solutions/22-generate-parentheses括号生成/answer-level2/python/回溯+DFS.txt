这道题采用回溯算法。

**解空间/问题状态**：

我们把左括号对应为0，把右括号对应为1，则我们的解空间为：
$$
(x_1,x_2, \dots, x_n),x_i \in \{0,1\}
$$
所以当搜索到第$i$层时，前$i-1$层的值都已经确定，构成一个**问题状态**。

**状态**

状态指的是我们需要在每次递归中传入的状态参数。解状态也可以作为参数的一部分传入，但由于列表传参传的是引用，在子函数里对状态的更改可能影响到父函数，所以改用全局变量来进行替代。也可以设定状态不可变，在每次更改状态时将其赋予一个新的变量即可。

**限界函数**：

- 在任何时刻，左括号个数不能超过$n$，右括号个数也不能超过$n$；
- 在任何时刻，右括号个数不能超过左括号个数。

整道题目的代码如下：

```python
class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        res = []

        if n == 0:
            return ['']

        # problem state/solution space
        cur_solution = [False for _ in range(2*n)]  # False: (, True: )

        # bound function
        def bound(s, cur_left, cur_right):
            if s is False:
                if cur_left + 1 > n:
                    return False
            else:
                if cur_right + 1 > cur_left:
                    return False
            return True

        def backtraking(k, cur_left, cur_right):
            for s in [False, True]:
                if bound(s, cur_left, cur_right):
                    # update state vector
                    cur_solution[k] = s

                    if k == 2*n - 1:  # is a solution
                        res_solution = cur_solution[:]
                        res.append(res_solution)
                    if k < 2*n - 1:
                        backtraking(k+1, cur_left if s else cur_left +
                                    1, cur_right + 1 if s else cur_right)

        backtraking(0, 0, 0)

        for i in range(len(res)):
            for j in range(len(res[i])):
                if res[i][j]:
                    res[i][j] = ')'
                else:
                    res[i][j] = '('
            res[i] = "".join(res[i])

        return res
```

