执行用时 :4 ms, 在所有 Go 提交中击败了57.83%的用户
内存消耗 :2.2 MB, 在所有 Go 提交中击败了27.46%的用户

该解法符合“一趟扫描”的进阶要求，只需一次循环即可得出答案，即时间复杂度为O(n)，而且理解起来比官方题解简单很多。

**思路：**
1.通过循环将所有ListNode推入数组中，这样数组的索引就表示链表的正向顺序，同时也能变相将单向链表变成双向链表，以便删除节点时能查到它的父子节点是什么并将它们连上。
链表1->2->3->4->5，在数组中表示为[1,2,3,4,5]，很明显数组中任意索引-1是链表中的父节点，索引+1是链表中的子节点。
2.d当循环到ListNode.Next为空时，意味着链表到头了，数组构造完毕，这时就能确定链表的长度（即数组长度）。
3.因此就可以从数组中找到倒数第N个节点对应的ListNode（数组长度-N即为正数位置），然后通过数组索引加减1查询到它的父子节点，把它的父节点的Next指向它的子节点就可以了。


``` golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
    // 保存链表的数组
    var arr []*ListNode
    // 当前节点指向根节点
    curNode := head
    for {
        // 将节点推入数组，此时数组的索引表示当前节点在链表中的位置
        arr = append(arr, curNode)
        // 如果当前节点有子节点，进行标记，以便下一次for循环推入arr
        if curNode.Next != nil {
            curNode = curNode.Next 
        // 如果当前节点没有子节点，那么说明全部节点保存完毕，开始查找倒数节点
        } else {  
            // 统计该链表总节点数
            total := len(arr)
            // 正向顺序 = 总数 - n，如倒数第1个节点的正向顺序为为total - 1，正好对应arr中的最后一项
            front := total - n
            // 需要处理一些是否存在父子节点的越界问题
            // 如果链表只有一项，意味着既没有父节点，也没有子节点，把它自己删了这个链表就是空链表了，那么直接返回空即可。
            if total == 1 {
                head = nil
            // 如果要删除的是第一个节点，那么它是没有父节点的，所以把head指向第二个节点返回就行了。
            } else if front == 0 {
                head = arr[1]
            // 如果要删除的节点即有父节点又有子节点，那么把它的父节点和它的子节点连上即可
            } else {
                arr[front - 1].Next = arr[front].Next
                // arr[front - 1].Next = arr[front + 1] 亦可
            }
            break
        }
    }
    return head
}

粗体
```
