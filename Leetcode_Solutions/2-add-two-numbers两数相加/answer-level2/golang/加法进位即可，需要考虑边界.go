### 解题思路
代码写的不好，不过刚开始玩leetcode慢慢来吧

其实这个题目是一个基本的数学运算题

例如两个链表如下
2->4->3 
5->6->4

变成是:342 + 465 = 807 倒顺就是708

本质上是从2->4->3从左到右边进行相加，左边是低位，右边是高位，要考虑进位。

怎么计算加法很简单，需要考虑的边界地方很多。

lenOfList这个函数是获取链表的长度

在主方法中演示了加法，边界条件如下：

进位为1的话 需要多加入一个节点

添加新节点需要考虑链表是否有新的输入加入，不然会多加一个初始化链表节点，Val的值为0


### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func lenOfList(l *ListNode) int {
    var len int = 0
    var p *ListNode = l

    for {
        
        if p == nil {
            break
        }

        len = len + 1
        p = p.Next
    }

    return len
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {

    var len1 int = lenOfList(l1)
    var len2 int = lenOfList(l2)
    var maxLen int = len1
    if len1 < len2 {
        maxLen = len2
    }

    var p *ListNode = new(ListNode)
    var head *ListNode = p

    var addedNum int = 0
    var tmpL *ListNode = nil
    for i := 0; i < maxLen; i ++ {

        if i < len1 && i < len2 {
            
            var tmp int = l1.Val + l2.Val + addedNum

            head.Val = tmp % 10

            addedNum = tmp / 10

            l1 = l1.Next
            l2 = l2.Next

            if l1 != nil || l2 != nil {

                head.Next = new(ListNode)
                head = head.Next
                head.Next = nil
            } else {

                if addedNum == 1 {

                    head.Next = new(ListNode)
                    head = head.Next
                    head.Val = addedNum
                    head.Next = nil
                }
            }
        } else {

            if tmpL == nil {
                
                tmpL = l1
                if l2 != nil {
                    tmpL = l2 
                }
            }

            var tmp int = tmpL.Val + addedNum

            head.Val = tmp % 10

            addedNum = tmp / 10

            tmpL = tmpL.Next

            if tmpL != nil {

                head.Next = new(ListNode)
                head = head.Next
                head.Next = nil
            } else {

                if addedNum == 1 {

                    head.Next = new(ListNode)
                    head = head.Next
                    head.Val = addedNum
                    head.Next = nil
                }
            }
        }
    }

    return p
}
```