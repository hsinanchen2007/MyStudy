### 解题思路
此处撰写解题思路
![2020-01-08_235412.png](https://pic.leetcode-cn.com/86386587c444c0b6113cd649b744bdbde7903a1961fd426cb9c655f1f5b8fc3e-2020-01-08_235412.png)
按照题目要求，直接用递归法。--内存消耗：击败100%用户
### 代码

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        if(!head)
            return head;
        Node *p=new Node;//1、新开辟一个空间，如果直接用head的，后面返回的又是head
        Node *tail=p,*h=head;
        tail->prev=nullptr;
        tail->next=nullptr;
        tail->child=nullptr;
        tail->val=head->val;

        if(h->child)
        {
            Node *t = flatten(h->child);//2、插入子链表
            //if(t)//肯定不为空，故不用判断
            {
                t->prev=tail;
                tail->next = t;
                if(!h->next)
                    return p;
                 while(t->next)
                {
                    t=t->next;
                }
                tail=t;
            }
        }
        //else//这里必须注释掉else，不然没有链表不全
        {
            
            Node *t = flatten(h->next);//3、插入下一个结点
            if(t)
            {
                t->prev=tail;
                tail->next=t;
                //这里不需要了，当前链表的后序结点，tail无需指向尾指针。
                //因为递归到最后一层，后面不用插入新结点了，直接返回上一层即可。
                //while(t&&t->next)
                //{
                //    t=t->next;
                //}
                //tail=t;
            }
        }
        return p;
    }
};
```