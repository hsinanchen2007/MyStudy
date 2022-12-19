# JavaScript 反转链表解法
热爱JavaScript的JSer，走过路过不要错过嗷，一起来看看JS的链表反转吧😊

## 非递归解法
第一种解法是采用while循环实现节点的遍历，从而进一步达到改变后驱反转链表的效果

```
var reverseList = function(head) {
    // 首先判断是否为空链表或者只有一个元素的链表的情况
    if(head === null || head.next === null) return head;

    // 初始化... 从头指针开始进行操作，初始化一个前驱元素
    let currentNode = head;
    let preNode = null;

    // 开始循环操作，直到尾指针结束循环
    while(currentNode) {
        let next = currentNode.next;  // 保存当前‘遍历’到的节点下一个节点
        currentNode.next = preNode; // 开始反转链表方向
        preNode = currentNode;  // 为下一个节点的指向调转做准备
        currentNode = next;  // 移动到下一个节点
    }

    return preNode;  // 返回反转后的头指针
};
```

第一种方法真的很简单很容易去想，所以就注释写了写...

## 递归解法
接下来使我们简洁优雅的递归调用。
递归首先要注意两点：1、递归结束条件 2、函数的自调用
先上代码😆

```
var reverseList = function(head) {
    if( head === null || head.next === null ) return head; 

    let next = head.next;
    let newList = reverseList(head.next);

    head.next = null;
    next.next = head;

    return newList;
};
```

首先我们先来看第一个点：
```
    if( head === null || head.next === null ) return head; 
```

在刚刚 while 解法中，我们也有这一段代码，那个时候我们是用来判断是否为空链表或者只有一个元素的链表的情况，在递归解法中还有一个作用是满足递归的结束条件。
while 循环整体上的感觉是 **从头进行操作一直到尾部**
而递归解法是**先不断递归找到尾部，然后从尾部开始反转直到头部**
从整体上我们就能大致判断出递归调用的性能并不高于我直接使用while
但是，递归优雅呀，简洁精炼。

由于递归写法精炼的特性，尝尝会伴着某些操作晦涩难懂，所以接下来的操作采用手绘图的形式演示：

![1.jpg](https://pic.leetcode-cn.com/8abf6b4351db8548531a2f63d3749d763db4191f8dd444ad3750e2fef73d28ea-1.jpg)

![2.jpg](https://pic.leetcode-cn.com/d66a3ebaa8f5eb88017a39db913b32a4abed66d040f286a3a0eeae16e9b1ea90-2.jpg)

我觉得应该很详细了吧？？如果还不懂得话就是我太菜了讲不清楚😥语文真的很重要！！！

最后祝天天开心，Code越来越优雅，解题越来越顺利😝