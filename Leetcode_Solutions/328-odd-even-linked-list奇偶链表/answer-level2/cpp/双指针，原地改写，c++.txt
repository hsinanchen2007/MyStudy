### 解题思路
此处撰写解题思路
结果：
执行用时 :12 ms, 在所有 C++ 提交中击败了78.03% 的用户
内存消耗 :9.6 MB, 在所有 C++ 提交中击败了58.97%的用户
思路：
下一个奇数位，中间一段偶数位调换位值，详细如下
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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL) return head;//如果只有一节，或者本来就是空，直接返回
        struct ListNode* res = head;//新建一个指向头的临时结点
        ListNode *temp, *temp_;
        temp = head->next;//保存2号地址
        temp_ = head->next;//开始的时候是重合的
        do{ 
            head->next=temp->next;//1号指向3号
            temp->next = temp->next->next;//2号指向4号
            head->next->next = temp_;//3号指向2号
           
            head=head->next;//奇数屁股
            temp_=head->next;//偶数头
            temp=temp->next;//偶数屁股
        }
        while(temp!=NULL && temp->next!=NULL);
        return res;
    }
};
```