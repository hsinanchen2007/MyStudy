链表递归作和，和为数组，数组进位处理，最终转链表。

```
// 定义节点
class Node {
  constructor(val) {
    this.val = val;
    this.next = null;
  }
}
// 定义链表
class NodeList {
  constructor(arr) {
    const nodeList = [];
    const root = new Node(arr.shift());
    nodeList.push(root);
    arr.forEach((item, idx) => {
      const newNode = new Node(item);
      
      nodeList[idx].next = newNode;
      nodeList.push(newNode);
    });
    nodeList.length = 0;
    return root;
  }
}
// 进位运算
function pushDigit(arr, idx){
  const item = arr[idx];
  if(item === void 0){
	  return arr;
  }
  if(arr[idx] >= 10){
	  arr[idx] = item - 10;
	  (arr[idx + 1] !== void 0) ? ++arr[idx + 1] : arr.push(1);
  }
  return pushDigit(arr, idx + 1)
}
var addTwoNumbers = function(l1, l2) {
  const sumArr = [];
  // 作和
  function add(acc, item1, item2) {
    if(!item1 && !item2){
	    return acc;
    }
    item1 = item1 || {};
    item2 = item2 || {};
    acc.push(+(item1.val || 0) + +(item2.val || 0))
	  return add(acc, item1.next, item2.next)
  }
  add(sumArr, l1, l2);
  // 进位
  const result = pushDigit(sumArr, 0);
  // 转链表
  return new NodeList(result);
};
```