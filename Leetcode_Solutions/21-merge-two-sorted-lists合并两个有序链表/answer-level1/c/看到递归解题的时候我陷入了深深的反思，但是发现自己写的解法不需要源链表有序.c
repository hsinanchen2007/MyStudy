大佬勿喷，没利用好有序链表是真的蠢，上传一波留个痕迹（4ms，7.6MB）
大体思路就很直接：
   把链表里的数存到数组里，然后排序，用排序好的数组生成有序链表
```
void trav(struct ListNode* l1,int *ret){
    int i=0;
    struct ListNode*node;
    node = l1;

    while(node != NULL){
        ret[i] = node->val;
        node = node->next;
        i++;
    }
}
void getLen(struct ListNode* l1,int* plen){
    struct ListNode*node;
    node = l1;

    while(node != NULL){
        *plen=(*plen)+1;
        node = node->next;
    }
}
void sort(int * buf,int len){
    int i;
    int j;
    int temp;
    for(j = 0; j<len-1; j++){
        for(i =0;i<len-j-1;i++){
            if(buf[i]>buf[i+1]){
                temp = buf[i+1];
                buf[i+1] = buf[i];
                buf[i] = temp;
            }else{
                continue;
            }
        }
    }
}
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    int *buf1 = NULL;
    int *buf2 = NULL;
    int len1=0;
    int len2=0;
    int *buf = NULL;
    int i;
    /*获取两个链表的长度，并创建两个记录数据的数组*/
    getLen(l1,&len1);
    buf1 = (int*)malloc(len1*sizeof(int));
    getLen(l2,&len2);
    buf2 = (int*)malloc(len2*sizeof(int));
    if(len1+len2 == 0)
        return NULL;
    /*遍历两个链表，填充数组（尝试过获取长度的时候就一起记录数据，但是用自己定义的接口来实现的话，会导致申请的内存被释放掉）*/
    trav(l1,buf1);
    trav(l2,buf2);
    /*合并链表数据*/
    buf = (int*)malloc((len1+len2)*sizeof(int));
    if(len1 != 0)
        memcpy(buf,buf1,len1*sizeof(int));
    if(len2 != 0)
        memcpy(buf+len1,buf2,len2*sizeof(int));
    free(buf1);
    free(buf2);
    /*数组排序*/
    sort(buf,len1+len2);
        
    /*根据有序数组生成一个有序链表*/
    struct ListNode* ret,*pos,*temp;
    ret = (struct ListNode*)malloc(sizeof(struct ListNode));
    pos = ret;
    for(i = 0;i<len1+len2;i++){
        ret->val = buf[i];
        
        if(i == len1+len2-1){
            ret->next = NULL;
        }else{
            temp = (struct ListNode*)malloc(sizeof(struct ListNode));
            ret->next = temp;
            ret = ret->next;
        }
    }
    
    return pos; 
}
```
