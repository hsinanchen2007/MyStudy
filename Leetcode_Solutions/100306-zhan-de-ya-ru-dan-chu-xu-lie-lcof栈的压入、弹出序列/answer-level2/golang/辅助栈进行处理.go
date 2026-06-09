### 解题思路
观察规律 要想知道是否是应有的序列
一开始我是考虑递归的 但后面发现直接写会方便一定
规律：
观察辅助栈遍历目前的入栈情况
1.栈顶有与目前poped当前元素相同的，出栈，进行下一个匹配
2.栈顶有与目前poped当前元素不相同的，pushed元素入栈
3.如果push已经遍历完了，而poped没有遍历完，那么久可以返回不正确了

### 代码

```golang
func validateStackSequences(pushed []int, popped []int) bool {
    if len(pushed) == 0{
        return true
    }
    return check(pushed,popped)
}

func check(pushed []int,popped []int)bool {
    j:=0
    helper:=make([]int,0)
    helper= append(helper,pushed[j])
    for i:=range popped{
        b:=popped[i]

        //不等于 就不断压栈
        for len(helper) == 0||b!=helper[len(helper)-1]{
            j++
            if j==len(pushed){
                return false
            }
            helper = append(helper,pushed[j])
        }
        //等于 就出栈
        if helper[len(helper)-1] != b{
            break
        }
        helper = helper[0:len(helper)-1]   
    }
    return true
}
```