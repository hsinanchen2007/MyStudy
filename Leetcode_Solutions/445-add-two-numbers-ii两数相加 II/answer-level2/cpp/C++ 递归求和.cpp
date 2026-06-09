### 解题思路


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
        // 获取链表长度
        int length_1 = getLength(l1);
        int length_2 = getLength(l2);
        // 对长短较短的链表前端补0
        ListNode* newL1 = l1, *newL2 = l2;
        if(length_1 < length_2){
            newL1 = pre_Add_0(l1, length_2-length_1);
        }else if(length_1 > length_2){
            newL2 = pre_Add_0(l2, length_1-length_2);
        }
        // 开始递归求和
        ListNode* head = nullptr;
        addList(newL1, newL2, head);
        // 判断是否存在最高位进位
        if(carry){
            ListNode* dummy = new ListNode(1);
            dummy->next = head;
            head = dummy;
        }
        return head;
    }
private:
    void addList(ListNode* p1, ListNode* p2, ListNode*& head){
        if(!p1 && !p2) {
            head = nullptr;
            return;
        }
        addList(p1->next, p2->next, head);
        // 求和
        int sum = p1->val + p2->val + carry;
        carry = sum/10;
        sum %= 10;
        // 建立新的节点
        ListNode* p = new ListNode(sum);
        p->next = head;
        head = p;
    }
    ListNode* pre_Add_0(ListNode* p, int zero_num){
        ListNode* head = p;
        while(zero_num--){
            ListNode* fro = new ListNode(0);
            fro->next = head;
            head = fro;
        }
        return head;
    }
    int getLength(ListNode* p){
        int length = 0;
        while(p){ length += 1; p = p->next; }
        return length;
    }
private:
    int carry = 0;
};


// [3,9,9,9,9,9,9,9,9,9]
// [7]
```