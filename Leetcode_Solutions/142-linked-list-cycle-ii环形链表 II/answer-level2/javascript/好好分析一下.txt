个人觉得，官方题解关于双指针的判断，其实是有些问题的，没有考虑得很全面

这题需要分两步走，先判断是否有环，再找出环的入口
**1. 判断单链表是否有环**
设定快指针p2和慢指针p1，快指针每次走两格，慢指针每次走一格
如果有环，则两格指针终将会有相遇的时候 p1 == p2
如果没有环，肯定是p2为null了

**2. 找出环的入口**
p2走的距离是p1的2倍，举个栗子

![image.png](https://pic.leetcode-cn.com/84c9961569cc705c35e353fe287ec3e5f190fd735965c028a5c92b45a4aa1011-image.png)
在这个图中，起始点是3，环的入口是2，相遇点是-4，
a为起始点到入口点的距离，b为入口点到相遇点的距离，c为相遇点折返回入口点的距离
根据两倍的距离关系，可以先得到
// 两倍p1路径距离 = 实际p2的路径距离,n为p2经过相遇点后，又继续走的圈数，比如这里是1
2(a + b) = a + b + n(c + b)
a + b = n(c + b)
**a = nc + (n - 1)b**
公式的右边，可以认为是从相遇点-4走n圈的距离（从点-4回退到点2，再开始走圈就理解了）
所以我们再放两个指针po1和po2，po1从起始点走，po2从相遇点走，速度一致
当po1走到了入口点2，po2也刚好走了n圈到入口点2，一起循环一下就行了

当然了，嫌麻烦的话，也可以不管上面的公式
直接从起始点出发，一个一个地判断在不在环里面就行，只是会多耗一些时间
或者，连指针这些都不用了，直接用Map记录访问过的节点，更简便哈哈哈

```
var detectCycle = function(head) {
    if (!head || !head.next) {
        return null;
    }
    
    var p1 = head.next;
    var p2 = head.next.next;
    while (p1 && p2 && p2.next && p1 != p2) {
        p1 = p1.next;
        p2 = p2.next.next;
    }
    
    if (!p2 || !p2.next) {
        return null;
    }
    
    // return p2
    var h = head;
    while (h != p2) {
        // var node = inCircle(p2, h);
        // console.log(h,node)
        // if (node) {
        //     return node;
        // };
        
        h = h.next;
        p2 = p2.next;
    }
    
    return p2;
};

function inCircle(circle, node) {
    if (circle == node) {
        return node;
    }
    
    var p = circle.next;
    while (p && p != circle) {
        if (p == node) {
            return node;
        }
        
        p = p.next;
    }
}
```

