### 解题思路
此处撰写解题思路
首先，写一个函数能够合并两个链表
然后，遍历数组，进行两两合并，如果数组大小为奇数个，在最后传一个空指针
重复进行上述操作，直至数组数量为1时，结束，返回链表。
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
        if(lists.size()==0)
            return NULL;
        vector<ListNode*> copy;
        vector<ListNode*> vec=lists;
        while(vec.size()!=1){
            for(int i=0;i<vec.size();i+=2){
                if(i+1==vec.size()){
                    copy.push_back(merge2List(vec[i],NULL));    
                }else
                    copy.push_back(merge2List(vec[i],vec[i+1]));
            }
            vec=copy;
            copy.clear();
        }
        return vec[0];
    }
    //合并两个链表
    ListNode* merge2List(ListNode* l1,ListNode* l2){
        ListNode* ret=NULL;
        ListNode* p;
        
        if(l1==NULL&&l2!=NULL)
            return l2;
        else if(l2==NULL&&l1!=NULL)
            return l1;
        else if(l2==NULL&&l1==NULL)
            return NULL;

        if(l1->val<l2->val){
            ret=l1;
            p=ret;
            l1=l1->next;
        }else{
            ret=l2;
            p=ret;
            l2=l2->next;    
        }
        while(l1!=NULL&&l2!=NULL){
            if(l1->val<l2->val){
                p->next=l1;
                l1=l1->next;
                p=p->next;
            }else{
                p->next=l2;
                l2=l2->next;
                p=p->next;
            }
        }
        if(l1==NULL){
            p->next=l2;
            return ret;
        }else{
            p->next=l1;
            return ret;
        }


    }
};
```