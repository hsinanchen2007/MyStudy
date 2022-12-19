

```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    var mylist1 = l1;
    var mylist2 = l2;
    // 存储每次和的节点
    var c3;
    // 存储最终返回的和
    var l3;
    var carry = 0;
    while(mylist1 || mylist2|| carry){
        var value1 = 0;
        var value2 = 0;
        var sum = 0;
        if(mylist1)
        {
            value1 = mylist1.val;
            mylist1 = mylist1.next;            
        }
        if(mylist2)
        {
            value2 = mylist2.val;
            mylist2 = mylist2.next;
        }
        sum = value1 + value2 + carry;
        carry = Math.floor(sum / 10);
        if (!c3) {
            // 不知道理解的对不对，最开始l3、c3指向同一内存空间，都存储了第一个节点，且第一个节点的next为null
            l3 = new ListNode(sum % 10);
            c3 = l3;
            console.log(l3);
            console.log(c3);                   
        } else {
            // 创建c3的下一个节点，此时l3也会更新
            c3.next = new ListNode(sum % 10);
            // 把c3的下一个节点赋值给c3
            c3 = c3.next;
            console.log(l3);
            console.log(c3);
        }
    }
    return l3;
};


```