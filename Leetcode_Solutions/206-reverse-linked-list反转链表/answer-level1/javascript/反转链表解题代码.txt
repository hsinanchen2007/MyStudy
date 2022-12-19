var reverseList = function(head) {
    let current = head;
    //保留处理过的链表 1.初始化(null)  2.处理之后的头节点
    let previous =null;
    while(current){
        //存储未处理链表的头节点
        let unprocessed = current.next;
        //将待处理的节点，接入到处理后的头部
        current.next = previous;
        //游标后移
        previous = current;
         //游标后移
        current = unprocessed;
    }
    return previous;
};