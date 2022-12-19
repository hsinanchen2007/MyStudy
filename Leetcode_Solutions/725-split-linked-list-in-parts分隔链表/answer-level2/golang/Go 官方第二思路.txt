### 解题思路
先遍得到历链表长度，计算分成k块每块的大小，和余数
再次遍历，若余数大于0块大小加一，余数减一
切割成块大小的数组

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func splitListToParts(root *ListNode, k int) []*ListNode {
    cur := root
    n := 0
    for cur != nil {
        n ++
        cur = cur.Next
    }
    mod := n%k
    size := n/k
    cur = root
    ret := make ([]*ListNode,k)
    for i:=0 ; cur != nil && i < k; i++ {
        ret [i] = cur
        curSize :=0
        if mod > 0 {
            mod --
            curSize = size +1 
        } else {
            curSize = size
        }
        for j :=0 ; j < curSize -1 ; j++ {
            cur = cur.Next
        }
       cur, cur.Next = cur.Next, nil
    }
    return ret
}
```