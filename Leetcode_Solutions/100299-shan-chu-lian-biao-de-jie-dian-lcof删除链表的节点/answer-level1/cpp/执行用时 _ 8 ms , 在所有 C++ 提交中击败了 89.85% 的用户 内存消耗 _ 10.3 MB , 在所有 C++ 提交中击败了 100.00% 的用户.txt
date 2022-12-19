### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/c7ea513fe8cea52a7cc2fef5fa0f14602b1118da43e2739f7f0ff92484b06592-image.png)

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
    ListNode* deleteNode(ListNode* head, int val) {
        if(head->val == val)return head->next; //判断是否为头节点
        ListNode *res = head;   //记录需返回的结点
        while(head->next){
            if(head->next->val == val){
                head->next = head->next->next;  //删除结点跳出循环
                break;
            }
                
            head = head->next;
        }   
        return res;
    }
};
```