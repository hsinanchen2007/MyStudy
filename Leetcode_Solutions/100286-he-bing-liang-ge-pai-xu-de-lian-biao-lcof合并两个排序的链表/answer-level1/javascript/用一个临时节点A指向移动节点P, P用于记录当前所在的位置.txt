### 解题思路
此处撰写解题思路

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
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var mergeTwoLists = function(l1, l2) {
    let pointer=new ListNode();  //相当于游标用于指向当前筛选出来放在最终结果的位置
    let link=pointer; //用于保存第一个节点，因为游标pointer会向前移动
    while(l1 && l2){
        if(l1.val < l2.val){
            pointer.next = l1;//把俩链表中当前节点里小的那个拿出来放进结果链表的末尾也就是pointer位置
            l1=l1.next;//指向下一个预备用于对比的节点
        }else{
            pointer.next = l2; //同理
            l2=l2.next;
        }
        pointer=pointer.next; //游标也随着移动下一个
    }
    pointer.next=l1?l1:l2;//最后剩下不为空的链表剩余节点们肯定大于结果链表最后那个节点，所以直接连在结果链表末尾就可以了
    return link.next; //返回临时节点一开始时候保存的第一个节点
};
```