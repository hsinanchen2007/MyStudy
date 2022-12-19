### 解题思路
1. 第一步将链表变为环:
    1.1 将链表最后节点next指向head

2. 第二部找到新的头结点并将环打破：
    2.1. 根据旋转的数值找到最终循环中对应的node并用两个辅助node标记当前node以及他的前置node(此处不能使用单一节点，如下有反例)
    2.2. 从前置node处断开
### 代码

```swift
class Solution {
    func rotateRight(_ head: ListNode?, _ k: Int) -> ListNode? {
        /*
    反例：不能使用单一节点，
        //第一步将链表变为环
        //第二部找到新的头结点并将环打破
        
        var dumb: ListNode? = ListNode(-1)
        dumb?.next = head
        //1.组装环行链表
        var last = head
        var length = 1
        while last?.next != nil {
            last = last?.next
            length += 1
        }
        last?.next = head

        //2.找到新的头结点
        var step = length - k % length
        while step != 0 {
            step -= 1
            dumb?.next = dumb?.next?.next
        }
        
        //3.从新的头节点前节点处断开环
        let newHead = dumb?.next
        dumb?.next = nil
        
        return newHead
 */
   
        //第一步将链表变为环
        //第二部找到新的头结点并将环打破
        
        //1.组装环行链表
        var last: ListNode? = head
        var length = 1
        while last?.next != nil {
            last = last?.next
            length += 1
        }
        last?.next = head

        //2.找到新的头结点
        var step = length - k % length
        var newHead = head
        var newTail = last
        while step != 0 {
            step -= 1
            newHead = newHead?.next
            newTail = newTail?.next
        }
        
        //3.从新的头节点前节点处断开环
        newTail?.next = nil
        
        return newHead
    }
}

```