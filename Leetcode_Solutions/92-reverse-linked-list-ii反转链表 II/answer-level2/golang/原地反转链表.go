思路：cur指针始终指向初始的第m个节点，tmp为其下一个节点，每次讲tmp往前移动，注意边界条件处理。
建立头结点，防止m为原列表的第一个节点情况的出现。

```
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
// 执行本地反转，需要新建一个空头节点，避免m为1时出错
//  1 2 3 4 5 -> 1 3 2 4 5 -> 1 4 3 2 5 
func reverseBetween(head *ListNode, m int, n int) *ListNode {
    // 边界处理
    if head == nil || m > n {
        return nil
    }
    
    //申请节点指向头节点
    fake := &ListNode{}
    fake.Next = head
    prve := fake // prev始终指向m个节点前一个节点，当m为1时。prev为自建的指向头节点的新节点
    
   //走到将要翻转节点的前一个节点 prev，始终不变
    for i := 0; i < m-1; i++ {
        prve = prve.Next
    }

    //cur 始终指向初始的第m个节点，如1，也就是将要翻转的节点
    cur := prve.Next
    // 从右开始，每趟交换两个节点
    for i := m; i < n; i++ {
        tmp := cur.Next            //保存要反转节点的下一个节点
        cur.Next = tmp.Next    //当前节点指向 要放转节点的next节点，最终指向第m个节点的next
        tmp.Next = prve.Next  //第n个节点的next指向前一个节点
        prve.Next = tmp           // 第m个节点指向后面一个节点
    }
    
    return fake.Next    

}
```