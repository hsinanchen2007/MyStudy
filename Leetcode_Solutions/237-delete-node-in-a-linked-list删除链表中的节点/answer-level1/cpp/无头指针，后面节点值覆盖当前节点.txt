```
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
    void deleteNode(ListNode* node) {
        ListNode* tmp = node;
        ListNode* pre = NULL; // pre存上一个指针
        // 不知道头指针，所以后面元素值覆盖当前的
        while(tmp->next)
        {
            tmp->val = tmp->next->val;
            pre = tmp;
            tmp = tmp->next;
        }
        // 删除最后一个节点，此时tmp指向最后一个节点
        delete tmp;
        pre->next = NULL;
    }
};
```
<<<优化>>>其实只需用最临近的节点覆盖，后面的接上即可，注意链表相对于数组的优势！
![图片.png](https://pic.leetcode-cn.com/33733e7b7a7354a88cb7d1ca2f3a76ae989ee85012a4a23db224e7ce618056c5-%E5%9B%BE%E7%89%87.png)

```
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* tmp = node;
        ListNode* nxt = tmp->next; // nxt存node临近的下一元素
        
        // 不知道头指针，所以nxt元素值覆盖当前的
        // 只需要覆盖最近的那个就好，剩下的接上
        tmp->val = nxt->val;
        tmp->next = nxt->next;
        // 释放nxt节点内存资源
        delete nxt;
    }
};
```
