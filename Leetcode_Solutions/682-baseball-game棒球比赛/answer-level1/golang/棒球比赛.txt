func calPoints(ops []string) int {
    s, top := 0, 0//s是总分     top是栈顶的下标
    stack := make([]int, 1000)//模拟栈
    for _, v := range ops{
        if v == "+"{
            stack[top] = stack[top-2] + stack[top-1]
            top++
        }else if v == "D"{
            stack[top] = stack[top-1] * 2
            top++
        }else if v == "C"{
            stack[top-1] = 0
            top--
        }else{//数字则变为int型加到栈顶
            score, _ := strconv.Atoi(v)
            stack[top] = score
            top ++
        }
    }
    for i:=0; i<top; i++{//把每轮的分数相加
        s += stack[i]
    }
    return s
}
写的一般，请多多指教