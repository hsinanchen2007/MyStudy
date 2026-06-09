
![屏幕快照 2019-05-14 下午3.44.30.png](https://pic.leetcode-cn.com/3049bcd9212de1eac491fceb93f1057109b14f6f5ffb6c9b99ac0141e7ea3bc9-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-05-14%20%E4%B8%8B%E5%8D%883.44.30.png)

两数倒叙相加，每个链节点只存个位int数据，故两数相加当前节点对10取余，大于9则下一节点增加1，用flag来记录0和1即可。
```
    func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? 
{
        var ll1 = l1 ,ll2 = l2 ,node = ListNode(0)
        let nodes = node
        var flag = 0
        while (ll1?.val != nil || ll2?.val != nil || flag == 1)
        {
            let num1 : Int = ll1?.val ?? 0
            let num2 : Int = ll2?.val ?? 0
            var num = num1 + num2 + flag
            if num > 9
            {
                num = num%10
                flag = 1
            }else
            {
                flag = 0
            }
            node.next = ListNode(num)
            node = node.next!
            ll1  = ll1?.next
            ll2  = ll2?.next
        }
        return nodes.next
    }
```