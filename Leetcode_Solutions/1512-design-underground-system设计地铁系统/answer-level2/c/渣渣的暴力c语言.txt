### 解题思路
渣渣的暴力c语言

### 代码

```c
typedef struct UndergroundSystem{
    int i;
    char *str;
    int t;
    int in;
    struct UndergroundSystem * next;
    
} UndergroundSystem;


UndergroundSystem* undergroundSystemCreate() {
    struct UndergroundSystem * head=(struct UndergroundSystem *)malloc(sizeof(UndergroundSystem ));
    head->next=NULL;
    return head;
}

void undergroundSystemCheckIn(UndergroundSystem* obj, int id, char * stationName, int t) {
    struct UndergroundSystem * q=obj;
    while(q->next!=NULL)
    {
        q=q->next;
    }
    struct UndergroundSystem * p=(struct UndergroundSystem *)malloc(sizeof(UndergroundSystem ));
    p->i=id;
    p->str=stationName;
    p->in=1;
    p->t=t;
    p->next=NULL;
    q->next=p;
}
void undergroundSystemCheckOut(UndergroundSystem* obj, int id, char * stationName, int t) {
    struct UndergroundSystem * q=obj;
    while(q->next!=NULL)
    {
        q=q->next;
    }
    struct UndergroundSystem * p=(struct UndergroundSystem *)malloc(sizeof(UndergroundSystem ));
    p->i=id;
    p->str=stationName;
    p->in=0;
    p->t=t;
    p->next=NULL;
    q->next=p;
}

double undergroundSystemGetAverageTime(UndergroundSystem* obj, char * startStation, char * endStation) {
    struct UndergroundSystem* q=obj->next;
    struct UndergroundSystem* p;
    int i,k=0,sum=0;
    while(q!=NULL)
    {
        if(0==strcmp(startStation,q->str)&&q->in)
        {
            p=q->next;
            
            while(p!=NULL)
            {
                if(0==strcmp(endStation,p->str)&&p->i==q->i&&p->in==0)
                {
                    printf("p->t= %d  q->t =%d\n",p->t,q->t);
                    sum=p->t-q->t+sum;
                    k++;
                    break;
                }
                p=p->next;
            }
        }
        q=q->next;
    }
    printf("sum=%d  k=%d\n",sum,k);
    return sum*1.0/k;
}

void undergroundSystemFree(UndergroundSystem* obj) {
    
}

/**
 * Your UndergroundSystem struct will be instantiated and called as such:
 * UndergroundSystem* obj = undergroundSystemCreate();
 * undergroundSystemCheckIn(obj, id, stationName, t);
 
 * undergroundSystemCheckOut(obj, id, stationName, t);
 
 * double param_3 = undergroundSystemGetAverageTime(obj, startStation, endStation);
 
 * undergroundSystemFree(obj);
*/
```