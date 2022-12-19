### 解题思路
折半查询 
先找到总长度
然后折半如果是偶数加一 如果是奇数先加一再除以二
然后通过while求出所需值
在这 我改变了源数据  当然也可以拷贝一个 返回

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
var middleNode = function (head) {
    let length = 1;
    let newhead=head;
    while(newhead.next){
        length++;
        newhead=newhead.next;
    }
    length%2==0?length=length/2+1:length=(length+1)/2;
    while(--length){
        head=head.next
    }
    return head
};
```