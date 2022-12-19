# 迭代解法
使用两个指针，pre 和 cur
cur代表当前所在节点，pre 代表上一个节点
初始状态下，pre 为 null，cur 为 head，对当前节点 cur 进行迭代
1. 迭代过程中，先存下来原来的 next = cur.next
2. 然后把当前的 cur.next 指向 pre，达到反转的目的
3. 反转成功后，再把 pre 节点和 cur 节点分别向前前进一个
继续重复上述1-3操作

```
var reverseList = function(head) {
    if(!head || !head.next) return head
    let cur = head
    let pre = null
    while(cur){
        let next = cur.next
        cur.next = pre
        pre = cur
        cur = next
    }
    return pre
};
```
