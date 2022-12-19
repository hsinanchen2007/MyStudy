- 获取链表长度，并根据除法和模运算的结果，将链表划分，获取每个元素的链表长度
- 注意，当链表为空时的特殊处理。
```
int getListLenth(struct ListNode* lst){
    struct ListNode* tmp = lst;
    int len = 0;
    while(tmp != NULL){
        len ++;
        tmp = tmp -> next;
    }
    return len;
}
struct ListNode** splitListToParts(struct ListNode* root, int k, int* returnSize){
    int len = getListLenth(root);
    struct ListNode** returnListNode = (struct ListNode**)malloc(sizeof(struct ListNode*) * k);
    int num = len / k;
    int mod = len % k;
    struct ListNode* p = root;
    if(len == 0){
        for(int i = 0; i < k; i++){
           returnListNode[i] = p;
        }
        *returnSize = k;
        return returnListNode;
    }
    if(mod == 0){
        for(int i = 0; i < k; i++){
            int cnt = num;
            returnListNode[i] = p;
            cnt --;
            while(cnt > 0){
                p = p -> next;
                cnt --;
            }
            struct ListNode* tmp= p -> next;
            p -> next = NULL;
            p = tmp;
        }
    }else{
        for(int i = 0; i < mod; i++){
            int cnt = num + 1;
            returnListNode[i] = p;
            cnt --;
            while(cnt > 0){
                p = p -> next;
                cnt --;
            }
            struct ListNode* tmp= p -> next;
            p -> next = NULL;
            p = tmp;
        }
        if(num == 0){
            for(int i = mod; i < k; i++){
                returnListNode[i] = NULL;
            }
        }else{
            for(int i = mod; i < k; i++){
                int cnt = num;
                returnListNode[i] = p;
                cnt --;
                while(cnt > 0){
                    p = p -> next;
                    cnt --;
                }
                struct ListNode* tmp= p -> next;
                p -> next = NULL;
                p = tmp;
            }
        }
    }
    *returnSize = k;
    return returnListNode;
}
```
