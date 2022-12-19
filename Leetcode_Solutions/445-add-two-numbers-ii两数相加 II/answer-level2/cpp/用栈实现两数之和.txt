### 解题思路
stack 

### 代码

```cpp
/*
top()返回栈顶元素但不删除,可以用完top再加个pop
pop()返回值为void ，只是删除栈顶元素
empty()
push()
size()
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int>* l1Stack=createStack(l1);
        stack<int>* l2Stack=createStack(l2);
        int carry=0;
        int x=0,y=0;
        ListNode* head= NULL;
        //当栈元素全部弹出并且没有进位时结束
        while(!l1Stack->empty()||!l2Stack->empty()||carry!=0){
            //如果有一个栈元素弹空，则都是0
            if(l1Stack->empty()){
                x=0;
            }else{
                x=l1Stack->top();
                l1Stack->pop();
            }
            if(l2Stack->empty()){
                y=0;
            }else{
                y=l2Stack->top();
                l2Stack->pop();
            }
            //不要忘了加上进位
            int sum=x+y+carry;
            //个位数留下，十位数当进位
            ListNode* node=new ListNode(sum%10);
            //头插法
            node->next=head;
            head=node;
            //进位等于/10
            carry=sum/10;
        }
        return head;
    }

    stack<int>* createStack(ListNode*l){
        stack<int>* myStack=new stack<int>;
        while(l!=NULL){
            myStack->push(l->val);
            l=l->next;
        }
        return myStack;
    }
};
```