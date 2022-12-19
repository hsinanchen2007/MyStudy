三种方式
第一种
暴力。对于A中每一个都去B遍历
```
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while(headA)
        {
            auto pt = headB;
            while(pt)
            {
                if(headA == pt)
                    return pt;
                pt = pt->next;
            }
            headA = headA->next;
        }
        return headA;
    }
};
```
第二种
哈希表
把A的放入哈希表，对于B中每一个去哈希表中找
```
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> s;
        while(headA)
        {
            s.insert(headA);
            headA = headA->next;
        }
        while(headB)
        {
            if(s.find(headB) != s.end())
                return headB;
            headB = headB->next;
        }
        return headA;
    }
};
```
第三种，利用两个指针
原理在于指针走的距离相等
```
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto a = headA, b = headB;
        while(a != b )
        {
            a = a? a->next:headB;
            b = b? b->next:headA;
        }
        return a;
    }
};
```

还写了一些别的leetcode的题解，分享一下看看有没有需要的，题解还会更新：[https://www.yuque.com/books/share/300e07be-6fc9-417d-bb05-c50f5dea1618?#](https://www.yuque.com/books/share/300e07be-6fc9-417d-bb05-c50f5dea1618?#)
顺带给自己推一波公众号，要是有兴趣可以关注：**麦芽糖的笔记本**
![image.png](https://pic.leetcode-cn.com/95c54eba219d34f176350f6968ff8d934a93879a43a12f926b2e05148b5833ca-image.png)

公众号回复**LC**，可以下载题解的pdf版本，pdf也会更新

![image.png](https://pic.leetcode-cn.com/a533ef6e9a37396c93e0d965e5ef389996a90e8c5b6a05d35aa19d918dcf8b86-image.png)
