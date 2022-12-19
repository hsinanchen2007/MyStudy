### 解题思路
见代码注释

### 代码

```golang
//栈存的节点
type stackNode struct {
    res []rune
    times int
}

func decodeString(s string) string {
    return string(decodeStringByRecur(s))
}

//递归做，很直观，容易想到
//时间复杂度O(N), 空间复杂度O(N)
func decodeStringByRecur(s string) []rune {
    rs := []rune(s) //转换成rune，兼容中文等多字节字符
    size := len(rs)
    //找到数字开始位置
    i:=0
    for i<size && (rs[i] < '0' || rs[i] > '9') {
        i++
    }
    //没有数字，直接返回
    if i == size {
        return rs
    }
    //此时i就是数字开始位置

    //j是第一个[开始位置
    j:=i+1

    for rs[j] != '[' { //可能有多个数字，一直遍历到[
        j++
    }

    //k是与[对应的]的位置
    k := j //注意不要j+1，不然后面k需要减1
    count := 1 //[的个数
    for count > 0 {
        k++
        if rs[k] == '[' {
            count++
        } else if rs[k] == ']'{
            count--
        }
    }

    num, _ := strconv.Atoi(string(rs[i:j])) //i~j-1都是数字、

    //分三段，再合并
    head := rs[:i]
    mid := repeat(decodeStringByRecur(string(rs[j+1:k])), num)
    tail := decodeStringByRecur(string(rs[k+1:]))

    return append(append(head, mid...), tail...)
}
  

//用栈做，一般这种成对括号的问题都可以联想到栈
//时间复杂度O(N), 空间复杂度O(N)
func decodeStringByStack(s string) []rune {
    stack := []*stackNode{}
    res := []rune{} //暂存区
    times := 0 //倍数

    for _, r := range s {
        if r ==  '[' { //把times和res入栈
                stack = append(stack, &stackNode{
                    res: res,
                    times: times,
                })
                res = []rune{}
                times = 0
        } else if r ==  ']' { //从栈顶拿一个出来，与res合并
                prev := stack[len(stack)-1]
                stack = stack[:len(stack)-1]
                tmp := repeat(res, prev.times)  //注意这里是将res重复，不是prev.res
                res = append(prev.res, tmp...) //prev.res在前哦
        } else if r >= '0' && r <= '9' { //数字，加起来
            num,_ := strconv.Atoi(string(r))
            times = 10 * times + num //记得乘以10
        } else { //字符
            res = append(res, r)
        }
    }

    return res
}

//重复
func repeat(s []rune, times int) []rune{
    res := []rune{}
    for i:=0; i<times; i++ {
        res = append(res, s...)
    }

    return res
}
```