### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/d14173f78ed18006a9019591df918baaac666ff29d770f9033ed09dbb24eb155-image.png)


### 代码

```cpp
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if( !head ){
            return NULL;
        }
        ListNode pHead = ListNode(0);
        pHead.next = head;
        ListNode* fp = head;
        ListNode* sp = head;
        ListNode* lp = head;
        int length = 0;
        while(lp) {
            ++length;
            lp = lp->next;
        }
        k = k % length;
        if (k == 0){
            return head;
        }
        for (int i = 0; i < k; i++) {
            fp = fp->next;
        }
        while(fp->next){
            fp = fp->next;
            sp = sp->next;
        }
        pHead.next = sp->next;
        sp->next = NULL;
        fp->next = head;
        
        return pHead.next;
    }
};

```