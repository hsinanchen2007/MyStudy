
![image.png](https://pic.leetcode-cn.com/ab6e2e386dd60fd3df0bed6dba3cb3a4ebf443da142d5cc499dab9b1346d71aa-image.png)



```
var addTwoNumbers = function(l1, l2) {
    function Stack() {
    let list = new ListNode(0)
    this.pop = function () {
        let newNode = list.next
        if (!list.next) {
            return undefined
        }
        list.next = list.next.next
        return newNode.val
    }
    this.push = function (val) {
        let newNode = new ListNode(val)
        newNode.next = list.next
        list.next = newNode
        return list.next
    }
    this.isEmpty = function () {
        return list.next === null ? true : false
    }
    this.length = function () {
        let len = 0
        let cur = list.next
        while (cur) {
            len++
            cur = cur.next
        }
        return len
    }
}

    let stack1 = new Stack()
        stack2 = new Stack()
    
    while(l1){
        stack1.push(l1.val)
        l1 = l1.next
    }
    while(l2){
        stack2.push(l2.val)
        l2 = l2.next
    }
    let carry = 0,jummy = new ListNode(0)
    while(!stack1.isEmpty()||!stack2.isEmpty()||carry){
        let num1 = stack1.isEmpty()?0:stack1.pop()
        let num2 = stack2.isEmpty()?0:stack2.pop()
        let num = num1 + num2 + carry
        carry = num>=10? 1:0
        num = num>=10?num-10:num
        let cur = new ListNode(num)
        cur.next = jummy.next
        jummy.next = cur
    }
    return jummy.next
};
```