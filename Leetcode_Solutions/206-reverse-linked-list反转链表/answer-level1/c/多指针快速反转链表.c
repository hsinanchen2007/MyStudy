### 解题思路

- 本题我们解决的思路是使用多指针
- 设置三个指针变量 p(指向当前节点)  pre(指向当前节点的前一个结点) pNext(指向当前节点的后一个节点)

![image.png](https://pic.leetcode-cn.com/ef35f3e01542d685d7e26ce1e0ba21249f5fe4b526ad8db4e01000f4aa73e5d6-image.png)

- 每次都将p指向pre, 然后pre p pNext分别向后移动一个位置
- 最后返回指针pre

![image.png](https://pic.leetcode-cn.com/0ed56a8607749baa42a1f8da15d4f9dadf6ada5fcbbd374610de415dc34b41d9-image.png)


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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode* pre = nullptr;    //指向当前节点的前一个节点
        ListNode* p = head;     //指向当前节点
        ListNode* pNext = head->next;   //指向当前节点的后一个节点
        
        while(p != nullptr) {
            p->next = pre;
            pre = p;
            p = pNext;
            pNext =  pNext == nullptr ? nullptr : pNext->next;  //这边加一个判断,防止pNext为空指针(遍历到最后pNext要比p先到达空指针的位置)
        }
        
        return pre;
    }
    
};
```