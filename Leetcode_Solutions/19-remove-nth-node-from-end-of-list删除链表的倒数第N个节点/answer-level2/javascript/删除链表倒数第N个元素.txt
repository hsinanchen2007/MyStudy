### 解题思路
找到倒数第N+1个元素，将倒数N+1个元素的next指向倒数N-1个元素

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
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function(head, n) {
    let r=head;//保存最终结果的指针
    let index=0
    let temp=null;//记录倒数第N+1个节点的指针
    while(head){
        index++;
        //当前节点
        if(index==n+1){//当循环到n+1个元素时，将头指针存储到temp中
            temp=r
        }else if(index>n+1){//之后每一次迭代都将temp后移一位
            temp=temp.next
        }
        //到下一节点
        head=head.next
    }
    if(index<n){//如果整个链表都没有n个元素那么直接返回整个链表
        return r
    }else if(index==n){//如果整个链表元素个数正好==n，那么删除头元素就可以了
        return r.next
    }else{//如果整个链表至少有n+1个元素，那么我们使用我们将前一个指针指向后一个指针的方式来删除倒数第n个元素
        temp.next=temp.next.next
        return r
    }
};
```