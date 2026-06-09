## 读题时间（5min）

给定链表的头结点，自己去遍历判断判断表中是否有环

## 初步思路

1. 如何循环判断结束点？

> 无法通过结点的值来判断结束（因为存在结点值相同的情况）

> 必须通过对象地址相同进行比对（weakSet集合）

### 深度思考

看到执行结果的我……
![image.png](https://pic.leetcode-cn.com/93e92291b12845e6883815003ccb3f9b477be170699b092cd527309358ae3e82-image.png)

我到底忽略了神马线索？？？

于是我乖乖去找题解……

## 题解学习

**没有注意的细节**

1. 在202.快乐数中，我对于官方的弗洛伊德循环查找算法（我觉得就是所谓的双指针法）感觉很鸡肋…… 嗯 现在打脸了……
2. 既然无法通过结点的值来判断结束，为啥不能设计一种可以通过值判断结束的呢？Symbol

## 代码解析

### 方法一： 哈希算法

用一个WeakSet集合在存储每一个结点的值

通过判断对象是否是同一个引用来确定是否进行了循环

**算法：**

```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {boolean}
 */
var hasCycle = function(head) {
    if (!head) return false
    let next = head
    const weakset = new WeakSet()
    let flag = true
    while(true) {
        if (weakset.has(next)) break;
        weakset.add(next)
        if (!next.next) {
            flag = false
            break;
        }
        next = next.next
    }
    return flag
};
```

**复杂度分析：**

时间复杂度：O(n)
空间复杂度：O(n)

**执行结果**

![image.png](https://pic.leetcode-cn.com/09356a0f7cd1db0c51390e69434cc764561a16bdfcc2ba25a126a358c98048d7-image.png)

## 方法二：双指针法

这里巧妙地利用一下try/catch来跳出循环

**算法：**

```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {boolean}
 */
var hasCycle = function(head) {
    try {
        let slow = head
        let fast = head.next
        while(true) {
            if (slow === fast) return true
            slow = slow.next
            fast = fast.next.next
        }
    }
    catch(e) {
        return false
    }
};
```


**复杂度分析：**

时间复杂度：O(n)
空间复杂度：O(1)

**执行结果**

![image.png](https://pic.leetcode-cn.com/2ff5d35797e49083378b280bf43811efc8eb843f2a95a481b16c301c6b51fcaa-image.png)

## 方法三： 结点值替换法

最最最稳妥的替换方式是用Symbol

但我想哈，生成唯一不被替换的值，这本身是否也需要成本，因此在实际过程中，可以用一段随机无意义的字符串来取代～

**算法：**

```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {boolean}
 */
var hasCycle = function(head) {
    const flag = 'wojquiyigetmcl'
    while(head) {
        if (head.val === flag) return true
        head.val = flag
        head = head.next
    }
    return false
};
```

**复杂度分析：**

时间复杂度：O(n)
空间复杂度：O(1)

**执行结果**

![image.png](https://pic.leetcode-cn.com/62bf8684d4254acde9a75e97b3b639da806dc3f06110cf28d963e9650a7651eb-image.png)




