### 解题思路
借用二楼的图说明哈 ，在此感谢！
一，想象哈两个人同时从如图跑道1，跑道二起跑
二，如果两个链表相交点的可能在于第二根分界线起跑，边跑便比较，如果相等就退出跑道返回结点
三，问题在于如何消除长度差，两者从第二根分解线起跑呢？？？
四，不难理解，当较短的headB跑到自己的终点（第一跟分界线），此时headA也在分界线处，此时让headB从A道继续跑，
终有一个时刻headA到自己的终点，就跟换跑道B,此时headB还在长的A到中，但是这时都到了同一可能出现交点的道路上了，
返回短的那个指针就可以了，   仔细看图结合代码就能看懂，写个题解以后自己回顾！！！！

（还有一个思想就是利用栈，但是有些案例通不过：厉害的看我评论把它完善）
![image.png](https://pic.leetcode-cn.com/85bea58adfb5b46651376233564c7d19bd5a84efbe09bd0d71b811e2044d3443-image.png)


### 代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
         if (headA == NULL || headB == NULL) return NULL;

       ListNode *pa=headA;
       ListNode *pb=headB;
       while(pa!=pb)
       {
           if(pa==NULL)
           pa=headB;
           else
           pa=pa->next;

           if(pb==NULL)
           pb=headA;
           else
           pb=pb->next;
       }
       return pa;


    }
};
```