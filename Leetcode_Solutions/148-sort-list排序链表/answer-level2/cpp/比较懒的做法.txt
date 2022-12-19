因为个人是一个喜欢使用STL的排序，所以遇到排序题喜欢使用`std::sort()`解决（Java或其他语言也可以使用对应的函数）
主要是建立一个O(n)的数组或者向量存储所有的链表值，并在数组上进行排序，时间为`O(NLogN)`
排序完之后**直接**更改head的链表内容而不是重新建表，因为建表new节点结构体一个消耗的时间很多，本身也没必要重新建一个链表。
而按照题意直接改head链表即可。

最后将链表的内容对着排序过后的数组按顺序一一对应赋值即可。
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
    ListNode* sortList(ListNode* head) {
        if(head==NULL)return head;
        vector<int>store;
        // 取值
        ListNode* q=head;
        while(q){
            store.push_back(q->val);
            q=q->next;
        }
        // 排序
        sort(store.begin(),store.end());
        // 赋值
        q=head;
        for(int s:store){
            q->val=s;
            q=q->next;
        }
        return head;
    }
};
```