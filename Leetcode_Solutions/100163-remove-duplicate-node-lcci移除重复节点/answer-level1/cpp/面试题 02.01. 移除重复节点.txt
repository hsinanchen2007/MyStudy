### 解题思路
1. 用一个数组存储该数字是否出现过
2. 用一个指针p遍历，判断p->next是否出现过（这种方式比较好删除节点，如果判断p是否出现过，则还需要一个指向上一个节点的指针）

执行用时 :
16 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :
15.2 MB, 在所有 C++ 提交中击败了100.00%的用户
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
    ListNode* removeDuplicateNodes(ListNode* head) {
        //head空，直接返回
        if(!head) return head;
        //存储空间，记录是否出现
        int a[20001]={0};
        //头指针newlist 运行指针p
        ListNode* newlist=new ListNode(0);
        ListNode* p=head;
        newlist->next=p;
        a[p->val]++;//记录第一个节点
        //p表示当前节点，while循环中比较的是下一个节点是否出现过
        /*
        - p->next==NULL的话，可以退出了
        - p->next如果出现过的话，p->next=p->next->next，跳掉p-->next这个节点
        - p->next如果没出现过，记录该节点，并且p移动一个节点
        */
        while(p){
           // cout<<p->next->val<<" "<<a[p->next->val]<<endl;
            if(!p->next) break;
            if(a[p->next->val]==0){
                a[p->next->val]++;
                p=p->next;
            }else{
                p->next=p->next->next;
            }
        }
        return newlist->next;
    }
};
```