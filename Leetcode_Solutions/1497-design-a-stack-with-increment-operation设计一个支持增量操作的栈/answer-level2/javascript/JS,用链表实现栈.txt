### 解题思路
先说结论：在JS中，用数组模拟栈性能远远高于链表，也更易于操作，用链表只是一种思路；
理论上，链表的pop和push操作复杂度低于数组。
### 代码

```javascript
/**
 * @param {number} maxSize
 */
function ListNode(val){
    this.val=val;
    this.next=null;
}
var CustomStack = function(maxSize) {
    this.maxSize=maxSize;
    //链表头指向栈顶；
    this.head=null;
    this.length=0;
};

/** 
 * @param {number} x
 * @return {void}
 */
CustomStack.prototype.push = function(x) {
    if(this.length===this.maxSize) return;
    let node=new ListNode(x);
    let linkList=this.head;
    node.next=linkList;
    this.head=node;
    this.length++;
};

/**
 * @return {number}
 */
CustomStack.prototype.pop = function() {
    if(this.length===0) return -1;
    let linkList=this.head.next;
    let popVal=this.head.val;
    this.head=linkList;
    this.length--;
    return popVal;
};

/** 
 * @param {number} k 
 * @param {number} val
 * @return {void}
 */
CustomStack.prototype.increment = function(k, val) {
    if(k<0) return;
    let start=this.length-k;
    let currentNode=this.head;
    if(start>0){
        for(let i=0;i<start;++i){
            currentNode=currentNode.next;
        }
    }
    while(currentNode){
        currentNode.val+=val;
        currentNode=currentNode.next;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * var obj = new CustomStack(maxSize)
 * obj.push(x)
 * var param_2 = obj.pop()
 * obj.increment(k,val)
 */
```