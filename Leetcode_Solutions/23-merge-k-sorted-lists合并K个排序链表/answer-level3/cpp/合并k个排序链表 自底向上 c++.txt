![image.png](https://pic.leetcode-cn.com/cb59ccdeadcf4bf262880d45db32d45fd07d73dc159fad00f96e25ce705ea89a-image.png)


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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        ListNode* left;
        ListNode* right;
        for(int step = 1; step < lists.size(); step*=2){
            int curIndex =0;
            while(curIndex < lists.size()-1){
                left = lists[curIndex];
                if(curIndex+step > lists.size()-1) break;
                right = lists[curIndex+step];
                lists[curIndex] = mergeTwoLists(left,right);
                curIndex = curIndex+step+step;
            }
        }
        return lists[0];
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            ListNode tempNode(0);
            ListNode* tempPtr = &tempNode;
            if(l1==NULL){
                tempPtr->next = l2;
            }else if(l2==NULL){
                tempPtr->next = l1;
            }
            while(l1&&l2){
                if(l1->val<l2->val){
                    tempPtr->next = l1;
                    l1 = l1->next;
                }else{
                    tempPtr->next = l2;
                    l2 = l2->next;
                }
                
                tempPtr = tempPtr->next;
                if(l1==NULL){
                    tempPtr->next = l2;
                }else if(l2==NULL){
                    tempPtr->next = l1;
                }
            }
            return tempNode.next;
        }
};
```
