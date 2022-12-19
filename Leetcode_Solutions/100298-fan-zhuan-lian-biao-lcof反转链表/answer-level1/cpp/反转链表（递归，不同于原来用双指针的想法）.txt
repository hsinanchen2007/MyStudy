### 解题思路
递归的思路与理解，还是那几个步骤（写二叉树类型题目的步骤）
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
public:   //用递归写试试。。
    ListNode *t;
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr||head->next==nullptr) return head;  
        res(head);
        return t;
    }
    ListNode *res(ListNode *head){
        if(head->next==nullptr) {    //终止条件 
            t=head;                  
            return head;
        }
        ListNode *p=res(head->next);  //递归（只是不是二叉树那种左右递归而已） 
        ListNode *q=p->next;          //该节点需要做什么:该节点需要做的是将该节点插入到返回节点的后面
        p->next=head;
        head->next=q;
        return head;                  //返回值：返回原节点
    }
};


```cpp
/*这位大佬的思路比我的清晰多了，虽然我的能写出来，但是有些地方还是没想到的，例如[1,2,3,4,5]当递归返回到2这个位置时，就算3在回溯的时候可能多一个父节点和子节点，但是改变不了他还有一个原链表的父节点*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* ret = reverseList(head->next);
        head->next->next = head;  //就是我之前说的当前节点的值指向原本链表该节点的后一个值，就不需要我上面写的代码那种方式
        head->next = NULL;
        return ret;
    }
};

作者：huwt
链接：https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/solution/fan-zhuan-lian-biao-yi-dong-de-shuang-zhi-zhen-jia/
