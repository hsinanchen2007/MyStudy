```
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* oneNode = head;
        ListNode* twoNode = head;
        ListNode* temp = head;

        while (twoNode != NULL) {
            temp = oneNode;
            oneNode = oneNode->next;
            if (twoNode->next == NULL) {
                return  temp;
            }
            if (twoNode->next->next == NULL) {
                return oneNode;
            }
            twoNode = twoNode->next->next;
        }

        return temp;
    }
};
```
![image.png](https://pic.leetcode-cn.com/ab4d0fcf5a5dbe2f315b2c96c3580677e9192399803edb8cc68938fa7c00539d-image.png)
