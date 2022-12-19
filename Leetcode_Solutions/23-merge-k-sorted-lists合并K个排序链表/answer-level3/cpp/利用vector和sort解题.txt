### 解题思路
先将所有的链表里的数，通过循环方式取出来，push_back到一个新的vector里，利用sort函数
进行sort(newvector.begin(),newvector.end())进行排序，然后自定义一个返回类型的链表，头指针为 s，指向头节点，再定义一个辅助循环的指针t，不断进行链表赋值和遍历

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>temp;   //新的vector 
        for(int i=0;i<lists.size();++i) //对容器中的每个链表循环
        {
            ListNode*q;     //用q遍历第i个链表          
            for(q=lists[i];q!=NULL;q=q->next)
            {
                temp.push_back(q->val); //将值存入咱们的vector
            }
           
        }
        sort(temp.begin(),temp.end());  //sort排序
        ListNode*s;// 链表头指针
        s=new ListNode(0); //头结点
        ListNode*t;//辅助遍历赋值指针
        t=s;   //也指向头节点
        for(int i=0;i<temp.size();++i) //遍历咱们的vector
        {
           t->next=new ListNode(temp[i]); //将其值一一赋值给链表s
           t=t->next;        //迭代向前
        }
        s=s->next; //去掉头结点，让s直接指向第一个数据结点
        return s;    //返回类型
    }
};
```