`生成` 想到回溯法, 回溯法的关键在于
1.  何时结束递归?
2. 将某个回溯结果保存在最终结果集中的约束是什么?
我们可以利用`输入值n`与 `每个回溯结果长度`的关系 找到递归的终止条件`2*n == len`,同时我们知道括号的性质是第一个一定是左括号,还有就是左右括号应该是相等的,等于n,即`left < n`那么约束是什么呢? 左括号一定是第一个那么在最终二者相等之前一定有`left < right`.
通过这两个约束就可以使得回溯的结果符合括号的嵌套定义。

```
func generateParenthesis(n int) []string {
    return loadParenthesis(0,0,n,make([]string,0),"")
}

func loadParenthesis(l,r,max int,res []string,tmp string)[]string{
    if len(tmp) == 2 * max{
        res = append(res,tmp)
        return res
    }
    
    if l < max{
        res = loadParenthesis(l+1,r,max,res,tmp+"(")
    }
    if r < l{
        res = loadParenthesis(l,r+1,max,res,tmp+")")
    }
    return res
}
```