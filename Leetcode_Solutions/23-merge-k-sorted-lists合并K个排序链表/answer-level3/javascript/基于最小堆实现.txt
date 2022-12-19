### 解题思路
链表x, headerX指向其下一个要被遍历的节点；
每次需要从[header1, header2, ..., headerX]中找出最小值，并放置在结果链表中。
可以借助二叉最小堆实现。

堆的存储方式为数组[undefined, 1, 2, ...]，下标从1开始。这样的话，下标i的左子(若存在)为2i, 右子(若存在)为2i+1(也可以从0开始存储，保证父子之间的映射逻辑正确即可);

伪代码过程：
1. 对各链表头建堆，建堆过程为不断的插入值并上滤的过程。
2. 遍历堆，直到堆为空(length === 1)
   1. 重复取堆顶min, 并将min.next补位至堆顶，然后下滤；
   2. 若min.next为空，则将堆尾元素补位至堆顶，然后下滤。 

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
 * @param {ListNode[]} lists
 * @return {ListNode}
 */
var mergeKLists = function(lists) {
  const l = lists ? lists.length : 0;
  if(l === 0) return null;
  if(l === 1) return lists[0];

  const heap = [undefined];
  for(let i=0; i<l; i++){
    const node = lists[i];
    if(node){
      insertHeap(heap, node);
    }
  }

  const node = new ListNode();
  let now = node;
  while(heap.length>1){
    now.next = deleteMin(heap);
    now = now.next;
  }

  return node.next;
};

/**
 * @param {ListNode} another
 * @return {number}
 */
ListNode.prototype.compareTo = function(another){
  return this.val - another.val;
}

/**
 * @param {ListNode[]} heap
 * @param {ListNode} node
 * @return {ListNode[]}
 */
const insertHeap = (heap=[undefined], node) => {
  heap.push(node);

  let hole = heap.length-1;
  for(;hole>1;){
    const parent = Math.floor(hole/2);
    if(node.compareTo(heap[parent])<0){
      heap[hole] = heap[parent];
      hole = parent;
      continue;
    }
    break;
  }
  heap[hole] = node;
}

const topDown = (heap=[undefined], start=1) => {
  const l=heap.length, node = heap[start];
  let hole = start;
  for(let child = 2*hole; child<l; child = 2*hole){
    if(child<l-1 && heap[child].compareTo(heap[child+1])>0) child++;
    if(node.compareTo(heap[child])>0){
      heap[hole] = heap[child];
      hole = child;
      continue;
    }
    break;
  }

  heap[hole] = node;
}

const deleteMin = (heap=[undefined]) => {
  const l = heap.length;
  if(l <= 1) return null;

  const min = heap[1];
  let supply = min.next;
  if(!supply){
    supply = heap.pop();
    if(l===2) return min;
  }
  

  heap[1] = supply;
  topDown(heap, 1);
  return min;
}
```