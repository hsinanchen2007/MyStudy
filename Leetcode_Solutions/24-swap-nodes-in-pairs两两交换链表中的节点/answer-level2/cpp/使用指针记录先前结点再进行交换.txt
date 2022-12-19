### 解题思路
使用指针记录先前结点后进行交换
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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)
        return NULL;
        if(head->next == NULL)
        return head;
        ListNode * frist = head->next;       //记录新链表的头结点
        ListNode * pre = new ListNode(0);    //记录交换两结点的先前结点
        ListNode* tmp = NULL;                //用来记录交换的两结点的后结点
        while(head  &&  head->next)
        {
                  
           tmp = head->next;
           head->next = tmp->next;           //前后结点交换
           tmp->next = head;
           pre->next = tmp;                  //改变先前结点得指向
           pre = head;                       //更新先前结点
           head = head->next;                //转移到下一组要交换的结点
        }
      return frist;
    }
};
```

//执行用时 :0 ms, 在所有 C++ 提交中击败100.00%的用户
//内存消耗 :9.9 MB, 在所有 C++ 提交中击败了5.60%的用户

