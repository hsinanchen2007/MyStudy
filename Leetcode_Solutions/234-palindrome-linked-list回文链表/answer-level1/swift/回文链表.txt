总体思路:

使用快慢指针找到链表的中间位置
反转前半部分链表
逐一对比前后两部分链表
 上面提到了快慢指针,我们来了解一下如下:

利用快慢指针,将一个链表看成一个跑道, 假设a的速度是b的两倍, 那么当a跑完全程后, b刚好跑一半, 来找到中间节点的目的.

slow 和 fast 指针都指向链表的第一个节点,然后slow 每次移动一个指针, fast每次移动两个指针.图如下:
![image.png](https://pic.leetcode-cn.com/18c67dbd80d671dd82e83aff273d600eb86b13fed952f22d69692f52c9c4c52a-image.png)

```
public class ListNode {
    public var val: Int?
    public var next: ListNode?
    public init (_ val: Int) {
        self.val = val
        self.next = nil
    }
}

func isPalindrome(_ head: ListNode?) -> Bool {
    if head == nil || head?.next == nil {
        return true
    }
    var slow = head //慢指针每次移动一个元素,初始值为head
    var fast = head //快指针每次移动两个元素,初始值为head
    var pre = head  //用于前半部分逆转后的指针,指向head
    var prepare: ListNode? = nil
    while fast != nil && fast?.next != nil {//移动快慢指针,然后并将前半部分发转
        pre = slow
        slow = slow?.next
        fast = fast?.next?.next
        pre?.next = prepare
        prepare = pre
    }
    if fast != nil { //奇数时候,中间位置下一个(这样翻转才一样) 1->2->3->2->1,然后分为前半部分反转之后为2->1与原本之后的1->2,就是为了过掉奇数中的中间点3
        slow = slow?.next
    }
    while pre != nil && slow != nil {
        if pre?.val != slow?.val { //不一样的值,直接返回
            return false
        }
        pre = pre?.next //前半部分后移一位
        slow = slow?.next //后半部分后移一位
    }
    return true
}
```
