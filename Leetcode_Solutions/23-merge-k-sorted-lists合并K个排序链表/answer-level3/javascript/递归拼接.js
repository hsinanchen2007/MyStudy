### 解题思路
此处撰写解题思路

### 代码

```javascript
var mergeKLists = function(lists) {
    if (!lists || !lists.length) return null;
    if (lists.length === 1) return lists[0];
    let head = {}, current, nodeList = [];
    function check(headList) {
      let minIndex = headList.length - 1, minNode = headList[minIndex];
      for (let i = headList.length - 2; i >= 0; i--) {
        if (headList[i]) {
          if (!minNode) {
            headList.splice(minIndex, 1);
            minNode = headList[i];
            minIndex = i;

            if (i === 0) {
              return head = minNode;
            }
            continue;
          }
          if (minNode.val > headList[i].val) {
            minNode = headList[i];
            minIndex = i;
          }
        } else {
          minIndex--;
          headList.splice(i, 1);
        }

      }
      if (!minNode) return head = null;
      if (!minNode.next) {
        headList.splice(minIndex, 1);
      } else {
        headList[minIndex] = headList[minIndex].next;
      }
      if (head.val === undefined) {
        head = minNode;
        current = head;
      } else {
        current.next = minNode;
        current = current.next;
      }

      if (headList.length) {
        check(headList);
      }
    }
    check(lists);
    return head;
  };
```