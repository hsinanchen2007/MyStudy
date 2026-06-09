### 解题思路
此处撰写解题思路

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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *res,*end=head;
        if(head==NULL) return head;
        int num(1);
        while(end->next!=NULL){
            num++;
            end=end->next;//确定结尾和数量
        }

        k=k%num;//最终实际位移大小
        if(0==k) return head;
        k=num-k;//从第几个开始变化
        end->next=head;//首尾

        for(int i=1;i<k;++i){
            head=head->next;
        }
        res=head->next;
        head->next=NULL;
        return res;
    }
};






```