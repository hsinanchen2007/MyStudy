### 解题思路
链表题

![image.png](https://pic.leetcode-cn.com/e415e28f0b072839b94ef1b1afb2d33b748649f5f82974e751ffa1c4cf113943-image.png)


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
        int cnt = 1;
        ListNode* tail = head;
        ListNode* now = head;
        if(tail == NULL) return head;
        // tail 存储链表尾结点，并计算链表长度
        while(tail -> next != NULL)
        {
            cnt ++;
            tail = tail -> next;
        }
        // 去掉无用位移量（即去掉将链表完整位移一遍回到原位置的那些位移量）
        k = cnt - k % cnt;
        if(k == cnt) return head;
        // 寻找位移后的头结点
        while(k > 1)
        {
            now = now -> next;
            k --;
        }
        // 进行位移
        tail -> next = head;
        head = now -> next;
        now -> next = NULL;
        return head;
    }
};
```