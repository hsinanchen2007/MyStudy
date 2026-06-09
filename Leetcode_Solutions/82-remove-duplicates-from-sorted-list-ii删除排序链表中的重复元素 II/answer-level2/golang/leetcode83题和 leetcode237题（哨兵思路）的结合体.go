### 解题思路

![image.png](https://pic.leetcode-cn.com/e459cd836218c7d1f66a00d8a42313e279c929c7da40b01848c8330abac12b27-image.png)


leetcode83题和 leetcode237题（哨兵思路）的结合，做完这两道题，再做这个题思路就会好很多

具体思路：结合之前的83题，先把链表处理成排序无重复的，并存储重复节点，之后再过滤一遍链表并剔除重复的元素
### 代码

```golang
/**
* Definition for singly-linked list.
* type ListNode struct {
*     Val int
*     Next *ListNode
* }
*/
func deleteDuplicates(head *ListNode) *ListNode {
    if head==nil || head.Next ==nil{
        return head
    }

    pre := head
    cur := head.Next

    nodeSet := make(map[int]int)

    for cur!=nil{
        if pre.Val == cur.Val{
            nodeSet[cur.Val] = 1 // 变量存储一定要在指针移动之前

            pre.Next = cur.Next
            cur = cur.Next
        }else{
            pre = cur
            cur = cur.Next
        }
    }


    //  移除链表中的节点
    sentinel := &ListNode{0,head}
    pre = sentinel
    cur = head
    for cur!=nil{
        if nodeSet[cur.Val]==1{ // delete this node
            pre.Next = cur.Next
            cur = cur.Next
        }else{
            pre = cur
            cur = cur.Next
        }
    }
    return sentinel.Next

}



/*
思路：结合之前的83题，先把链表处理成排序无重复的，并存储重复节点，之后再过滤一遍链表并剔除重复的元素
*/

```