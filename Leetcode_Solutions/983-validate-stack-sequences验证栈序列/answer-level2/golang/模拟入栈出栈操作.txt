```
func validateStackSequences(pushed []int, popped []int) bool {
    if len(popped)!=len(pushed){
        return false
    }
    l := len(pushed)
    var stack = make([]int,0)
    var i,j int
    for i<l||j<l{
        //如果pushed已经push完毕，但是此时出栈第一个元素都不对，则必定错误
        if i==l&&stack[len(stack)-1]!=popped[j]{
            return false
        }
        //如果栈空，或者栈顶元素不是要pop的元素，将pushed元素入栈
        if len(stack)==0||stack[len(stack)-1]!=popped[j]{
            stack = append(stack,pushed[i])
            i++
        }else{
            stack = stack[:len(stack)-1]
            j++
        }
    }
    return true
}
```
