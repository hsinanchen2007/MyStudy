方法1: 使用set 删两遍

方法2: 一次遍历 遇到重复节点 在内部再使用一个循环去删除

```cpp
class Solution {
public:

    //方法1: 使用set 删两遍
    ListNode* deleteDuplicates(ListNode* head) {

        if(head == nullptr || head->next == nullptr)
            return head;

        ListNode* prev = head;

        //使用set记录下重复出现的值
        unordered_set<int> set;
        // set.reserve(256);

        //删除重复节点，保留第一次出现的节点
        while (prev->next)
        {
            if (prev->next->val == prev->val)
            {
                set.insert(prev->val);
                // ListNode* tmp = prev->next;
                prev->next = prev->next->next;
                // delete tmp;
            }
            else
            {
                prev = prev->next;
            }
        }

        //再把重复的第一次出现的节点删除(第一个节点也可能重复，要删除 可以使用辅助头节点)
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        prev = dummy;
        
        while (prev->next)
        {
            if (set.find(prev->next->val) != set.end())
            {
                // ListNode* tmp = prev->next;
                prev->next = prev->next->next;
                // delete tmp;
            }
            else
            {
                prev = prev->next;
            }
        }

        return dummy->next;
    }

    //方法2: 一次遍历
    ListNode* deleteDuplicates(ListNode* head) {

        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        while (prev->next && prev->next->next)
        {
            if (prev->next->val == prev->next->next->val)
            {
                ListNode* tmp = prev->next; //重复节点中的第一个

                while (tmp && tmp->next && tmp->val == tmp->next->val)
                {
                    // ListNode* node = tmp;
                    tmp = tmp->next;
                    // delete node;
                }

                prev->next = tmp->next; //tmp为重复节点中的最后一个
                // delete tmp;
            }
            else
            {
                prev = prev->next;
            }
        }

        return dummy->next;
    }
};