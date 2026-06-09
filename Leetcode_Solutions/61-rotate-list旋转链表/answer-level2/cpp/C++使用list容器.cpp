### 解题思路
先求循环的次数，num=k%l.size();再利用push_front头插法，在删除尾元素。

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
        if(head==NULL)return NULL;
        list<int>l;
        ListNode *p=head;
        while(p!=NULL){
            l.emplace_back(p->val);
            p=p->next;
        }
        int num=k%l.size();//判断要执行多少部
        if(num==0)return head;
        for(int i=0;i<num;++i){
            auto it=l.rbegin();
            l.push_front(*it);
            l.pop_back();
            
        }
        ListNode *first=new ListNode(0);
        p=first;
       auto  it=l.begin();
        while(it!=l.end()){
            ListNode *s=new ListNode(*it++);
            p->next=s;
            p=s;
        }
        p->next=NULL;
        return first->next;
    }
};
```