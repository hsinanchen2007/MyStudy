### 解题思路
1. 遍历
2. 切片a存放所有节点指针
3. 索引进行转换 index = len(a)-k
4. 返回 a[index]
### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getKthFromEnd(head *ListNode, k int) *ListNode {
    // 存储所有节点指针
    var a []*ListNode
    // 空链
    if head == nil{
        return nil
    }

    a = append(a,head)
    // 链表遍历
    node := head.Next
    for node !=nil{
        a = append(a,node)
        node = node.Next
    }
    // 索引转换 
    index := len(a) - k
    return a[index]


}
```