栈解法。
遍历一遍数组，时间复杂度O(n)。
初始化输出结果为全0：result = [0]*n。
如果下一个元素>当前元素，result[索引] = 1;
否则将当前元素压入栈，之后在遍历时判断当前元素是否大于栈顶元素。如果大于，则索引差值作为结果，栈顶元素pop，重复循环；否则不变化。

`class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        r = [0]*len(T)
        stack = []
        for i in range(len(T)):
            if stack:
                while (T[i] > stack[-1][1]):
                    r[stack[-1][0]] = i-stack[-1][0]
                    stack.pop()
                    if not stack:
                        break
            if i == len(T)-1:
                break
            if T[i+1] > T[i]:
                r[i] = 1
            else:
                stack.append( (i,T[i]) )
        return r
`