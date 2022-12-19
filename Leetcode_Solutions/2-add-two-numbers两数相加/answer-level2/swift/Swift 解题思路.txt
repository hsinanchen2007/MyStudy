思路：首先利用数组求和遍历处理进位解题，然后大脑展开思路后，优化为同官方解题方法。
```
private class Solution1 {
    func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        
        var temp_l1 = l1
        var temp_l2 = l2
        
        var totalArr = [Int]()
        
        while temp_l1 != nil || temp_l2 != nil {
            let l1_val = temp_l1 != nil ? temp_l1!.val: 0
            let l2_val = temp_l2 != nil ? temp_l2!.val: 0
            
            totalArr.append(l1_val + l2_val) // 首先只是求出每对数字的和并存在数组里面
            
            temp_l1 = temp_l1?.next
            temp_l2 = temp_l2?.next
        }
        
        var valuePerBitArr = [Int]()
        
        var decimal = 0 // 记录进位
        
        for valuePerBit in totalArr {
            valuePerBitArr.append((valuePerBit + decimal) % 10) // 当前位的实际值
            decimal = (valuePerBit + decimal) / 10 // 是否进位
        }
        
        if decimal > 0 { // 最后一组数字，是否需要进位
            valuePerBitArr.append(decimal)
        }
        
        let dummyHead = ListNode(0)
        var result = dummyHead // 移动链表
        
        for value in valuePerBitArr { // 遍历数组构成链表
            result.next = ListNode(value)
            result = result.next!
        }
        
        return dummyHead.next
    }
}
```
优化代码结构：
```
private class Solution2 {
    func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        
        var temp_l1 = l1
        var temp_l2 = l2
        
//        var totalArr = [Int]()
        
        var decimal = 0
        
        let dummyHead = ListNode(0)
        var result = dummyHead
        
//        var valuePerBitArr = [Int]()
        
        while temp_l1 != nil || temp_l2 != nil {
            let l1_val = temp_l1 != nil ? temp_l1!.val: 0
            let l2_val = temp_l2 != nil ? temp_l2!.val: 0
            
//            totalArr.append(l1_val + l2_val)
            
            let valuePerBit = l1_val + l2_val
            
//            valuePerBitArr.append((valuePerBit + decimal) % 10)
            
            result.next = ListNode((valuePerBit + decimal) % 10)
            result = result.next!
            
            decimal = (valuePerBit + decimal) / 10
            
            temp_l1 = temp_l1?.next
            temp_l2 = temp_l2?.next
        }
        
//        for valuePerBit in totalArr {
//            valuePerBitArr.append((valuePerBit + decimal) % 10)
//            decimal = (valuePerBit + decimal) / 10
//        }
        
//        if decimal > 0 {
//            valuePerBitArr.append(decimal)
//        }
        
        if decimal > 0 {
            result.next = ListNode(decimal)
        }
        
//        for value in valuePerBitArr {
//            result.next = ListNode(value)
//            result = result.next!
//        }
        
        return dummyHead.next
    }
}

```
