### 解题思路
1 递归输出后面一个节点，再输出当前节点
1 栈依次存入节点值，再依次取出实现逆序
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
    //方法1 递归
     vector<int> reversePrint(ListNode* head) {
         vector<int>res;
         helper(head,res);
         return res;
     }
     void helper(ListNode* head,vector<int>& res){
         if(head){
             if(head->next){
                  helper(head->next,res);
             }
             res.push_back(head->val);
         }
         return ;
     }
    
    //方法2 使用栈
    vector<int> reversePrint(ListNode* head) {
         vector<int>res;
         stack<int>sk;
         while(head){
             sk.push(head->val);
             head=head->next;
         }
         while(!sk.empty()){
             res.push_back(sk.top());
             sk.pop();
         }
         return res;
    
    }
};
```