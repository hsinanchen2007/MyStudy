### 解题思路
【方法一】
循环两次，第一次统计链表长度n，第二次找到n/2+1个节点。
【方法二】
循环一次，使用快慢指针来寻找中间节点，快指针每次移动2步，慢指针每次移动1步

### 代码

```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var middleNode = function(head) {
    return method2(head)
};
/*
    1. 计算链表长度n
    2. 计算结果是第几个节点：取n/2+1个节点
    3. 找到第n个节点
*/
var method1=function(head){
    let original=head;
    //第一轮循环计算链表的长度
    let length=0;
    while(head){
        length++
        head=head.next
    }
    //算中间节点
    let index=parseInt(length/2)+1
    console.log(index)
    //找到第n个节点
    length=0;
    r=null;
    while(original){
        length++
        if(length==index)
            return original
        original=original.next
    }
}
/*
    使用双指针在链表中移动，快指针移动两步，慢指针移动一步
*/
var method2=function(head){
    //添加哑节点处理边界情况
    let fast=new ListNode(null)//快指针
    fast.next=head
    let slow=fast;//慢指针
    while(fast){
        slow=slow.next//每次移动一步 
        if(fast.next) fast=fast.next.next//每次移动两步
        else return slow
    }
    return slow
}
```