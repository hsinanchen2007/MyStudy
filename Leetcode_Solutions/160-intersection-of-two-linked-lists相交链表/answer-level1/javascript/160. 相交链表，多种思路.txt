# 暴力法
双层循环寻址，逐一对比指针
```
var getIntersectionNode = function(headA, headB) {
    if (headA == null || headB == null)  return null;
    let curA = headA;
    while(curA){
          let curB = headB
          while(curB){
                if(curA == curB) return curA;
                curB = curB.next;
          }
        curA = curA.next;
    }
    return null;
};
```
# 缓存指针
开辟一个set用以存储一条链表中的指针，遍历另一条链表查找指针是否相等
```
var getIntersectionNode = function(headA, headB) {
    if (headA == null || headB == null)  return null;
    let curA = headA,curB = headB;
    let set = new Set();
    while(curA){
        set.add(curA);
        curA = curA.next;
    }
    while(curB){
        if(set.has(curB)) return curB;
        curB = curB.next;
    }
    return null;
};
```
# 假设探环
将任意一链表收尾相连构成环，问题转化为环形链表查找入环节点
```
var getIntersectionNode = function(headA, headB) {
    if (headA == null || headB == null)  return null;
    let curA = headA,curB = headB;
    while(curA.next != null){
        curA = curA.next;
    }
    curA.next = headA;
    let fast = headB,slow = headB;
    while(fast != null&&fast.next != null){
          slow = slow.next;
          fast = fast.next.next;
          if(slow == fast){
             slow = headB;
             while(slow != fast){
                 slow = slow.next;
                 fast = fast.next;
            }
              curA.next = null;
              return fast;
          }
    }
    curA.next = null;
    return null;
};

```
# 双指针
单纯双指针可以理解为，将两支链表AB，BA收尾想接。
若两支链表有交点，各链表各有至少两个该交点，然后必然会有一个交点在出现在相同位置；
若两支链表无交点，生成两支链表最后遍历到末尾同时指向null，遍历结束，返回null。
```
var getIntersectionNode = function(headA, headB) {
    let pA = headA;
    let pB = headB;
    while(pA != pB){
        pB = pB? pB.next: headA;
        pA = pA? pA.next: headB;
    }
    return pA;
};
```
