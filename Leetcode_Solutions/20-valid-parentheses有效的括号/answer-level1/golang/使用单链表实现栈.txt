### 解题思路
执行用时 : 0 ms, 在所有 Go 提交中击败了100.00%的用户  内存消耗 : 2 MB, 在所有 Go 提交中击败了54.46%的用户

### 代码

```golang
// 使用单链表实现栈
func isValid(s string) bool {
    type Node struct{
    Val byte
    Next *Node
    }

    head:=&Node{}
    for i,j:=range s {
        if (s[i]!=head.Val)&&(s[i]-head.Val<3){
            head=head.Next
        }else{
            head=&Node{
                Val:byte(j),
                Next: head,
            }
        }   
    }

    if head.Next==nil{
        return true
    }else{
        return false
    }
}



```