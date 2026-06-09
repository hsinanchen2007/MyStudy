### 解题思路
1、放入数组 使用数组插入排序

2、不使用数组 直接操作链表 由于是单向链表，比较时是从左往右，而无法直接从右往左

### 代码

```cpp

class Solution {
public:
    //1、借助数组
    ListNode* insertionSortList(ListNode* head) {

        if (head == nullptr || head->next == nullptr)
            return head;

        vector<ListNode*> v;
        while (head)
        {
            v.push_back(head);
            head = head->next;
        }

        //对指针数组按值进行插入排序
        for (int i = 1; i < v.size(); ++i)
        {
            int j = i;
            ListNode* tmp = v.at(j);

            for (; j > 0; --j)
            {
                if (tmp->val < v.at(j - 1)->val)
                {
                    v.at(j) = v.at(j - 1);
                }
                else
                {
                    break;
                }
            }

            v.at(j) = tmp;
        }

        //重新串连链表
        for (int i = 0; i < v.size() - 1; ++i)
        {
            v.at(i)->next = v.at(i + 1);
        }
        v.back()->next = nullptr;

        return v.front();
    }


    //2、不借助数组
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = head; //待插入节点的前一个节点
        ListNode* node = head->next; //待插入节点

        while (node)
        {
            if (node->val < prev->val)
            {
                ListNode* temp = dummy;
                while (temp->next->val <= node->val)
                {
                    temp = temp->next;
                }

                prev->next = node->next; //先删
                node->next = temp->next; //后插
                temp->next = node;

                node = prev->next; 
            }
            else //已经有序
            {
                prev = prev->next;
                node = node->next;
            }
        }

        head = dummy->next;
        delete dummy;
        return head;
    }
    

};
```