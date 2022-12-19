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
//head 不是头节点 空的
    ListNode* reverseList(ListNode* head) {
        ListNode *p = NULL;//前驱结点,虽然马上前驱变后驱了
        ListNode *tmp = NULL;//缓存下一个结点
        ListNode *q = NULL;//当前指针
        //pHead本身不存在,只有头结点 即pHead->next = NULL,或者只有头结点和1个业务结点也不需要逆置
        if (head ==NULL || head->next == NULL)
        {
            return head;
        }

        p = head;
        q = head->next;

        //一个结点一个结点的逆置
        while (q)  //其实就是while(q!=NULL)
        {
            tmp = q->next;
            q->next = p;  //逆置
            p = q;//让p下移一个结点
            q = tmp;
        }
        //头结点变成尾部 后置,成null//必须先这一步
        head->next= NULL;        
        

        return p;

    }
};