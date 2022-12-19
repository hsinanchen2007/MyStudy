### 解题思路
此处撰写解题思路

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
/*
 //执行用时 :4 ms, 在所有 C++ 提交中击败了95.87% 的用户
 //内存消耗 :7.8 MB, 在所有 C++ 提交中击败了100.00%的用户
 //第一种迭代法
 //按原始顺序迭代结点，并将它们逐个移动到列表的头部
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        if(cur == nullptr || cur->next == nullptr) return head;
        while(cur->next != nullptr)
        {
            ListNode* temp;
            temp = cur->next;
            cur->next = cur->next->next; 
            temp->next = head;
            head = temp;   
        }
        return head;
    }
};

*/

/*
//执行用时 :16 ms, 在所有 C++ 提交中击败了7.30% 的用户
//内存消耗 :7.6 MB, 在所有 C++ 提交中击败了100.00%的用户
//第二种迭代法
//只是将每个元素的next换成它上一个元素的地址
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;   //上一个结点
        ListNode* cur = head;   //目前的节点位置
        while(cur != nullptr)
        {
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};
*/

//第三种 递归法（我子节点下的所有节点都已经反转好了，现在就剩我和我的子节点 没有完成最后的反转了，所以反转一下我和我的子节点）
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* p = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return p;
    }
};

```