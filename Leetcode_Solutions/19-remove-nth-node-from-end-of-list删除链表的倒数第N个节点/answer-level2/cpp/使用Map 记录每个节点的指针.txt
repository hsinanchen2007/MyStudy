### 解题思路
此处撰写解题思路

执行用时 :4 ms
在所有 C++ 提交中击败了89.82%的用户

使用map 来记录指针，然后根据index取出来

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        //关键在于这个map，以空间换区时间
        std::map<int, ListNode*> indexMap;
        auto p = head;
        auto q = p;
        int i = 0;
        while (p) {
            indexMap.insert(std::make_pair(i, p));
            p = p->next;
            ++i;
        }
       
        if (n == i) {
            return q->next;
        }
        else if (i == 0) {
            return q;
        }
        else {
            int index = i - n;
            auto p1 = indexMap[index];
            auto p2 = indexMap[index - 1];
            p2->next = p1->next;
            return q;
        }
    }
};
```