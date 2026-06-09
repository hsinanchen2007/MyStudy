### 解题思路
此处撰写解题思路
这个题直接用优先队列然后把vector里面所有的元素都放进去，然后while()循环检查队列是否为空，有一点bfs的感觉。
不过最骚的还是我之前一直是直接重载>来写小堆或者大堆。。嗯。。然后一直报错。。。
之前重载运算符的代码
class Solution {
public:
       //对新的数据类型的<进行重写
       bool operator >(ListNode *a,ListNode *b){
          return a->val > b->val;
       }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
          priority_queue<ListNode*, vector<ListNode *>,greater<ListNode*>> q;
          ListNode *head=new ListNode(0);
          ListNode *pre=head;  //浅拷贝 操作同一个链表
          for(auto list:lists)
          {
              if(list==NULL)
                  continue;
              q.push(list);
          }
          while(q.empty()!=true)
          {
              ListNode* p=new ListNode(0);
              ListNode* temp=q.top();
              p->val=temp->val;
              pre->next=p;
              pre=pre->next;
              if(temp->next!=NULL)
              {
                  temp=temp->next;
                  q.pop();
                  q.push(temp);
              }
              else
              {
                  q.pop();
              }
          }
          return head->next;
    }
};
没找到啥原因。。确实基础还是不太牢，这里分享一下解题思路。
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
    struct cmp{  //对新的数据类型的<进行重写
       bool operator()(ListNode *a,ListNode *b){
          return a->val > b->val;
       }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
          priority_queue<ListNode*, vector<ListNode *>,cmp> q;
          ListNode *head=new ListNode(0);
          ListNode *pre=head;  //浅拷贝 操作同一个链表
          for(auto list:lists)
          {
              if(list==NULL)
                  continue;
              q.push(list);
          }
          while(q.empty()!=true)
          {
              ListNode* p=new ListNode(0);
              ListNode* temp=q.top();
              p->val=temp->val;
              pre->next=p;
              pre=pre->next;
              if(temp->next!=NULL)
              {
                  temp=temp->next;
                  q.pop();
                  q.push(temp);
              }
              else
              {
                  q.pop();
              }
          }
          return head->next;
    }
};
```