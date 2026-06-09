### 解题思路
主要是进位问题，以后合并链表或者数组可以参考下面

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // ListNode* l1_tail = l1;
        // ListNode* l2_tail = l2;

        // int cur_num = 0;
        // int pro_num = 0;
        // ListNode* output = new ListNode(0);
        // ListNode* output_temp = output;
        // bool flag = false;
        // while(l1_tail && l2_tail){
        //     int sum = (l1_tail->val + l2_tail->val) + pro_num;
        //     if(sum >= 10){
        //         flag = true;
        //     }else{
        //         flag = false;
        //     }
        //     cur_num = sum % 10;
        //     ListNode* new_node = new ListNode(cur_num);
        //     output_temp->next = new_node;
        //     pro_num = sum / 10;
        //     l1_tail = l1_tail->next;
        //     l2_tail = l2_tail->next;
        //     output_temp = output_temp->next;
        // }
        // if(l1_tail){
        //     while(l1_tail){
        //         if(flag){
        //             int sum = l1_tail->val + pro_num;
        //             cur_num = sum % 10;
        //             pro_num = sum / 10;
        //             ListNode* new_node = new ListNode(cur_num);
        //             output_temp->next = new_node;
        //             output_temp = output_temp->next;
        //             if(sum >= 10){
        //                 flag = true;
        //             }else{
        //                 flag = false;
        //             }       
        //         }
        //         else{
        //             ListNode* new_node = new ListNode(l1_tail->val);
        //             output_temp->next = new_node;
        //             output_temp = output_temp->next;
        //         }
        //         l1_tail = l1_tail->next;
        //     }
        // }else if(l2_tail){
        //     while(l2_tail){
        //         if(flag){
        //             int sum = l2_tail->val + pro_num;
        //             cur_num = sum % 10;
        //             pro_num = sum / 10;
        //             ListNode* new_node = new ListNode(cur_num);
        //             output_temp->next = new_node;
        //             output_temp = output_temp->next;
        //             if(sum >= 10){
        //                 flag = true;
        //             }else{
        //                 flag = false;
        //             }                   
        //         }else{
        //             ListNode* new_node = new ListNode(l2_tail->val);
        //             output_temp->next = new_node;
        //             output_temp = output_temp->next;
        //         }
        //         l2_tail = l2_tail->next;
        //     }
        // }
        // if(flag){
        //     ListNode* new_node = new ListNode(pro_num);
        //     output_temp->next = new_node;
        // }
        // return output->next;
        ListNode* output = new ListNode(0);
        ListNode* p = output;
        int carry = 0;
        while(l1 || l2 || carry){
            int l1_val = l1 ? l1->val : 0;
            int l2_val = l2 ? l2->val : 0;

            int sum = l1_val + l2_val + carry;
            carry = sum / 10;

            ListNode* new_node = new ListNode(sum % 10);
            p->next = new_node;
            p = p->next;

            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        
        return output->next;

    }
};
```