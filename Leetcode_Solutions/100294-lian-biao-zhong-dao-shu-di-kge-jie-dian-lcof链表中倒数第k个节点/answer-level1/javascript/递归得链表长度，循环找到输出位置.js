### 解题思路
链表长度递归方法 head ? 1 + length(head.next) : 0
总长度-倒数节点=需遍历节点数，找到位置后输出
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
 * @param {number} k
 * @return {ListNode}
 */
function length(head) {
  return head ? 1 + length(head.next) : 0
}
var getKthFromEnd = function (head, k) {
    var l=length(head);
    if(l==k){return head;}
    else{
        l=l-k;
        for(let i=1;i<=l;i++){
            head=head.next;
        }
        return head;
    }
};
```