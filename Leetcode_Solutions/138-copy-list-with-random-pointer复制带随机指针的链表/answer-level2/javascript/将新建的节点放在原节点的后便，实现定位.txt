### 解题思路
分为三步：
1.复制节点，构造顺序链
N1 -> N1' -> N2 -> N2' -> N3 -> N3' -> null
2.根据定位得到新建节点的连接
因为我们将复制的节点放在了当前节点的后边，所以就可以得到当前节点的random节点，然后random->next 即为复制节点的next即： N1' -> random = N1 -> random -> next ;
3.分离链表
这样再将原来链表和复制的链表分离处理（根据奇数偶数位）


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


/*
*   使用map辅助空间
 */
// var copyRandomList = function(head) {
//     if(!head){
//         return null;
//     }
//     let nodeMap = new Map();
//     let currentNode = head;
//     let start = clonedNode = new Node();
//     while(currentNode){
//         let tempNode = new Node();
//         tempNode.val = currentNode.val;
//         tempNode.next = currentNode.next;
//         tempNode.random = null;
//         nodeMap.set(currentNode,tempNode);
//         currentNode = currentNode.next;
//         clonedNode.next = tempNode;
//         clonedNode = clonedNode.next;
//     }

//     let nextStart  = head;
//     while(nextStart){
//         let currentBeClonedNode = nextStart;
//         let clonedNode = nodeMap.get(currentBeClonedNode);
//         let nextBeCloneNode = currentBeClonedNode.random;
//         let nextCloneNode = nodeMap.get(nextBeCloneNode);
//         clonedNode.random = nextCloneNode;
//         nextStart = nextStart.next;
//     }

//     return start.next;
// };

// 邻近节点指向
var copyRandomList = function(head) {
    if(!head){
        return null;
    }
    let start = head;
    start = copyList(start);
    // console.log(start);
    start = changeRandom(start);
    // console.log(start);
    let resultList = getResult(start);
    // console.log(resultList);
    return resultList;
};

let copyList = function(currentNode){
    let start = currentNode;
    while(currentNode){
        let clonedNode = new Node();
        clonedNode.val = currentNode.val;
        clonedNode.next = currentNode.next;
        clonedNode.random = null;
        currentNode.next = clonedNode;
        currentNode = clonedNode.next;
    }
    return start;
}

let changeRandom = function(currentNode){
    let start = currentNode;
    while(currentNode){
        let clonedNode = currentNode.next;
        if(currentNode.random){
            clonedNode.random = currentNode.random.next;
        }
        currentNode = clonedNode.next;
    }
    return start;
}

let getResult = function(currentNode){
    // let start = currentNode;
    let clonedHead = null;
    let clonedNode = null;
    if(currentNode){
        clonedNode = clonedHead = currentNode.next;
        currentNode.next = clonedNode.next;
        currentNode = currentNode.next;
    }
    while(currentNode){
        clonedNode.next = currentNode.next;
        clonedNode = clonedNode.next;
        currentNode.next = clonedNode.next;
        currentNode = currentNode.next;
    }
    return clonedHead;
}
```