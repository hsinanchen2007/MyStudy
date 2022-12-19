![WX20200215-203223.png](https://pic.leetcode-cn.com/6995837cd1f80a5d68587b00e39b046a1c391496482033962c42e6a9b236840f-WX20200215-203223.png)


### 解题思路
解题需要三部
1. 第一次遍历n/2 slow/fast指针 前1/2部分的值保存到stack中
2. fast != nil 链表长度为奇数, 所以slow = slow.Next
3. 第二次遍历n/2 和stack中的值进行比较

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func isPalindrome(head *ListNode) bool {
    if head == nil || head.Next == nil {
        return true
    }
    slow,fast := head,head
    //golang slice 作为stack
    stack := []int{}

    //寻找中间链表
    for fast != nil && fast.Next != nil{
        //stack push
        stack = append(stack,slow.Val)

        slow = slow.Next
        fast = fast.Next.Next
    }
    //如果ListNode 长度为奇数
    if fast != nil{
        slow = slow.Next
    }
    //stack 数值和后半部分链表值比较
    for slow !=nil {
        ln := len(stack)
        if ln > 0{
            //stack pop
            pop := stack[ln-1]
            stack = stack[0:ln-1]

            if pop != slow.Val{
                return false
            }
        }
        slow = slow.Next
    }
    return true
}
```