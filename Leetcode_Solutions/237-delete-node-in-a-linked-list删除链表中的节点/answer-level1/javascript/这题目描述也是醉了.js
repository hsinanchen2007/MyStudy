
题目描述真的是无力吐槽,对,我理解能力有问题.
其实,链表删除一项,其实就是把当前一项的val替换成下一项val,下一项的next替换成下一项的next,
这样当前项就消失了

```
var deleteNode = function(node) {
    node.val = node.next.val
    node.next = node.next.next
};
```
