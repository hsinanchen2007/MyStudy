解题思路：
1. 将链表转化成数字，测试用例中有超过Number精度的数字，所以用BigInt类型
2. BigInt 之间运算
3. 再转换成逆序链表

这种方法稍加改造，就能适配正序的链表

```javascript
var addTwoNumbers = function(l1, l2) {
  const value1 = getLinkListValue(l1);
  const value2 = getLinkListValue(l2);
  return setLinkListValue(value1 + value2);
};

// 将链表转换成数字
function getLinkListValue(listNode) {
  let numString = "";
  while (listNode !== null) {
    numString = listNode.val + numString; // 逆序
    // numString = numString + listNode.val; // 正序
    listNode = listNode.next;
  }
  return BigInt(numString);
}
// 将数字转换成链表
function setLinkListValue(num) {
  return num
    .toString()
    .split("")
    .reverse() // 正序注释该行
    .map(value => new ListNode(value))
    .map((listNode, index, list) => {
      const nextIndex = index + 1;
      if (nextIndex < list.length) {
        listNode.next = list[nextIndex];
      }
      return listNode;
    })[0];
}
```
