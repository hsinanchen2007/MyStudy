```
func reversePrint(head *ListNode) []int {
    var res = make([]int,0,10)
    for{
        if head != nil{
            res = append(res,head.Val)
            head = head.Next
        }else{
            break
        }
    }
    lenth := len(res)
    var tmp int
    for i:=0;i<lenth/2;i++{
        tmp = res[i]
        res[i] = res[lenth-i-1]
        res[lenth-i-1] = tmp
    }
    return res
}
```
