执行用时 :140 ms, 在所有 JavaScript 提交中击败了99.60%的用户
内存消耗 :38.8 MB, 在所有 JavaScript 提交中击败了32.57%的用户
```
var addTwoNumbers = function(l1, l2) {
    let result = new ListNode();
    let node = result;
    let jinwei = false; // 进位
    // 如果有进一位的，还要再执行一遍
    while(l1 || l2 || jinwei) {
        let num = (l1 ? l1.val : 0) + (l2 ? l2.val : 0);
        if (jinwei) num += 1;
        jinwei = num > 9;
        // 大于等于10取个位数
        num = num % 10;
        l1 && (l1 = l1.next);
        l2 && (l2 = l2.next);
        node = node.next = new ListNode(num);
    }
    return result.next;
};
```

