func removeDuplicates(S string) string {
    stack := make([]byte, 1)
    for _, v := range S{
        if byte(v) != stack[len(stack)-1]{//判断是否重复
            stack = append(stack, byte(v))//push
        }else{
            stack = stack[:len(stack)-1]//pop
        }
    }
    return string(stack[1:len(stack)])
}