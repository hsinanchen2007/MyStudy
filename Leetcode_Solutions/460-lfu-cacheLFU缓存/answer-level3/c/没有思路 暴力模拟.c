### 解题思路
垃圾小白肝了4个小时写出的拙码

每次输出把节点放到最后  并num+1;
输入判断
1是否有key
2是否超缓存
  若超判断num最小 且靠前的 删掉
  若不超直接在最后添加
### 代码

```c
typedef struct LFUCache{
    int key;
    int val;
    int num; //每输出一次加一
    struct LFUCache *next;
}LFUCache; 


LFUCache* lFUCacheCreate(int capacity) {
    struct LFUCache *head=(struct LFUCache*)malloc(sizeof(struct LFUCache)*1);
    head->num=capacity;//头节点 记录最多缓存几个
    head->val=0;//当前缓存了几个
    head->next=NULL;
    return head;
}

int lFUCacheGet(LFUCache* obj, int key) {
    if(obj->val==0)return -1;
    struct LFUCache *p=obj->next;
    struct LFUCache *prev=obj;
    struct LFUCache *nextp=p->next;
    while(p->next!=NULL)
    {
        if(p->key==key)
        {
            prev->next=nextp;
            struct LFUCache *q=obj;
            while(q->next!=NULL)
            {
                q=q->next;
            }
            q->next=p;
            p->next=NULL;
            p->num++;
            return p->val;
        }
        prev=p;
        nextp=p->next->next;
        p=p->next;
    }
    
        if(p->key==key)
        {
            prev->next=nextp;
            struct LFUCache *q=obj;
            while(q->next!=NULL)
            {
                q=q->next;
            }
            q->next=p;
            p->next=NULL;
            p->num++;

            return p->val;
        }
        

    return -1;
}

void lFUCachePut(LFUCache* obj, int key, int value) {
    if(obj->num==0)
    return ;
    struct LFUCache *p=obj->next;
    while(p!=NULL)
        {
            if(p->key==key)
            {
            p->val=value;
            p->num+=1;
            return; 
            }
        p=p->next;
        }
    p=obj;
    struct LFUCache *q=(struct LFUCache*)malloc(sizeof(struct LFUCache)*1);
    q->next=NULL;
    q->key=key;
    q->val=value;
    q->num=0;
    if(obj->val<obj->num)
    {
        obj->val+=1;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=q;
    }else
    {
        int min=99999;
        struct LFUCache *a=obj->next;
        while(a->next!=NULL)
        {
            
            if(min>a->num)
            {
                min=a->num;
            }
            a=a->next;
        }
        if(min>a->num)
        {
            min=a->num;
        }
        
        a=obj->next;
        struct LFUCache *prev=obj;
        struct LFUCache *nextp=a->next;
        while(a->next!=NULL)
        {
            if(a->num==min)
            {
                prev->next=nextp;
                break;
            }
            prev=a;
            nextp=a->next->next;
            a=a->next;
        }
        if(a->num==min)
            {
                prev->next=nextp;
                
            }
            
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=q;
    }
}

void lFUCacheFree(LFUCache* obj) {
    
}

/**
 * Your LFUCache struct will be instantiated and called as such:
 * LFUCache* obj = lFUCacheCreate(capacity);
 * int param_1 = lFUCacheGet(obj, key);
 
 * lFUCachePut(obj, key, value);
 
 * lFUCacheFree(obj);
*/
```