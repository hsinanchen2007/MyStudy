


```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct node{
    int key;
    int count;
    struct node *next;
}node;

typedef struct table{
    node** head;
    int len;
}table;

void init(table *t, int len){
    t->head = (node**)malloc(len*sizeof(node*));
    memset(t->head, 0, len*sizeof(node*));
    t->len = len;
}

node* hash_find(table *t, int val){
    int k = abs(val)%t->len;
    node* tmp = t->head[k];
    while (tmp){
        if(tmp->key == val){
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}

void hash_insert(table *t, int val){
    node* tmp = hash_find(t,val);
    if(tmp){
        tmp->count+=1;
        return;
    }
    tmp = (node*)malloc(sizeof(node));
    tmp->key=val;
    tmp->count=1;
    int k = abs(val)%t->len;
    tmp->next = t->head[k];
    t->head[k]=tmp;    
}

void hash_del(table *t, int val){
    node* tmp = hash_find(t, val);
    if(tmp!=NULL){
        tmp->count=0;
    }
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    table *table1 = (table*)malloc(sizeof(table));
    table *table2 = (table*)malloc(sizeof(table));
    init(table1, 1000);
    init(table2, 1000);
    for(int i=0;i<nums1Size;i++){
        hash_insert(table1, nums1[i]);
    }
    for(int i=0;i<nums2Size;i++){
        hash_insert(table2, nums2[i]);
    }
    int count = 0;
    node *t1,*t2;
    int* ans = (int*)malloc(nums1Size*sizeof(int));
    for(int i=0;i<nums1Size;i++){
        t1 = hash_find(table1, nums1[i]);
        t2 = hash_find(table2, nums1[i]);
        if(t1&&t2){
            if(t1->count!=0&&t2->count!=0){
                ans[count++]=nums1[i];
                hash_del(table1,nums1[i]);
                hash_del(table2,nums1[i]);
            }
        }
    }
    *returnSize = count;
    return ans;
}
```
