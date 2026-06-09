##### 步骤

1. 定义了快、慢指针
2. 快指针一次走2格，慢指针一次走一格
3. 其中慢指针走过的路做反转存到`half`
4. 第一个循环在快指针到头时停止
5. 如果原链表长度是奇数，慢指针要再多走一格，跳过链表中间的那一个元素
6. 这样子会得到slow和half长度是相同的，对比他们每个节点即可
6. 第二个循环让慢指针走完剩下的路，half与其一同上路
7. 有一个不相等就失败，走到最后就是真正的回链

<br>

```javascript
var isPalindrome = function(head) {
    let fast = head // 快指针
    let slow = head // 慢指针
    let half = null // 存链表前1/2部分的反向链表，从slow
    let cache // 链表反转用的临时变量

    while(fast && fast.next) {
        cache = half
        half = slow

        slow = slow.next
        fast = fast.next
        fast = fast.next
        
        half.next = cache
    }

    if(fast) {
        /**
        如 [1,2,3,4,5] 这样的奇数长度链表
        根据第一个遍历，走2步，最终
        slow = [3, {}]
        fast = [5, null]
        我们想要的是 slow[4,5] 和 half是[2,1] 对比
        所以slow要再多走一步，跳过奇数链表中间那一个元素
         */
        slow = slow.next
    }

    while(slow) {
        if(slow.val != half.val) {
            return false
        }
        slow = slow.next
        half = half.next
    }
    return true
};
```
