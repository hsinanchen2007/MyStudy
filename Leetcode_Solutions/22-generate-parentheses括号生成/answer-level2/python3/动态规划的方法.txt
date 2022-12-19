### 解题思路
主要是利用动态规划进行思考，关键是要弄清楚从i-1个括号到i个括号的转变方式：这相当于在i-1个括号的基础上添加一个新的括号，前p个添加到这个括号里，后面的q个放到右边，其中q+p=i-1。


### 代码

```python3
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        if n==0:
            return []
        all_l = []
        all_l.append([None])
        all_l.append(["()"])
        for i in range(2,n+1):
            l = []
            for p in range(i):
                left_list = all_l[p]
                right_list = all_l[i-1-p]
                for left_p in left_list:
                    for right_p in right_list:
                        if left_p == None:
                            left_p = ""
                        if right_p == None:
                            right_p = ""
                        now_p = "(" + left_p + ")" + right_p
                        l.append(now_p)
            all_l.append(l)
        return all_l[n]
```