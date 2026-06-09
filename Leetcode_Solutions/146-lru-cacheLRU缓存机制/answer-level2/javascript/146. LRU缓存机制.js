// #### 解法一：LRU = 哈希表 + 双向链表
// + 思路
//   + 哈希表
//     + 查找：O(1)，数据没有顺序，但插入删除慢
//   + 双链表
//     + 插入、删除：O(1)，数据🈶️顺序，但查找慢
//   + 模版
//     ```javascript
    实现哈希表
    实现双链表
    let LRUCache = function(capacity) {
        初始化容量，用于判断LRU是否已满
        初始化哈希表映射，用于查找节点
        初始化双链表，用于插入、删除节点
    };
    LRUCache.prototype.get = function(key) {
        if(哈希查找 不存在){
            return -1;
        }else{
            将此节点置于开头，为最近访问节点
            return 节点值
        }
    }
    LRUCache.prototype.put = function(key, value) {
        if(哈希查找 已经存在){
            删除旧的数据
            
        }else{
            if(LRU 即 双链表已满){
                删除尾节点
                更新哈希映射值，并将更新后的节点置于开头
            }
            将新节点置于开头
            新建新节点的哈希映射
        }
    }
//     ``` 
// ```javascript
// 链表节点
class Node{
    constructor(key,val){
        this.key = key;
        this.val = val;
    }
}
// 双链表
class DoubleList{
    // 初始化头、尾节点、链表最大容量
    constructor(){
        this.head = new Node(0,0);
        this.tail = new Node(0,0);
        this.size = 0;
        this.head.next = this.tail;
        this.tail.prev = this.head;
    }
    // 在链表头部添加节点
    addFirst(node){
        node.next = this.head.next;
        node.prev = this.head;
        this.head.next.prev = node;
        this.head.next = node;
        this.size++;
    }
    // 删除链表中存在的node节点
    remove(node){
        node.prev.next = node.next;
        node.next.prev = node.prev;
        this.size--;
    }
    // 删除链表中最后一个节点，并返回该节点
    removeLast(){
        // 链表为空
        if(this.tail.prev == this.head){
            return null;
        }
        let last = this.tail.prev;
        this.remove(last);
        return last;
    }
}
/**
 * @param {number} capacity
 */
var LRUCache = function(capacity) {
    this.cap = capacity;
    this.map = new Map();
    this.cache = new DoubleList();
};

/** 
 * @param {number} key
 * @return {number}
 */
LRUCache.prototype.get = function(key) {
    let map = this.map;
    if(!map.has(key)){
        return -1;
    }
    let val = map.get(key).val;
    // 最近访问数据置前
    this.put(key,val);
    return val;
};

/** 
 * @param {number} key 
 * @param {number} value
 * @return {void}
 */
LRUCache.prototype.put = function(key, value) {
    let cache = this.cache;
    let map = this.map;
    let node = new Node(key,value);
    if(map.has(key)){
        // 删除旧的节点，新的插到头部
        cache.remove(map.get(key));
    }else{
        if(this.cap == cache.size){
            // 删除最后一个
            let last = cache.removeLast();
            map.delete(last.key);
        }
    }
    // 新增头部
    cache.addFirst(node);
    // 更新 map 映射
    map.set(key,node);
};

/** 
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */
// ```
// #### 解法二：Map
// + Map 中的键值是有序的，而添加到对象中的键则不是。因此，当对它进行遍历时，Map 对象是按插入的顺序返回键值
// + Map.prototype.keys()
//   + 返回一个新的 Iterator对象， 它**按插入顺序**包含了Map对象中每个元素的键 。
//     + 1、尾部元素一直是最新set的，对应于LRU的最近使用原则
//       + Map.set()
//     + 2、头部元素是最远使用的，用于LRU容量满载时删除最远使用的元素，可获取其key
//       + Map.keys().next().value
// + 解题步骤
//   + get
//     + 元素存在
//       + delete、set
//     + 元素不存在
//       + return -1
//   + put
//     + 元素存在
//       + delete、set
//     + 元素不存在
//       + 容量超载
//         + delete map头部元素(**最远不常用**)、set
//       + 不超载
//         + set
// ```javascript
/**
 * @param {number} capacity
 */
var LRUCache = function(capacity) {
    this.cap = capacity;
    this.cache = new Map();
};

/** 
 * @param {number} key
 * @return {number}
 */
LRUCache.prototype.get = function(key) {
    let cache = this.cache;
    if(cache.has(key)){
        let val = cache.get(key);
        cache.delete(key);
        cache.set(key,val);
        return val;
    }else{
        return -1;
    }
};

/** 
 * @param {number} key 
 * @param {number} value
 * @return {void}
 */
LRUCache.prototype.put = function(key, value) {
    let cache = this.cache;   
    if(cache.has(key)){
        cache.delete(key);
    }else{
        if(cache.size == this.cap){
            cache.delete(cache.keys().next().value);
        }
    }
    cache.set(key,value);
};

/** 
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */
// ```