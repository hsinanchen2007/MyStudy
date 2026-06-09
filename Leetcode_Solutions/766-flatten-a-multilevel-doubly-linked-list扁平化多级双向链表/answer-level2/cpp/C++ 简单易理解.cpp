### 代码

```cpp
class Solution {
public:
    Node* flatten(Node* head) {
        for(Node *h = head; h; h = h->next){
            if(h->child){
                Node *temp = h->next;
                h->next = h->child;
                h->child->prev = h;
                h->child = NULL;
                Node *p = h->next;
                while(p->next) p = p->next;
                p->next = temp;
                if(temp) temp->prev = p;
            }
        }
        return head;
    }
};
```