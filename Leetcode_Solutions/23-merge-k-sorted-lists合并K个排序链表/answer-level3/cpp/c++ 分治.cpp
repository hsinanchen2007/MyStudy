### 解题思路
参考了[前辈](https://leetcode-cn.com/problems/merge-k-sorted-lists/solution/he-bing-kge-pai-xu-lian-biao-by-leetcode/)的代码，只是后面那一点我觉得在面试的时候我还是习惯我这种写法。

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
    ListNode* mergeTwoLists(ListNode* l1,ListNode* l2){
        ListNode* dummyNode1 = new ListNode(INT_MIN);
        ListNode* dummyNode2 = new ListNode(INT_MIN);
        ListNode* dummyNode3 = new ListNode(INT_MIN);
        dummyNode1->next = l1;
        dummyNode2->next = l2;
        ListNode* ptr1 = dummyNode1;
        ListNode* ptr2 = dummyNode2;
        ListNode* now = dummyNode3;
        while(ptr1!=NULL && ptr2!=NULL){
            if(ptr1->val<ptr2->val){
                now->next = ptr1;
                ptr1 = ptr1->next;
            }else{
                now->next = ptr2;
                ptr2 = ptr2->next;
            }
            now = now->next;
        }
        if(ptr1==NULL) now->next = ptr2;
        if(ptr2==NULL) now->next = ptr1;
        now = dummyNode3->next->next->next;
        delete dummyNode3;
        delete dummyNode2;
        delete dummyNode1;
        return now;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0) return NULL;
        vector<ListNode*> new_lists;
        while(lists.size()!=1){
            for(int i=1;i<n;i=i+2){
            new_lists.push_back(mergeTwoLists(lists[i-1],lists[i]));
            }
            if(n%2==1) new_lists.push_back(lists[n-1]);
            lists = new_lists;
            n = lists.size();
            new_lists.clear();
        }
        return lists[0];
        
    }
};
```