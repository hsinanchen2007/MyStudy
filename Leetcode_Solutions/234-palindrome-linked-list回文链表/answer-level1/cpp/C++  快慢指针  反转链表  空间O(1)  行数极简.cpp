- 执行用时 :20 ms, 在所有 C++ 提交中击败了98.52%的用户
- 内存消耗 :12.5 MB, 在所有 C++ 提交中击败了73.29%的用户
- 整体思路是先用快慢指针找中点(慢指针的最终位置)
- 然后再反转中点指向的后半部分链表
- 前半部分再与后半部分逐元素比较
- 时间复杂度为O(n)
- 空间复杂度关键看反转链表是迭代还是递归，我这里用迭代所以是O(1),递归则是O(n)
- 为了行数，牺牲了代码可读性，可能看起来有点费劲.....
```
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next) return true;   //空链表表或链表只有一个元素
        ListNode *slow=head,*fast=head;       //快慢指针
        for( ; fast&&fast->next ; fast=fast->next->next,slow=slow->next); //快慢指针迭代找中点
        ListNode *cur=slow,*nex=nullptr,*back = nullptr;            //back表示后半链表头指针
        for( ; cur ; nex=cur->next, cur->next=back, back=cur, cur=nex);  //反转后半链表   
        for(ListNode* front=head ; front&&back ; front=front->next,back=back->next) //front:前半链表头指针
            if(back->val!=front->val) return false;   //前半链表与后半链表逐元素比较
        return true;
    }
};
```
