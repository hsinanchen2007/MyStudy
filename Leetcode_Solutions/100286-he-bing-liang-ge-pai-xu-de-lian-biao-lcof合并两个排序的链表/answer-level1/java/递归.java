### 解题思路
看代码注释

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
    if(l1 == null){
        return l2
    }else if(l2 == null){
        return l1
    }
    // 递归比较两个链表，较小的优先插入新的node链表中
    let node = new ListNode()
    /**
     * l1:1,2,4
     * l2:1,3,4
     * 
     * l1:1
     * l2:1
     * l1<=l2 =>  1<=1
     * 第一层遍历的时候：l1的1值添加到node中，所以第一个node的值1，l1指向下一个节点。l2保持不变
     * l1>=l2    2>=1
     * 第二层遍历的时候，l2的1值明显少于l1的2，所以第二个node的值也是1，l2值指向下一个节点。l1不变。
     * 
     * 依次类推
     * 
     * 最后一层的前一层（4<=4）
     * l1的值是4,添加到node中，l1指针指向下一个,也就是l1为空了，然后
     * 最后一层遍历的时候 返回 l2，也就是最后一个的值 l2的4。
     * 
     * 最终 回溯，构建node
    */
    if(l1.val <= l2.val){
        node.val = l1.val
        node.next = mergeTwoLists(l1.next,l2)
    }else{
        node.val = l2.val
        node.next = mergeTwoLists(l1,l2.next)
    }

    return node


};
```