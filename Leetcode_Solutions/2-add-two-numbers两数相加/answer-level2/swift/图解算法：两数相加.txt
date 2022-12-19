
```
    func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        var p = l1
        var q = l2
        var note = ListNode(0)
        let head = note //指向头
        var carry = 0 // 进位(满十)
        while q != nil || p != nil {  //也可以写出  q != nil || p != nil  || carry != 0  省略后面if carry > 0 的判断
            let a = q?.val ?? 0
            let b = p?.val ?? 0
            let sum = a + b + carry
            carry = sum / 10 //刷新进位
            note.next = ListNode(sum % 10)
            note = note.next!
            if p != nil {
                p = p?.next
            }
            if q != nil {
                q = q?.next
            }
            if carry > 0 {
                note.next = ListNode(carry)
            }
        }
        return head.next//为什么返回 head.next？ 因为head的头节点是0
    }
```
![WX20200409-151625@2x.png](https://pic.leetcode-cn.com/a67a7ce41deddd38bb998812e86732ad9c7ee18aeb1cd2eda1dc1ff5ce94c203-WX20200409-151625@2x.png)

