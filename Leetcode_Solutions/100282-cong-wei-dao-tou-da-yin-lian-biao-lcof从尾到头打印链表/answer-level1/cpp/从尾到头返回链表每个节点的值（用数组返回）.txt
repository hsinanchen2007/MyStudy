### 解题思路
两种解法：
1.普通思想
先计算出链表节点长度；  O(n)
再倒序赋值给数组；  O(n)

2.递归思想
b = reversePrint(head->next);
b.push_back(head->val);

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
    vector<int> reversePrint(ListNode* head) {
        // 普通解法
        // ListNode* p = head;
        // int count = 0;
        
        // while(p != NULL)
        // {
        //     count++;
        //     p = p->next;
        // }

        // p = head;
        // vector<int> a(count);   // 如果不确定内存长度就会报错
        // for(int i = count-1;i >= 0;i--)
        // {
        //     a[i] = p->val;
        //     p = p->next;
        // }
        // return a;

        // 递归解法
        vector<int> b;
        if(head == NULL)
            return b;
        b = reversePrint(head->next);
        b.push_back(head->val);
        return b;

    }
};
```