## 1、暴力破解

逻辑比较简单，遍历链表A的每一个节点时遍历B寻找相交点。

时间复杂度O(m*n), 空间复杂度O(1).

代码：

```java
public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
    if (headA == null || headB == null) return null;
    ListNode initialHeadB=headB;
    while (headA != null){
        while (headB != null){
            if (headA.equals(headB)) return headA;
            headB=headB.next;
        }
        headA = headA.next;
        headB = initialHeadB;
    }
    return null;  
}
```



## 2、哈希表

建立一个哈希表，遍历链表A获得保存所有结点。然后遍历B的每一个节点判断哈希表中是否存在，返回第一个存在结点为相交节点。

时间复杂度O(m+n)，空间复杂度O(1).

代码：

```java
public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
    if (headA == null || headB == null) return null;
    HashSet hA = new HashSet();
    while (headA != null) {
        hA.add(headA);
        headA = headA.next;
    }
    while (headB != null) {
        if (hA.contains(headB)) return headB;
        headB = headB.next;
    }
    return null;
}
```



## 3、双指针法

设立两个指针，指针A先遍历headA，直到headA为空后转去headB。而指针B，先遍历headB ,然后转去headA遍历。最后当指针A和B相等时，返回相交结点或者null。

这里最难想到的： skipA +skipB = skipB +skipA, 即便不想交，最后也会同时指向null。

时间复杂度最大O(m+n), 空间复杂度O(1).

代码：

```java
public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
    ListNode hA = headA;
    ListNode hB = headB;
    while (hA!=hB){
        hA = (hA==null? headB: hA.next);
        hB = (hB==null? headA: hB.next);
    }
    return hA;
}
```

