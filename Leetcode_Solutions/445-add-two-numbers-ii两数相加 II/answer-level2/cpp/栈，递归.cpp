### 解题思路
这道题首先想到的就是用两个栈把链表里的数据存起来，然后再弹出来相加，但是为啥时间这么长，，，看了解题也一样的方法，时间就短很多？？

递归的方法是解题里的。先计算每个链表的深度。然后送去递归。思想差不多。为啥运行出来时间也这么慢？？

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
    // 执行用时 :60 ms, 在所有 C++ 提交中击败了11.43% 的用户
    // 内存消耗 :73.9 MB, 在所有 C++ 提交中击败了5.17%的用户
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // if(!l1||!l2) return l1?l1:l2;
        stack<ListNode*> stc1, stc2;
        ListNode *res, *pNext=nullptr;
        int overflow = 0;
        while(l1){
            stc1.push(l1);
            l1 = l1->next;
        }
        while(l2){
            stc2.push(l2);
            l2= l2->next;
        }
        while(stc1.size() || stc2.size()||overflow){
            int sum = 0;
            if(!stc1.empty()){
                sum += stc1.top()->val;
                stc1.pop();
            }
            if(!stc2.empty()){
                sum += stc2.top()->val;
                stc2.pop();
            }
            sum += overflow;
            res = new ListNode(sum%10);//创建节点。
            res->next = pNext;//与next指针相连

            overflow = sum/10;//确定有无进位。
            pNext = res;//前进一位
        }
        return res;
    }


    // 执行用时 :64 ms, 在所有 C++ 提交中击败了5.93% 的用户
    // 内存消耗 :71.6 MB, 在所有 C++ 提交中击败了5.17%的用户
    int carry = 0;
    ListNode* dfs(ListNode* l1, ListNode* l2, int d1, int d2) {
        if (l1 == NULL || l2 == NULL) {
            return NULL;
        }
        ListNode *p;
        int val = 0;
        if (d1 == d2) {
            p = dfs(l1->next, l2->next, d1 - 1, d2 - 1);
            val = carry + l1->val + l2->val;
        } else if (d1 > d2) {
            p = dfs(l1->next, l2, d1 - 1, d2);
            val = carry + l1->val;
        } else {
            p = dfs(l1, l2->next, d1, d2 - 1);
            val = carry + l2->val;
        }
        auto node = new ListNode(val % 10);
        node->next = p;
        carry = val / 10;
        return node;
    }
    int depth(ListNode* l) {
        int d = 0;
        while (l != NULL) {
            ++d;
            l = l->next;
        }
        return d;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        int d1 = depth(l1);
        int d2 = depth(l2);
        auto p = dfs(l1, l2, d1, d2);
        if (carry > 0) {
            auto node = new ListNode(carry);
            node->next = p;
            return node;
        }
        return p;
    }
};
```