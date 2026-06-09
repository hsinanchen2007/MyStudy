### 解题思路
方法一：先遍历A链表，哈希存储A链表，然后遍历链表B，逐一比较。时间复杂度O(m+k)，空间复杂度(m),其中m为A链表长度，k为交叉点的位置。
方法二：将链表首尾相接成AB&BA的形式，两种遍历会**同时到达尾结点然后停止**，中途如果结点相等则返回。(停止条件挺巧妙的，书写的时候总以为会无限循环下去)

### 代码
方法一：循环方法
```javascript
var getIntersectionNode = function (headA, headB) {
    if (!headA || !headB) return null
    let mapA = new Map();
    while (headA) {
        mapA.set(headA, headA.val);
        headA = headA.next;
    }
    while (headB) {
        if (mapA.has(headB)) return headB
        headB = headB.next;
    }
    return null
};
```

方法二：AB&BA双指针遍历法
```javascript
var getIntersectionNode = function (headA, headB) {
    if (!headA || !headB) return null
    let A = headA, B = headB;
    while (A !== B) {
        A = A ? A.next : headB;
        B = B ? B.next : headA;
    }
    return A
};
```