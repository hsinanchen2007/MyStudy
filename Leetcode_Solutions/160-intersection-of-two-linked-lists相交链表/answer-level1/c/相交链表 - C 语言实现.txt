> 编写一个程序，找到两个单链表相交的起始节点  

[160.两个链表的交点](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/)  

如果两个链表没有交点，返回 null.  
在返回结果后，两个链表仍须保持原有的结构。  
可假定整个链表结构中没有循环。  
程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。  

刚开始以为“相交”的意思是元素相等，后来看了测试用例才知道连ListNode都是一样的，也就是说交点及其以后的节点是同一个。  

思路：（偷别人的思路，我没想出来）链表有长有短，先循环两个链表计算出长度差，然后根据长度差让长的链表前进几个长度，这样他们就处于同一出发点开始循环了。  
循环判断节点是否相等，而不是节点的值是否相等。循环的终止条件是这两个指针相等，因为这两个指针一旦相等，就说明他们是同一个节点，所以他们后面的节点肯定相等。

```c

执行用时 :60 ms, 在所有 C 提交中击败了49.39%的用户  
内存消耗 :15.2 MB, 在所有 C 提交中击败了5.61%的用户  

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(headA == NULL || headB == NULL)return NULL;
    int lenA = 0;
    int lenB = 0;
    int cha = 0;
    struct ListNode *a = headA;
    struct ListNode *b = headB;
    while(a){
        a = a->next;
        lenA++;
    }
    while(b){
        b = b->next;
        lenB++;
    }
    while(lenA > lenB){
        headA = headA->next;
        lenA--;
    }
    while(lenA < lenB){
        headB = headB->next;
        lenB--;
    }
    while(headA != headB){
        headA = headA->next;
        headB = headB->next;
    }
    return headA;
}
```

看了看官方题解，有个双指针的解法，思路清奇，尝试了一下  
思路：双方从首元节点开始，循环，直到链表末尾，指向对方链表的首元节点，当短的那个链表也指向对方的首元节点后，你会发现这两个链表在从一起点上（不一定是同一个指针），如果他俩指向同一个地址，则这就是交点。其实这个思路和上面那个很像，都利用了长度差。  

唉？要是不存在交点，不就死循环了么？(不会的，因为当长链表也指向了短链表的首元节点，它俩处于同一出发点，然后就并排前进，如果中途没有交点，那么一直到NULL，它俩相等，退出循环。)

```c

执行用时 :60 ms, 在所有 C 提交中击败了49.39%的用户  
内存消耗 :15.2 MB, 在所有 C 提交中击败了5.61%的用户  

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(headA == NULL || headB == NULL)return NULL;
    struct ListNode *a = headA;
    struct ListNode *b = headB;
    while(a != b){
        a = a == NULL ? headB : a->next;
        b = b == NULL ? headA : b->next;
    }
    return a;
}
```
Emmm，执行用时和内存消耗差不多，直来直去多好，就当扩展思路学习一下。
