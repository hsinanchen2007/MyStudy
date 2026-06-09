### 解题思路
此处撰写解题思路
暴力循环 分别取出两个链表的节点放进两个数组
然后遍历对比两个数组 有相同的节点 return该节点
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
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
var getIntersectionNode = function(headA, headB) {
    let arrA=[]
    let arrB=[]
    while (headA!=null){
        arrA.push(headA)
        headA=headA.next
    }
    while (headB!=null){
        arrB.push(headB)
        headB=headB.next
    }
    for(let item of arrA){
        for(let obj of arrB){
            if(item ===obj){
                console.log(item)
                return item
            }
        }
    }
    return null
};
```