连续的序列区间段，一般第一想法就是滑动窗口、双指针这些概念。然后基于此，就可以来构思代码了。
首先，初始化头尾指针，按照我的思维习惯，我喜欢从后往前遍历，由于题目说区间至少有2个值，所以初始化头指针head=target-2,尾指针tail=target-1。然后进行循环，循环结束的条件是，头指针到0。
每一次移动头尾指针，都需要计算一下区间和。这是就有3种情况：
1. 区间和大于target值，那么尾指针需要前移，将区间和变小。
2. 区间和小于target值，将头指针前移，尾指针不变，增加区间元素，将区间和变大。
3. 区间和等于target值，放入结果数组，然后头尾指针都前移一位。

```javascript
/**
 * @param {number} target
 * @return {number[][]}
 */
var findContinuousSequence = function(target) {
  var head = target - 2;
  var tail = target - 1;
  var ans = [];
  while (head > 0) {
    var sum = 0;
    for (var i = head; i <= tail; i++) {
      sum += i;
    }
    if (sum > target) {
      tail--;
    }
    if (sum == target) {
      var list = [];
      for (var j = head; j <= tail; j++) {
        list.push(j);
      }
      ans.unshift(list);
      head--;
      tail--;
    }

    if (sum < target) {
      head--;
    }
  }
  return ans;
};

```
