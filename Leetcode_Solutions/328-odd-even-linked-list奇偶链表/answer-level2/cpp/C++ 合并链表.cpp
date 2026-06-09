### 解题思路
![Screen Shot 2020-03-09 at 15.53.46.png](https://pic.leetcode-cn.com/5e5140d4e41c2eca888febc1ffa6ca149d9e047aa3bc31902d67e9b01923ef0e-Screen%20Shot%202020-03-09%20at%2015.53.46.png)
此处撰写解题思路

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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr) return head;
        
        int count = 1;
        ListNode* oddList = new ListNode(0);
        ListNode* curOdd  = oddList;
        ListNode* evenList = new ListNode(0);
        ListNode* curEven  = evenList;

        ListNode* current = head;
        while(current != nullptr)
        {
            ListNode* next = current->next;
            if(count%2 != 0)
            {
                curOdd->next = current;
                curOdd       = current;
                current->next= nullptr;
            }
            else
            {
                curEven->next = current;
                curEven       = current;
                current->next = nullptr;
            }
            current = next;
            count++;
        }
        ListNode* deleteOdd = oddList;
        oddList = oddList->next;
        delete deleteOdd;
        deleteOdd =nullptr;

        ListNode* deleteEven = evenList;
        evenList = evenList->next;
        delete deleteEven;
        deleteEven =nullptr;

        curOdd->next = evenList;
        return oddList;

    }
};
```
### 注意 memory leak 动态内存分配的释放