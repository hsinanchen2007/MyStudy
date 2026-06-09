### 解题思路
题目要求还求删除多余的元素。
时空复杂度不怎么高效

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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int,int> nums;
        ListNode* res,*p,*pre;
        res = new ListNode(0);
        res->next=head;
        pre = res;
        p=res->next;
        while(p){
            if(nums.empty()||nums.find(p->val)==nums.end()){
                 nums.insert(map<int,int>::value_type(p->val,1));
                //nums[p->val];
               // cout<<nums.size()<<endl;
                 pre = p;
                 p=p->next;
            }else{
                pre->next = p->next;
                delete p;
                p=pre->next;
            }
        }
        return res->next;

    }
};
```