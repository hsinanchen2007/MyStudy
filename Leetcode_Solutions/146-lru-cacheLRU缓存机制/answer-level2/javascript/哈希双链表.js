**哈希双链表实现, 可以更加深刻的理解数据结构的用途, 挺好的一个训练**

```

function  DLinkedNode  () {
    this.key = null;
    this.value = null;
    this.prev = null
    this.next = null;
}

/**
 * @param {number} capacity
 */
var LRUCache = function(capacity) {

    this.cache = new Map ();
    this.size = 0;
    this.capacity = capacity;

    this.head = new DLinkedNode ();
    this.tail = new DLinkedNode ();

    //一个双向链表已经建立
    this.head.next = this.tail;
    this.tail.prev = this.head;
};


/** 
 * @param {number} key
 * @return {number}
 */
LRUCache.prototype.get = function(key) {
    let node =  this.cache.get(key);
    if (!node) return -1;

    // move the accessed node to the head;
    //使用过的放在头部
    this.moveToHead (node);
    return node.value;
};

/** 
 * @param {number} key 
 * @param {number} value
 * @return {void}
 */

LRUCache.prototype.put = function(key, value) {
    let node = this.cache.get(key);
    if (!node) {
        let newNode = new DLinkedNode ();
        newNode.key = key;
        newNode.value = value;

        this.cache.set (key, newNode );
        this.addNode(newNode);

        this.size ++ ;

        if (this.size > this.capacity ) {
            //双向链表中要删除, 哈希 cache 中也要删除
            let tailNode = this.popTail ();
            this.cache.delete(tailNode.key);
            //计数减一
            this.size = this.size -- ;
        };
    } else {
        // update the value
        node.value = value;
        this.moveToHead (node);
    };
};


LRUCache.prototype.addNode = function( node ) {
    //Always add the new node right after head
    //添加到队头
    //假如 head  head.next 指向 nodeB

    //把 node 的 prev 和 next 指针 分别指向 head,  nodeB 这两个 节点
    node.prev = this.head;
    node.next = this.head.next;

    //上面我们仅仅修改了node的指针, 并没有修改 head 的 next 指针指向, 和 nodeB 的 prev 的指针指向
    //形成双向链表
    this.head.next.prev = node;
    this.head.next = node;
}

LRUCache.prototype.removeNode = function( node ) {
    /**
     * Remove an existing node from the linked list.
    */
    //从双向链表中, 删除 node, 先记录下 它的前驱和后继指向的对象
    let prev = node.prev;
    let next = node.next;

    //把两个节点联系起来
    prev.next = next;
    next.prev = prev;
}

LRUCache.prototype.moveToHead = function( node ) {
    /**
     * Move certain node in between to the head.
     */
    this.removeNode (node);
    this.addNode (node);
}
// 一个需要注意的是，在双向链表实现中，这里使用一个伪头部和伪尾部标记界限，这样在更新的时候就不需要检查是否是 null 节点;
// this.tail 是伪尾部
LRUCache.prototype.popTail = function( node ) {
    /**
     * Pop the current tail.
     */
    let res = this.tail.prev;
    this.removeNode (res);
    return res;
}

```
