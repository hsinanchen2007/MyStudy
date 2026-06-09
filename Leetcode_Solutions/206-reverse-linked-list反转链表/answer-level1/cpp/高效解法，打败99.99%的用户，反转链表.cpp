![image.png](https://pic.leetcode-cn.com/2eb1b22e3797aa2666898586a7f9382467be0c707074f2602b2a696432316152-image.png)
用三个相邻的指针从前往后移
```c++
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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)
            return NULL;
        ListNode *prePtr = NULL, *curPtr = head, *nextPtr=head->next;
        while(nextPtr != NULL){
            curPtr->next = prePtr;
            prePtr = curPtr;
            
            
            curPtr = nextPtr;
            nextPtr = nextPtr->next;
        }

        curPtr->next=prePtr;
       
        return curPtr;  
    }
};
```

左下角可以免费点赞，或者可以关注[知乎@司南牧](https://www.zhihu.com/people/yuanmuou/activities)