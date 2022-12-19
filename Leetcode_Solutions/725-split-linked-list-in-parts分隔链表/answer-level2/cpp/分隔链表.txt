### 解题思路
切断链表操作，定位到末尾

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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int length=0;
        ListNode* cur=root;
        while(cur!=NULL){
            length++;
            cur=cur->next;
        }
        int mod=length%k;
        int size=length/k;
        cur=root;
        vector<ListNode*> ret(k);
        //分成k个组,每组个数为：多余得平均分配给前面
        int currentSize=0;
        for(int i=0;cur!=NULL&&i<k;i++){
            ret[i]=cur;
            if(mod>0){
                currentSize=size+1;
                mod--;
            }else{
                currentSize=size;
            }

            //切断链表操作,定位到末尾size-1
            for(int j=0;j<currentSize-1;j++){
                cur=cur->next;
            }
            ListNode*tmp=cur->next;
            cur->next=NULL;
            cur=tmp;
        }
        return ret;

    }
};
```