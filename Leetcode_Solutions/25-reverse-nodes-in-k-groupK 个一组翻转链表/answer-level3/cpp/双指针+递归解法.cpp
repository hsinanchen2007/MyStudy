![Screen Shot 2020-02-02 at 9.31.11 PM.png](https://pic.leetcode-cn.com/5bc681429fc2073450c039d94443be52a7c52bee761cc4b90a6cd7971d7b4b96-Screen%20Shot%202020-02-02%20at%209.31.11%20PM.png)

解题思路：
1. 链表头部增加一个dummy节点，dummy->next=head，结束输出dummy->next。（因为翻转后首个元素不是head了，所以用dummy->next来指向答案。）
2. 左指针指向翻转段落的前一个节点，右指针指向当前节点。右指针移动时，记录数量。
3. 段落节点数量等于k时，调用递归翻转此段落，翻转完成后，记录的节点数量清零，左右指针都指向翻转后段落的最后一个节点。
4. 递归部分helper(l,r)：
    - 如果左指针下一个就是右指针，段落(从l->next到r)长度不够翻转，return r；
    - 先翻转右边段落，更新最右节点，r=helper(l->next,r)；
    - 再翻转此段落，把l->next放到最后，tmp1=l->next；把l->next->next提到前边来。 
    - 注意！！！段落翻转之后最右的节点改变了，需要更新最右节点，return tmp1。

C++代码：
```
class Solution {
public:
    ListNode* helper(ListNode* l, ListNode* r){
        if (l->next==r) return r;
        r=helper(l->next, r);
        ListNode* tmp1=l->next;
        ListNode* tmp2=r->next;
        r->next=l->next;
        l->next=l->next->next;
        tmp1->next=tmp2;
        return tmp1;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k<2) return head;
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode *l, *r;
        l=dummy;
        r=dummy;
        int cnt=0;
        while (r!=NULL){
            if (cnt==k){
                r=helper(l,r);
                cnt=0;
                l=r;
            }
            cnt++;
            r=r->next;
        }
        return dummy->next;
    }
};
```
