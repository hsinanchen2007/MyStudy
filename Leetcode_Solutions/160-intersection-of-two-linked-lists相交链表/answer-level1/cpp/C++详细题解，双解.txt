## 解法一
### 思路
暴力法，快慢指针，一个指针在A链表，一个指针在B链表，逐一遍历两个链表，比较节点的位置，若位置相交，返回任意一个地址（两者指向位置相同） 这个方法比较容易想到，但是使用了两个`while`循环，时间复杂度非常高O(n^2)。
```
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)    return nullptr;
        while (headA)
        {
            ListNode *temp = headB;
            if(headA == temp)  return headA;
            while(!(temp -> next == nullptr))
            {
                temp = temp -> next;
                if(headA == temp)  return headA;
            }
            headA = headA -> next;
        }
        return nullptr;
    }
};
```
## 解法二
### 思路
这个方法比较巧妙，时间复杂度较低O(n)
1. 假设两条链表有交点，可知相交部分等长
2. 那么交点位置距离链表尾的距离必小于等于较短的链表
3. 先将较长的链表剪去前面部分，使其的长度等于较短的链表
4. 此时将指针从当前的headA 和headB同时向后移动，且对比指针是否相同，若相同则输出指针。


```
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)    return nullptr;
        ListNode *countA = headA;
        ListNode *countB = headB;
        int lA = 0;
        int lB = 0;
        while(countA){
            ++ lA;
            countA = countA -> next;
        }
        while(countB){
            ++ lB;
            countB = countB -> next;
        }
        int i = max(lA,lB) - min(lA,lB);
        if(lA > lB) for(i; i > 0; -- i) headA = headA -> next;
        else    for(i; i > 0; -- i) headB = headB -> next;
        while(headA){
            if(headA == headB)  return headA;
            headA = headA -> next;
            headB = headB -> next;
        }
        return nullptr;
    }
};
```