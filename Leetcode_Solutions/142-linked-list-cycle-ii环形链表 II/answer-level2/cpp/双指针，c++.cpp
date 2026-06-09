### 解题思路
做过这道题的应该都做过判断是否有环的那个题，前半段不赘述
之后我先让其中一个指针不动，另一个循环直到两指针重合，计算出环长度
再将两指针定位到head，再使其中一指针领先另一指针环长度，两者再进行递加，直到两指针重合，这就是环开头

### 代码

```cpp
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL||(*head).next==NULL)return NULL;
        ListNode *i=head,*j=head;
        while(1){
            j=j->next;
            if((*j).next==NULL)return NULL;
            if(j==i)break;
            i=i->next;
            j=j->next;
            if((*j).next==NULL)return NULL;
            if(j==i)break;
        }//judge if it is circle
        
        int len=1;
        j=j->next;
        while(j!=i){
            j=j->next;
            len++;
        }//value the length
        
        i=j=head;
        for(int k=0;k<len;k++){
            j=j->next;
        }
        while(i!=j){
            i=i->next;
            j=j->next;
        }
        return i;

    }
};
```