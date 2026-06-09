常规做法，先得到链表长度，确定中间节点的位置，移动指针到该位置即可。
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
    ListNode* middleNode(ListNode* head) {
        ListNode* ans=NULL;
        if(head==NULL){
            return ans;
        }
        int l = len(head);
        if(l%2==0){
            l=(l+1)/2;
        }else{
            l=l/2+1;
        }
        ans=head;
        while(l--){
            ans =ans->next;
        }
        return ans;
    }
    int len(ListNode* head){
        ListNode* p=head->next;
        int sum=0;
        while(p!=NULL){
            p=p->next;
            sum++;
        }
        return sum;
    }
};
```

![图片.png](https://pic.leetcode-cn.com/c05824a608e7f5f56b6f9f926bf7cc7e760d1201408e88e696ef1747706855cd-%E5%9B%BE%E7%89%87.png)
