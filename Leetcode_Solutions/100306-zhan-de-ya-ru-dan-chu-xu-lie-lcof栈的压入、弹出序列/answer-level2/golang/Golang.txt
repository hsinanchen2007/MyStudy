### 代码

```golang
func validateStackSequences(pushed []int, popped []int) bool {
    if len(pushed)==0{
        return true
    }
    stack,p1,p2:=[]int{},0,0
    for{
        if pushed[p1]==popped[0]{
            p1++
            p2++
            break
        }
        stack=append(stack,pushed[p1])
        p1++
    }
    for{
        if p2==len(popped){
            return true
        }else if len(stack)>0&&stack[len(stack)-1]==popped[p2]{
            stack=stack[0:len(stack)-1]
            p2++
        }else if p1<len(pushed){
            stack=append(stack,pushed[p1])
            p1++
        }else{
            return false
        }
    }
}
```