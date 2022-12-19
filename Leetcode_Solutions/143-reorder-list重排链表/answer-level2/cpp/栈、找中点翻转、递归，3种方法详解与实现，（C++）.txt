**方法1：遍历一遍链表，把结点存入栈中，然后再遍历一次链表，将栈中的结点依次插到链表前面；
当遍历到的结点或它的下一结点和栈中的结点相同时，结束插入，同时断开剩下的结点的连接
时间复杂度 O(n) 空间复杂度 O(n)**

```cpp
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr) return;
        stack<ListNode* > nodes;
        ListNode* p = head;
        while(p){                       // 先将结点存入栈中
            nodes.push(p);
            p = p->next;
        }
        p = head;
        while(p && !nodes.empty()){     // 将栈中的结点插到链表前面
            ListNode* tmp = nodes.top();// 取栈顶结点
            nodes.pop();
            if(p == tmp){               // 链表长度为奇数的情况，当前结点与栈顶结点相同则结束
                p->next = nullptr;
                break;
            }else if(p->next == tmp){   // 链表长度为偶数的情况，当前结点的下一节点与栈顶结点相同则结束(不需要再插入了)
                p->next->next = nullptr;
                break;
            }else{                      // 插入链表
                tmp->next = p->next;
                p->next = tmp;
                p = tmp->next;
            }
        }
    }
```

**方法2：先找到链表中点，从中点断开链表，然后翻转中点之后的链表，最后遍历俩链表合并为一个链表
时间复杂度 O(n) 空间复杂度 O(1)**

```cpp
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr) return;

        ListNode* mid_node = findMidOfList(head);  // 找中点
        ListNode* right_head = mid_node->next;
        mid_node->next = nullptr;                  // 断开中点之后的链表

        right_head = reverseList(right_head);      // 翻转右半部分

        ListNode* left_p  = head;                  // 用于遍历左半部链表
        ListNode* right_p = right_head;            // 用于遍历右半部链表
        while(left_p && right_p){                  // 合并俩链表
            ListNode* temp_next1 = left_p->next;   // 暂存下一结点
            ListNode* temp_next2 = right_p->next;  // 暂存下一结点
            left_p->next  = right_p;               // 右部分链表的结点插入左部分结点之后
            right_p->next = temp_next1;
            left_p  = temp_next1;                  // 指针后移
            right_p = temp_next2;
        }

    }
    // 查找链表的中间结点并返回
    ListNode* findMidOfList(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    // 翻转链表，返回翻转后链表的头结点
    ListNode* reverseList(ListNode* head){
        ListNode* pre_node = nullptr;
        ListNode* cur_node = head;
        while(cur_node){
            ListNode* next_node = cur_node->next;
            cur_node->next = pre_node;
            pre_node = cur_node;
            cur_node = next_node;
        }
        return pre_node;
    }
```

**方法3：递归法，递归地断开最后一个结点，直到链表只剩一个或两个节点，然后层层返回开始拼接
时间复杂度较高 约为 O(n^2) 空间复杂度约为 O(n), 因为每次递归减少两个节点（首尾结点），递归深度近似为 n。**

```cpp
    void reorderList(ListNode* head){
        if(head == nullptr || head->next == nullptr) return;
        ListNode* pre = nullptr;
        ListNode* p   = head;
        while(p->next){   // p 遍历到最后一个结点，pre 遍历到倒数第二个结点
            pre = p;
            p = p->next;
        }
        pre->next = nullptr;              // 断开最后一个结点
        ListNode* temp_next = head->next; // 暂存头结点的下一节点，便于拼接
        reorderList(temp_next);

        head->next = p;
        p->next    = temp_next;
    }
```
