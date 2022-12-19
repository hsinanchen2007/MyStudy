### 解题思路
此处撰写解题思路
vector辅助存储链表
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;
        vector<ListNode*> tmp;
        while(head!=NULL) {
            tmp.push_back(head);
            head = head->next;
        }

        int len = tmp.size(), S = len - k%len, E=(S-1)%len;
        if(S==len) return tmp[0];
        tmp[E]->next = NULL;
        tmp.back()->next = tmp[0];
        return tmp[S];
    }
};
```
![搜狗截图20200318212323.png](https://pic.leetcode-cn.com/f547567c3fd97d9b440c4b11bca45599aa9a49eb649aa43aa416c68af691b744-%E6%90%9C%E7%8B%97%E6%88%AA%E5%9B%BE20200318212323.png)
