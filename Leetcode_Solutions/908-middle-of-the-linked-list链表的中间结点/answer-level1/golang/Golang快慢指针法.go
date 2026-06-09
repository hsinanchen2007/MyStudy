
![image.png](https://pic.leetcode-cn.com/73fd2efcbc52d95d614e3ff0f8573675de7847aab4624255a6c0313397482ce1-image.png)

### 解题思路
思路1：简单暴力，直接先遍历一遍获得链表长度n，再进行第二次链表遍历到（n+1）/2.0 向上取整 时间复杂度稍高

思路2：输出到数组，通过index进行获取

思路3：快慢指针。V_fast = 2*V_slow ，快指针到达链表末尾时，此时的慢指针刚好在中间，时间复杂度和空间复杂度都表现的很好

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func middleNode(head *ListNode) *ListNode {
    fast := head
    slow := head

    for fast!=nil && fast.Next!=nil{
        fast = fast.Next.Next
        slow = slow.Next
    }
    return slow
}


/*
思路1：简单暴力，直接先遍历一遍获得链表长度n，再进行第二次链表遍历到（n+1）/2.0 向上取整 时间复杂度稍高

思路2：输出到数组，通过index进行获取

思路3：快慢指针。V_fast = 2*V_slow ，快指针到达链表末尾时，此时的慢指针刚好在中间，时间复杂度和空间复杂度都表现的很好

*/
```