```
typedef struct node{
    int val;
    struct node *next;
    int num;

};
typedef struct {
    struct node *min;//使用各个阶段最小值的链表组成
    int top; //栈顶指针
    int *array;
    
} MinStack;


#define MAXSIZE 10000 
#define EMPTY -1
/** initialize your data structure here. */

struct node* initialNode(int val,int num,int next){
    struct node *t=malloc (sizeof(struct node));
    t->val=val;
    t->num=num;
    t->next=next;
    return t;

}
MinStack* minStackCreate() {
    MinStack *S = malloc (sizeof(MinStack));
    if (!S) return NULL;
    S -> array  = (int *) malloc (sizeof(int) * MAXSIZE);
    S->min=malloc (sizeof(struct node));
    struct node *t=malloc (sizeof(struct node));//初始化为头结点为S->min,尾结点存储的是INT类型的最大值，后续采取头插法插入当前最小值结点，使得S->min->next始终指向当前栈的最小值结点
    t->next=NULL;
    t->val=INT_MAX;
    t->num=1;
    S -> top = -1;
    S -> min->val = INT_MAX;
    S->min->num=1;
    S->min->next=t;
    return S;
}


void minStackPush(MinStack* obj, int x) {
    obj->array[++ obj->top]=x;
    if(obj->min->next->val>x){//若当前插入结点为新的最小值，则插入到obj->min后面
        struct node *t=initialNode(x,1,NULL);
        t->next=obj->min->next;
        obj->min->next=t;
    }else if(obj->min->next->val==x)//若当前插入结点与当前最小值相同，则代表最小值数量的结点中num数量加一
        obj->min->next->num+=1;
        
}

void minStackPop(MinStack* obj) {
    if(obj->array[obj->top--]==obj->min->next->val)
    {
        obj->min->next->num--;
        if(!(obj->min->next->num)){//若当前pop的是最小值结点，则根据其Num数量决定是否从链表删除
            struct node *p=obj->min->next;
            obj->min->next=obj->min->next->next;
            free(p);
        } 
          
    }
}


int minStackTop(MinStack* obj) {
    return obj->array[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return obj->min->next->val;
}

void minStackFree(MinStack* obj) {
    free(obj->array);
    free(obj->min);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
```
