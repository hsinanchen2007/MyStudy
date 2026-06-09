4ms 8.8M
```/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //从栈中弹出一个节点
    void stpop(stack<ListNode*> &st,ListNode* &pre){
        ListNode *pourcur = st.top();
        st.pop();
        pourcur->next = pre;
        pre = pourcur;
    }
    
    ListNode* swapPairs(ListNode* head) {
        //边界条件
        if(!head||!head->next)
            return head;
        //使用两个栈 分别存储奇数位置节点和偶数位置节点
        stack<ListNode*> oddst;
        stack<ListNode*> evenst;
        //开始遍历链表存储数据 需要把存储节点的next指针置空
        int index = 0;
        ListNode *cur = head;
        ListNode *storenode = NULL;
        while(cur){
            index+=1;
            storenode = cur;
            cur=cur->next;
            storenode->next=NULL;
            //奇数序列
            if(index%2 == 1){
                oddst.push(storenode);
            }else{
                //偶数序列
                evenst.push(storenode);
            }
        }
        //开始倾倒两个栈
        ListNode *pourcur=NULL;
        ListNode *newpre=NULL;
        //总节点数是奇数 oddst中多一个节点 因此先弹出
        if(index%2==1){
            stpop(oddst,newpre);
        }
        while(!oddst.empty()||!evenst.empty()){
            //先弹出奇数栈首元素
            if(!oddst.empty()){
                stpop(oddst,newpre);
            }
            //再弹出偶数栈首元素
            if(!evenst.empty()){
                stpop(evenst,newpre);
            }
        }
        return newpre;
    }
};

```
