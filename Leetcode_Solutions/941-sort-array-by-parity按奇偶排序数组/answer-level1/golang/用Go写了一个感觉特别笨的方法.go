新建两个数组分别追加遍历来的偶数和基数，编历结束后，在把两个数组拼起来.....

func sortArrayByParity(A []int) []int {
```
    var s []int
    var a []int
    for i:=0;i<len(A);i++{
        if A[i]%2 == 0{
            s = append(s, A[i])
        }else{
            a = append(a, A[i]) 
        }
    }
    return  append(s,a...)
```
}

之前尝试用头尾遍历的方式，然后反转数组，但是发现如果变动测试用例顺序就不成立了