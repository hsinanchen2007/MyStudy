```
var addTwoNumbers = function(l1, l2) {
    var l1Node = l1
    var l2Node = l2
    var args = [] // 存储对应的位置相加的结果
    var needAdd1 = 0
    // 先不考虑进位，对应的链表每一位相加
    while(l1Node||l2Node) {
        // 考虑两个链表长度不同的情况
        // var val1 = l1Node && l1Node.val || 0
        // var val2 = l2Node && l2Node.val || 0
        var val1 = l1Node ? l1Node.val : 0
        var val2 = l2Node ? l2Node.val : 0
        var temp = val1 + val2
        args.push(temp)
        l1Node && (l1Node = l1Node.next)
        l2Node && (l2Node = l2Node.next)
    }
    // 考虑进位的问题
    for (let i = 0; i < args.length; i++) {
        if(args[i] > 9) {
            args[i] -= 10
            if (args[i+1] === undefined) {
                args[i+1] = 1
            } else {
                args[i+1] += 1
            }
        }
    }
    // 把数组转成成链表(递归)
    function createList (...argu) {
         if (argu.length > 0) {
                var nodeStart = new ListNode(argu[0])
                argu.shift()
                nodeStart.next = createList(...argu)
                return nodeStart
            } else {
                return null
            }
    }
    
    return createList(...args)
};
