### 解题思路
双指针A,B，如果两个链表长度相等，那么我们让A,B同时以相同速度往前走，要么相交，要么同时到达末尾也没有相交
题目两链表长度不一定相等的，所以我们需要想办法让其相等
方法一，都走一篇计算长度，然后让长的先走一段，然后两链表一起走
方法二，都走length(A)+length(B)的长度，走完一个链表以后走另一个链表
注意链表为null的情况和没有交点的情况

### 代码

```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
var getIntersectionNode = function(headA, headB) { 
    //双指针A,B，如果两个链表长度相等，那么我们让A,B同时以相同速度往前走，要么相交，要么同时到达末尾也没有相交
    //题目两链表肯定是不相等的，所以我们需要想办法让其相等
    //方法一，都走一篇计算长度
    //return method1(headA,headB)
    //方法二，都走length(A)+length(B)的长度，走完一个链表以后走另一个链表
    return method2(headA,headB)
};
//方法一，都走一篇计算长度
var method1=function(headA,headB){
    let tA=headA;
    let tB=headB;
    //计算A,B的长度
    let lengthA=0;
    let lengthB=0;
    while(headA){
        headA=headA.next
        lengthA++
    }
    while(headB){
        headB=headB.next
        lengthB++
    }
    console.log(lengthA)
    console.log(lengthB)
    headA=tA
    headB=tB
    //链表长的多走几步
    for(let i=0;i<Math.abs(lengthA-lengthB);i++){
        if(lengthA>lengthB){
            headA=headA.next
        }else{
            headB=headB.next
        }
    }
    //同时走，判断相交
    while(headA){
        if(headA===headB) return headA
        headA=headA.next
        headB=headB.next
    }
    return null
}

//方法二，都走length(A)+length(B)的长度，走完一个链表以后走另一个链表
var method2=function(headA,headB){
    let tA=headA;
    let tB=headB;
    //终止条件
    let canChangeA=true
    let canChangeB=true
    while(headA && headB){
        if(headA===headB) return headA
        //headA往前走
        if(!headA.next && canChangeA){
            headA=tB
            canChangeA=false
        }else{
            headA=headA.next
        }
        //headB往前走
        if(!headB.next  && canChangeB){
            headB=tA
            canChangeB=false
        }else{
            headB=headB.next
        }
    }
    return null;
}
```