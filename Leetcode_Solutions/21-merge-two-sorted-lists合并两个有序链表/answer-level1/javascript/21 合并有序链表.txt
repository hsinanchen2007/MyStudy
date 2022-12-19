### 解题思路

第一回忘记存储 头节点了，导致最后返回了最后一位
内存竟然才打败了40%，等会儿看看咋优化

1. 创建head,l3
2. 比较l1,l2小的存储到l3，并指向下一位，接着比较
3. head = l3 记录头
4. l3 = l3.next 接着存储
5. 当 l1,l2 都不为null时，循环第二步 第四步
6. 二者其中有一空，则l3直接指向不为空的那一个
7. return head

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
    let head,l3
    if(l1 === null){
        return l2
    }
    if(l2 === null){
        return l1
    }
    if(l1.val <= l2.val){
        l3 = l1
        l1 = l1.next
    }else{
        l3 = l2
        l2 = l2.next
    }
    head = l3
    while(l1 && l2){
        if(l1.val <= l2.val){
            l3.next = l1
            l1 = l1.next
        }else{
            l3.next = l2
            l2 = l2.next
        }
        l3 = l3.next
    }

    // 有一方 为 null
    if(!l1){
        l3.next = l2
    }else if(!l2){
        l3.next = l1
    }

    return head
};
```