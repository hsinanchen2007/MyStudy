### 解题思路
此处撰写解题思路
数组法
1.遍历链表，将链表所有节点的值按顺序保存在数组arr中
2.在数组arr头和尾各插入一个值为null的元素
3.创建一个新的节点result
4.从1~arr.length-2遍历数组，当元素与前一元素后一元素都不相等的时候，则创建节点，构成新的链表
5.返回result.next
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
var deleteDuplicates = function(head) {
    if(!head)return head
    let arr=[null]
    while(head){
        arr.push(head.val)
        head=head.next
    }
    arr.push(null)
    let result=new ListNode()
    let tmp=result
    for(let i=1;i<arr.length-1;i++){
        if(arr[i]!=arr[i-1]&&arr[i]!==arr[i+1]){
            tmp.next=new ListNode(arr[i])
             tmp=tmp.next
        }
    }
    return result.next
};
```