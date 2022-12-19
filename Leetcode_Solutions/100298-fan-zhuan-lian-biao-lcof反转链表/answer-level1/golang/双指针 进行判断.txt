### 解题思路
假设链表 1 2 3 4 5 6 7 8 
指针cur:nil
指针prev:head
那么prev在遍历的时候 
t:=prev->next, prev->next = cur,cur = prev,prev = t 
将会让cur作为新表头 替换原来的cur 而且cur->next
同时prev后移 进行后移

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
// func reverseList(head *ListNode) *ListNode {

//     if head == nil||head.Next ==nil  {
//         return head
//     }

//     // 1 2 3 4head 5head-next 6newHead
//     newHead:=reverseList(head.Next)
//     //每次更改两个
//     head.Next.Next =  head
//     head.Next = nil

//     return newHead
// }


// func reverseList(head *ListNode) *ListNode {

//     if head == nil||head.Next ==nil  {
//         return head
//     }

//     // 1 2 3 4head 5head-next 6newHead
//     stack:=make([]*ListNode,0)
//     for head!=nil{
//         stack = append(stack,head)
//         head = head.Next
//     }

//     newHead:=&ListNode{}
//     prev:=newHead
//    // fmt.Println(len(stack))

//     for i:=len(stack)-1;i>=0;i--{
//         //fmt.Println(i)
//         prev.Next = stack[i]
//         prev = prev.Next
//     }
//     prev.Next = nil
//     return newHead.Next
// }


func reverseList(head *ListNode) *ListNode {

    if head == nil||head.Next ==nil  {
        return head
    }

   // 1  2 3 4 5 6
   // 2 1-> 3 2 1 
    //newHead:=&ListNode{}
    var pCur *ListNode
    pPrev:=head
    for pPrev!=nil{
        //双指针
        pTmp:= pPrev.Next
        pPrev.Next = pCur
        pCur = pPrev
        pPrev = pTmp
    }
   
    return pCur
}

```