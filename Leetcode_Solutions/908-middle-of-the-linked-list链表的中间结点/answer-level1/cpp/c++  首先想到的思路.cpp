### 解题思路
![图片.png](https://pic.leetcode-cn.com/0f694427413e4d64d542e4ef00d8e1967590d98163de7df8ffa0108922ee8f72-%E5%9B%BE%E7%89%87.png)

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
    ListNode* middleNode(ListNode* head) {
        int len = 0,mid = 0;
        ListNode *tmp = head;
        while(tmp != NULL)
        {
            len++;
            tmp = tmp->next;
        }
        mid = len/2; //无论len是奇数还是偶数，
        tmp = head;
        while(mid>0)
        {
            tmp = tmp->next;
            mid--;
        }
        return tmp;
    }
};
```