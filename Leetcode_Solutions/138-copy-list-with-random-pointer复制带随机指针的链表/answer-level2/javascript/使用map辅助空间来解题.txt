### 解题思路
首先我们可以想到，先整个对node进行顺序链的复制，即将next节点的逻辑链实现，
然后接下来我们考虑，每个节点random指向可能在前，可能后，如果要确定位置的话，我们需要每个节点从前往后遍历，
这样时间复杂度为O(n²);
然后我们考虑借助map，在第一次建立顺序链的时候，将原来链上的节点node,和新复制的节点clonedNode，建立map关系，
即(node,clonedNode)；
然后再遍历一次原来顺序链，这样可以找到原顺序链的节点，原顺序链的下一个节点，
这样通过map就可以对应得到复制顺序链的当前节点，和下一个节点，然后建立指向即可


### 代码

```javascript
/**
 * // Definition for a Node.
 * function Node(val, next, random) {
 *    this.val = val;
 *    this.next = next;
 *    this.random = random;
 * };
 */
/**
 * @param {Node} head
 * @return {Node}
 */
var copyRandomList = function(head) {
    if(!head){
        return null;
    }
    let nodeMap = new Map();
    let currentNode = head;
    let start = clonedNode = new Node();
    while(currentNode){
        let tempNode = new Node();
        tempNode.val = currentNode.val;
        tempNode.next = currentNode.next;
        tempNode.random = null;
        nodeMap.set(currentNode,tempNode);
        currentNode = currentNode.next;
        clonedNode.next = tempNode;
        clonedNode = clonedNode.next;
    }

    let nextStart  = head;
    while(nextStart){
        let currentBeClonedNode = nextStart;
        let clonedNode = nodeMap.get(currentBeClonedNode);
        let nextBeCloneNode = currentBeClonedNode.random;
        let nextCloneNode = nodeMap.get(nextBeCloneNode);
        clonedNode.random = nextCloneNode;
        nextStart = nextStart.next;
    }

    return start.next;
};
```