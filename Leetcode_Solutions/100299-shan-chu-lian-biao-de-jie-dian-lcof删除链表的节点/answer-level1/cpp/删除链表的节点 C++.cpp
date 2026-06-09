### 解题思路
参考[C++ 使用 dummy 节点](https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof/solution/c-shi-yong-dummy-jie-dian-by-dexin/)

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
    ListNode* deleteNode(ListNode* head, int val) {
        
        ListNode* dump = new ListNode(0);   // 创建一个伪头节点
        dump->next = head;                  // 伪头节点的next指向head
        ListNode* p = dump;                 // 用指针p来遍历链表

        ListNode* q = dump;     // 用一个指针指向伪头节点，用来遍历节点 
        while( q && q->next){   // 如果当前节点和下一节点不为空
            if(q->next->val == val){
                // 下一节点的值等于搜索值
                q->next = q->next->next;    // 之所以这么做是为了保存上一节点信息
            }
            q = q->next;
        }
        return dump -> next;
    }
};
```