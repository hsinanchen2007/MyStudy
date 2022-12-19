### 解题思路
1、置空法
2、注意各种情况下的判断语句

### 代码
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(!head) return false;
    bool b;
    struct ListNode *p;
    p=head->next;
    if(p){
        while(p->next){
            if(p->next->val==NULL)break;
            p->val=NULL;
            p=p->next;
            // p->val=NULL;
        } 
   }
        //注意条件判断的顺序以及逻辑连接词
        if(!p||!p->next) b=false;
        else if(p->next->val==NULL) b=true;
    return b;
}
```

