### 解题思路
和官方思路一相同。两次遍历：第一次获取链表长度，第二次找到要替换的位置，进行替换。
### 知识点
**哑结点：**    添加一个哑结点做辅助，该结点位于列表头部。哑结点用来简化某些极端情况，例如列表中只含有一个结点，或需要删除列表的头部。
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //第一次遍历:获得链表长度
        int length=1;
        ListNode* tmp;
        for(tmp=head;tmp!=NULL;++length){//错误点1：(需记忆)写成了!tmp(这里不是bool类型)
            tmp=tmp->next;
        }
        //第二次遍历：删除指定元素（找到要删除元素前面的元素
        ListNode first(0);
        first.next=head;
        tmp=&first;
        for(int j=1;j<length-n;++j){//错误点2：细节问题，写成了j<=length-n。自己推算一遍就知道了。
            tmp=tmp->next;
        }
        tmp->next=tmp->next->next;
        return first.next;/*错误点3：(需记忆)写成了return head。这里没有考虑到如果初始链表中只有一个元素时，return head=[x],而return first.next=[]*/
    }
};
```