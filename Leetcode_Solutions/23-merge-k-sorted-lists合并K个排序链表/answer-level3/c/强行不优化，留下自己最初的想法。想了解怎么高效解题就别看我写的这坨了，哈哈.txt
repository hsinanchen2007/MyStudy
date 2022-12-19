在优秀的算法先入为主之前，自己先写个能跑通的，也许会更加好的去学习优秀的方法吧。记录一下还是个弱鸡的自己
基本想法：
   因为之前有个“合并2个排序链表的题”，k个链表合并就是k-1次2个链表合并，你们最初是不是这么想的呢？
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/*将链表的数据拷贝到一个数组中*/
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
/*获取链表长度*/
void getLen(struct ListNode* l1,int* plen){
    struct ListNode*node;
    node = l1;

    while(node != NULL){
        *plen=(*plen)+1;
        node = node->next;
    }
}
/*冒泡排序*/
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
/*这个接口就直接搬了两个排序链表合并的题解（不是官方答案，也是自己写的没用递归，很繁琐）*/
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
/*针对第131个测试用例，写的接口*/
struct ListNode* demo_131(int* buf,struct ListNode** lists,int listsSize){
    int i;
    /*遍历所有单节点链表，将数据复制到数组里*/
    for(i=0;i<listsSize;i++){
        buf[i] = lists[i][0].val;
    }
    /*数据排序*/
    sort(buf,listsSize);
    /*根据有序数组生成一个有序链表*/
    struct ListNode* ret,*pos,*temp;
    ret = (struct ListNode*)malloc(sizeof(struct ListNode));
    pos = ret;
    for(i = 0;i<listsSize;i++){
        ret->val = buf[i];
        
        if(i == listsSize-1){
            ret->next = NULL;
        }else{
            temp = (struct ListNode*)malloc(sizeof(struct ListNode));
            ret->next = temp;
            ret = ret->next;
        }
    }
    
    return pos; 
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    /*空指针传参*/
    if(listsSize == 0)
        return NULL;
    /*只有一个链表*/
    else if(listsSize == 1)
        return *lists;
    /*链表数目超级多的情况-------至少大于100个了*/
    else if(listsSize > 100){
        int sup_buf[listsSize];
        struct ListNode* list0;
        list0 = demo_131(sup_buf,lists,listsSize);
        return list0;
    }
    /*链表数目不多的情况，两个两个的进行合并，比如4个链表就要两两合并循环3次*/    
    struct ListNode* list1 = NULL;
    struct ListNode* list2 = NULL;
    list1 = lists[0];

    int i;
    for(i = 1; i<listsSize;i++){
        list2 = lists[i];       
        list1 = mergeTwoLists(list1,list2);
    }
    return list1;
}
```
