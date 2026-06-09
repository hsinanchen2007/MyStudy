

![sendpix1.jpg](https://pic.leetcode-cn.com/a5d237f1f7a7c0379fb414870a335463085cf24b1e2246da8704d87ff10d9def-sendpix1.jpg)
思路：
    先实现同时遍历两个链表，这里我使用的是递归思路

    实现遍历链表之后再进行加法操作，超过10进1

    最后考虑边界情况 + 优化代码
```
var addTwoNumbers = function(l1, l2) {
    function getNum(node1, node2, res, pre) {
        let total = res.val;
        let n1 = 0,n2 = 0;
        if (!node1 && !node2) {
            if (res.val === 0 && pre) {
                pre.next = null
            }
            return
        }
        node1? n1 = node1.val: node1 = {next: null}; 
        node2? n2 = node2.val: node2 = {next: null};
        total +=  n1 + n2;
        let newNode = new ListNode(0);
        if (total >= 10) {
            total -= 10;
            newNode.val++
        }
        res.val = total;
        res.next = newNode;
        getNum(node1.next, node2.next, res.next, res)
    }
    let num = new ListNode(0)
    getNum(l1,l2, num, null)
    return num;
};
```

