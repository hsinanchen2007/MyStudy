### 解题思路
遍历到一个currNode节点， 要把 next 指向前一个节点， 需要
1. 缓存前一个节点 prevNode， 并把next指针更改
2. 在next指针更改后，就无法直接使用currNode.next继续访问下一个节点
3. 为了保证链表不断裂， 在遍历currNode时，需要缓存后一个节点 nextNode
4. 做完这些准备工作后就是，更改指针， 移动前后节点的指针了
```
var reverseList = function(head) {
    //缓存前一个节点保证正确指向
    //缓存后一个节点保证链表不断
    //交换指针后，以后前后节点的指针
    //p => c => n => m
    //x => p => c => n
    let prevNode = null,
        nextNode = null,
        currNode = head,
        ReservedHead = null
    
    while(currNode) {
        nextNode = currNode.next

        if(currNode.next === null) ReservedHead = currNode

        //switch pointer
        currNode.next = prevNode

        //move pointer, 顺序不能变
        prevNode = currNode
        currNode = nextNode
    }
    return ReservedHead
};
```


