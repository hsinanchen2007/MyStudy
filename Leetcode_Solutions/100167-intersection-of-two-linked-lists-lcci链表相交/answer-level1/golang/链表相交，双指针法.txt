# [面试题 02.07. 链表相交](https://leetcode-cn.com/problems/intersection-of-two-linked-lists-lcci/)

## 题目描述

给定两个（单向）链表，判定它们是否相交并返回交点。请注意相交的定义基于节点的引用，而不是基于节点的值。换句话说，如果一个链表的第k个节点与另一个链表的第j个节点是同一节点（引用完全相同），则这两个链表相交。



## 思路

- 思路一，长链表砍头后一起走，本质上和思路二差不多。先得到两个链表的长度，然后长的链表的指针从头往前走一段，使得剩下的长度和短的相同，然后一起往后走，如果链表有相交的话那么两个指针一定会在交点相遇。

- 思路二，两个链表拼接后一起走。指针1遍历链表A+B，指针2遍历链表B+A，两个指针一起走，如果链表有相交则两个指针一定在交点相遇。下面`+`代表链表A的结点，`-`代表链表B的结点，`*`代表公共结点。

  ```
  A和B长度不同：
  A+B:++++++****---****
  B+A:---****++++++****
  
  A和B长度相同：
  A+B:+++****---****
  B+A:---****+++****
  ```



## 代码

- 思路一，长链表砍头后一起走。

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getIntersectionNode(headA, headB *ListNode) *ListNode {
    // 双指针法
    if headA == nil || headB == nil {
        return nil
    }
    pA, pB := headA, headB
    lenA, lenB := 0, 0
    for pA != nil {
        pA = pA.Next
        lenA++
    }
    for pB != nil {
        pB = pB.Next
        lenB++
    }

    pA, pB = headA, headB
    var cut int = 0
    if lenA > lenB {
        cut = lenA-lenB
        for i:=0; i<cut; i++ {
            pA = pA.Next
        }
    }else{
        cut = lenB-lenA
        for i:=0; i<cut; i++ {
            pB = pB.Next
        }
    }

    for pA != nil {
        if pA == pB {
            return pA
        }
        pA = pA.Next
        pB = pB.Next
    }
    return nil
}
```

- 思路二，两个链表拼接后一起走。

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getIntersectionNode(headA, headB *ListNode) *ListNode {
    if headA==nil || headB==nil {
        return nil
    }
    pA, pB := headA, headB
    for pA != pB {
        if pA==nil {
            pA = headB
        }else{
            pA = pA.Next
        }

        if pB==nil {
            pB = headA
        }else{
            pB = pB.Next
        }
    }
    return pA
}
```



