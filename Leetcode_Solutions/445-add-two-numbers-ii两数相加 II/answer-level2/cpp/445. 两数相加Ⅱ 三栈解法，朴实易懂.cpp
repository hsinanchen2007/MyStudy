![image.png](https://pic.leetcode-cn.com/3bc91eb46a501ca29d75657c0407db6a5829e2ce251fb02437211b31440ed33b-image.png)

```
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        //因为对于链表来说：先遍历的节点是后计算的，所以要想到栈的用法，先进后出。
        stack<ListNode*> s1;
        stack<ListNode*> s2;
        while(l1!=NULL)
        {
            s1.push(l1);
            l1=l1->next;
        }
        while(l2!=NULL)
        {
            s2.push(l2);
            l2=l2->next;
        }

        int flag=0;//初始化进位符
        stack<int> s3;//存储每一位的加和结果
        while(!s1.empty()||!s2.empty()||flag==1)//这里的flag为1其实是防止遇到[5]和[5]这种情况
        {
            int num=0;//用num来记录每个位置相加的结果
            if(!s1.empty())
            {
                num+=s1.top()->val;
                s1.pop();
            }
            if(!s2.empty())
            {
                num+=s2.top()->val;
                s2.pop();
            }
            num+=flag;
            //判断sum与10的关系，进而o推出有没有进位符号
            if(num>=10)
            {
                num=num%10;
                flag=1;
            }
            else flag=0;
            
            //将最终的加和结果存到栈s3中
            s3.push(num);
        }

        //从s3栈输出结果
        ListNode* pHead=new ListNode(s3.top());
        s3.pop();
        ListNode* work=pHead;
        while(!s3.empty())
        {
            ListNode* temp=new ListNode(s3.top());
            s3.pop();
            work->next=temp;
            work=work->next;       
        }
        return pHead;      
    }
};
```
