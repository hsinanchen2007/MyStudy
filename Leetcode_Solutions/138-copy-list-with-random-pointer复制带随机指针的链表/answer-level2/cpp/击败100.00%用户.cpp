### 解题思路
![2019-12-31_200810.png](https://pic.leetcode-cn.com/1a09735047029d1ce399a9ac172b87e967bb7654b95e865e6dab989f949ccc99-2019-12-31_200810.png)
此处撰写解题思路
**先深拷贝next指针，接着深拷贝random指针。**
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
        if(!head)
            return head;
        Node *h=head->next;
        Node *t = new Node(head->val);
        Node *tail=t;
        while(h)
        {
            Node *n=new Node(h->val);
            tail->next=n;
            tail=n;
            h=h->next;
        }
        h=head;
        tail=t;
        Node *p1=head,*p2=t;
        while(h)
        {
            p1=head;
            p2=t;
            while(p1)
            {
                if(h->random == p1)
                {
                    tail->random=p2;
                    break;
                }
                p1=p1->next;
                p2=p2->next;
            }
            tail=tail->next;
            h=h->next;
        }
        return t;
    }
};
```