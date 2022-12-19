逆置链表法：将首节点next置为nullptr；每遍历一个节点，将其next置为pre；当遇到next为nullptr退出循环。
对数据结构进行了可逆的破坏，最坏需遍历2n个节点。
![image.png](https://pic.leetcode-cn.com/18aa2b02c1cca97fa0b8a0f3dd120117c6f94b4913d8aee9ef8e96268fae4468-image.png)

```c++
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==nullptr||head->next==nullptr)
            return false;
        ListNode *temp, *now = nullptr, *next = head;
        do{
            temp = next->next;
            next->next = now;
            now = next;
            next = temp;
        }while(next);
        return now==head;
    }
};
```