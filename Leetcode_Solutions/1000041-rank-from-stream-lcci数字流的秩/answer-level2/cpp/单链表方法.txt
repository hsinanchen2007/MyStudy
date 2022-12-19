### 解题思路
用这种方法效率不怎么高，主要提供一种思路
链表中
插入的时候选择好插入位置，保证链表递增有序，
插入成功后对后序的节点的秩都进行更新，也就是加一。
查找时找到小于等于输入值的节点的秩将其输出即可。
### 代码

```cpp
class StreamRank {
public:
    struct node{
        int x;
        int z;
        struct node* next;
    };
    struct node* head=(struct node*)malloc(sizeof(struct node));
    
    StreamRank() {
        head->next=NULL;
        head->z=0;
        head->x=INT_MAX;
    }
    
    void track(int x) {
        if(head->next==NULL){
            struct node *p=(struct node*)malloc(sizeof(struct node));
            p->next=NULL;
            p->x=x;
            p->z=1;
            head->next=p;
        }else{
            struct node *t=head;
            while(t->next!=NULL&&t->next->x<=x){
                t=t->next;
            }
            if(t->x==x){
                t->z+=1;
                t=t->next;
                while(t!=NULL){
                    t->z+=1;
                    t=t->next;
                }
            }else{
                struct node *p=(struct node*)malloc(sizeof(struct node));
                p->next=t->next;
                p->x=x;
                p->z=t->z+1;
                t->next=p;
                t=p->next;
                while(t!=NULL){
                    t->z+=1;
                    t=t->next;
                }
            }
            
        }
    }
    
    int getRankOfNumber(int x) {
        struct node *t=head;
        while(t->next!=NULL&&t->next->x<=x){
            t=t->next;
        }
        
        return t->z;
        
    }
};

/**
 * Your StreamRank object will be instantiated and called as such:
 * StreamRank* obj = new StreamRank();
 * obj->track(x);
 * int param_2 = obj->getRankOfNumber(x);
 */
```