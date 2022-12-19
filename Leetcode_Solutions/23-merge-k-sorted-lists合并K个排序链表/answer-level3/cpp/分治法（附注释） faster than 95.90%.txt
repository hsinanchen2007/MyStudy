### 解题思路
思路：1、写一个MergeTwo的函数2、使用divide&conquer不断迭代二分lists。

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        if (len == 0)return {};
        lists[0] = divide(lists,0,len-1);
        return lists[0];
    }
    ListNode* divide(vector<ListNode*>& lists, int l,int r){
        if(l == r)return lists[l];
        else{
            lists[l] = divide(lists,l,(l+r)/2);
            lists[(l+r)/2 + 1] = divide(lists,(l+r)/2 + 1,r);
        }
        return mergeTwoLists(lists[l],lists[(l+r)/2 + 1]);
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr){
            l1 = l2;//如果不return，虽然可以操作指针改变它前后的连接，但是函数外l1,l2还是原来的地址没有改变
            //cout<<l1->val<<endl;
            return l1;//always remember empty case
        }
        if(l2 == nullptr)return l1;
        if(l1->val > l2->val){//swap for excuting uniform next-step operation
            swap(l1,l2);
        }
        ListNode* head = l1;
        ListNode* temp1;
        while (l1->next != nullptr && l2 != nullptr){
            if(l2 == nullptr || l1->next->val <= l2->val){
                l1 = l1->next;
                continue;
            }
            if(l1->next->val > l2->val){
                temp1 = l1->next;
                l1->next = l2;
                l2 = l2->next;
                l1->next->next = temp1;
                
            }
        }
        //if l1 != nullptr after iteration, 
        //l1 has rest part that larger than last element of l1,
        //it is ok because l1 is connected linked list
        //if l2 != nullptr after iteration,
        //l2 has rest part not connected to l1
        if(l2 != nullptr)l1->next = l2;
        return head;
        
    }
};
```