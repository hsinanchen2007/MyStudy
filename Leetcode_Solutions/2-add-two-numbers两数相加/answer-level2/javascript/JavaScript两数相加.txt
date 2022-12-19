#### 思路
1. 新建一个链表`root`； 
2. 从`l1`、`l2`表头开始，依次相加得到`sum`，如果`sum > 9`就向后一位进`1`；
3. 新建一个`val = sum % 10`的节点添加到`root`上；
3. 如果最后一次相加的结果满`10`，需要额外添加一个值为`1`的节点。
#### 代码
```
var addTwoNumbers = function(l1, l2) {
    // 新建root
    let root = new ListNode(0);
    // 指针指向root头
    let pointer = root;
    // 标识是否有进1，取值0或者1
    let mark = 0;
    while (l1 || l2) {
        let sum = mark + (l1 ? l1.val : 0) + (l2 ? l2.val : 0);
        // 计算是否有满10进1，如果有下一次val相加要再加1
        mark = parseInt(sum / 10);
        // 创建下一个节点
        let nextNode = new ListNode(sum % 10);
        // 追加nextNode
        pointer.next = nextNode;
        pointer = pointer.next;
        // 遍历l1、l2
        if (l1) {
            l1 = l1.next;
        }
        if (l2) {
            l2 = l2.next;
        }
    }
    // 处理最后一次相加结果有进1的情况
    if (mark === 1) {
        pointer.next = new ListNode(1);
    }
    return root.next;
};
```
#### 优化思路
1. 如果遇到两个链表长度相差很大的情况，例如：`l1 = [1,0,0,0,0,0,0,0,0,0,1]; l2 = [2,3]`；
2. **当长度小的链表最后一个数相加后，且结果没有满`10`**，就不需要再依次相加下去，只需要将还未处理的数据添加到链表尾部即可；
3. 例如：当`l2`的最后一个数相加后，结果为`3 + 0 < 10`，直接将`l1`剩下的数据`0,0,0,0,0,0,0,0,1`追加即可。
#### 代码
```
var addTwoNumbers = function(l1, l2) {
    // 新建root
    let root = new ListNode(0);
    // 指针指向root头
    let pointer = root;
    // 标识是否有进1，取值0或者1
    let mark = 0;
    while (l1 || l2) {
        let sum = mark + (l1 ? l1.val : 0) + (l2 ? l2.val : 0);
        // 计算是否有满10进1，如果有下一次val相加要再加1
        mark = parseInt(sum / 10);
        // 创建下一个节点
        let nextNode = new ListNode(sum % 10);
        // 追加nextNode
        pointer.next = nextNode;
        pointer = pointer.next;
        // 遍历l1、l2
        if (l1) {
            l1 = l1.next;
        }
        if (l2) {
            l2 = l2.next;
        }
        // 优化，减少处理次数
        if (!l2 && mark === 0) {
            pointer.next = l1;
            return root.next;
        }
        if (!l1 && mark === 0) {
            pointer.next = l2;
            return root.next;
        }
    }
    // 处理最后一次相加结果有进1的情况
    if (mark === 1) {
        pointer.next = new ListNode(1);
    }
    return root.next;
};
```
