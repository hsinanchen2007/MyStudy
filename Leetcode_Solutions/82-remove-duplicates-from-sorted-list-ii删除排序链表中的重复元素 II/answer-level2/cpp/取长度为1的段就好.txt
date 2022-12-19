### 解题思路
思路：把整个链表视作多段相同值的链表的拼接，只需要对每一段进行判定，只取长度为1的段就好。
    所需变量：
         哑结点指针newH：哑结点， 指向链表的头结点，避免删除头结点。
         工作指针work：  总是指向链表的尾结点，用于添加新的段；
         头结点head：    每一段的头结点(可以使用原始的)；
         删除指针d：     用于释放内存。
         计数count：    计算每一段的长度，每段长度初始值为1；

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
        // 边界情况
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* newH = new ListNode(-1); // 哑结点，新的链表
        newH->next = head; 
        ListNode* work = newH; // 工作指针，用于段与段之间的操作
        ListNode* d;  // 删除指针，用作释放内存
        
        int count = 1;
        while(work->next != NULL){ // work为空说明没有段可以添加了

            count = 1;  // 每段初始值是1
            head= work->next;  

            // 计算段长
            while(head->next != NULL && head->next->val == head->val){
                 // 统计这一段的长度
                count ++; 
                d = head;
                head = head->next;
                delete d;
            }

            // 根据段长进行取舍
            if(count == 1){  // 取
                work->next = head;
                work = head;
            }
            else{  // 舍
                work->next = head->next;
            }
        }
        return newH->next;  // 返回哑结点的下一个结点
    }
};
```