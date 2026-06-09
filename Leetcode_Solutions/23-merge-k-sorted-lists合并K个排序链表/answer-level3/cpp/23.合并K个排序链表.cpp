第一次写出困难题，开心~
```
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        return merge(lists,0,lists.size() -1);
    }

    ListNode* merge(vector<ListNode*>& lists,int left,int right){
        if(left == right)
            return lists[left];
        if(right - left == 1)
            return mergeTwo(lists[left],lists[right]);
        int mid = (left + right) / 2;
        ListNode* listL = merge(lists, left, mid);
        ListNode* listR = merge(lists,mid + 1,right);
        return mergeTwo(listL,listR);
    }

    ListNode* mergeTwo(ListNode* left, ListNode* right){
        ListNode* p = new ListNode(-1);
        ListNode* q = p;
        while(left && right){
            if(left->val > right->val){
                p->next = right;
                right = right->next;
            }
            else{
                p->next = left;
                left = left->next;
            }
            p = p->next;
        }
        p->next = left ? left : right;
        return q->next;
    }
};
```
