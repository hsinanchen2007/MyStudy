### 解题思路
注意一下是a!=nullptr不是a->next!=nullptr
以及拆分时的写法！！！！！！！

### 代码

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* a=head;//head不动
        if(head==nullptr) return a;
        while(a!=nullptr)//不是a->next!=null
        {
            Node* p=new Node(a->val);//p是定义的指针节点
            Node* c=a->next;//保存a后面节点的位置
            a->next=p;
            p->next=c;
            a=p->next;//a=p->next->next//a=c
        }

        a=head;//头节点
        while(a!=nullptr)//不是a->random!=nullptr
        {//判断是否为空
            if(a->random!=nullptr)
                a->next->random=a->random->next;//p->random指向a->random->next
            a=a->next->next;
        }

        //拆分
        a=head;//头节点
        Node* d=head->next;
        Node* phead=head->next;//指向p系列的第一个指针，作为返回值
        while(a!=nullptr)
        {
            /*d=a->next;
            a->next=d->next;
            a=a->next;
            d->next=a==nullptr?nullptr:a->next;*/
            
            a->next=a->next->next;
            a=a->next;
            if(d->next!=nullptr)//
            {
                d->next=d->next->next;
                d=d->next;

            }
        }
        return phead;
    }
};
```