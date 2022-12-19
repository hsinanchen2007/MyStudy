### 解题思路
回溯算法，回溯跳出条件就是左右括号都已经排完的情况。
括号成对存在，先有左括号再有右括号，所以只有右括号的数量小于左括号才进行右括号的添加。
最后如果右括号的数量等于0，表示右括号已经排完了，同时意味着左括号也排完了。

### 代码

```golang
func generateParenthesis(n int) []string {
    // 使用new方法开辟内存返回内存地址
    res := new([]string)

    backtracking(n, n, "",  res)

    return *res
}

func backtracking(left, right int, tmp string, res *[]string) {
    /* 
        回溯跳出条件，
        并不需要判断左括号是否用完，因为右括号生成的条件 right > left ，
        所以右括号用完了就意味着左括号必定用完了
    */ 
    if right == 0 {
        *res = append(*res, tmp)
        return
    }

    // 生成左括号
    if left > 0 {
        backtracking(left - 1, right, tmp + "(", res)
    }

    // 括号成对存在，有左括号才会有右括号
    if right > left {
        backtracking(left, right - 1, tmp + ")", res)
    }
}
```

### 运行结果
![image.png](https://pic.leetcode-cn.com/20d4b0434552e68fe441e8faed521d6704ee127da2a34791cf69fd3760877970-image.png)
看了一下内存耗费2.6MB的样例，感觉是用时间换内存，不过差距并不大，没有深究。
