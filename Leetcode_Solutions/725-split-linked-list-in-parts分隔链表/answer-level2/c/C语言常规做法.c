假设root长度为length，那么前length%k个链表的长度为length/k，剩下的链表的长度为length/k。得出这一结论后，具体代码就不难写了。
```c
struct ListNode** splitListToParts(struct ListNode* root, int k, int* returnSize){
    struct ListNode** res=malloc(k*sizeof(struct ListNode*));
    short length=0,i,left,counter;
    struct ListNode* traverse=root, *tmp;
    while(traverse!=0){
        length++;
        traverse=traverse->next;
    }
    traverse=root;
    left=length%k;
    length=length/k;
    for(i=0;i<k;i++){
        counter=length+(left>0)-1;
        res[i]=traverse;
        while(counter&&traverse){
            traverse=traverse->next;
            counter--;
        }
        if(traverse){
            tmp=traverse->next;
            traverse->next=0;
        }
        else tmp=0;
        traverse=tmp;
        left--;
    }
    *returnSize=k;
    return res;
}
```