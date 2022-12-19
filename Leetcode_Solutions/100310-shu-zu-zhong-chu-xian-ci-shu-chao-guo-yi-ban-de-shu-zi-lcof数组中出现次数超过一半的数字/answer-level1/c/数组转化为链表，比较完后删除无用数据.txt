### 解题思路
可惜了，一波骚操作下来用时32ms，只打败44.85%，出发点是加快执行速度的，大概是数组不够长吧...
不过内存消耗12MB，击败100%...这我也相当想不清楚了哈哈

### 代码

```c
struct listnode{
    int val;
    struct listnode* next;
};

int majorityElement(int* nums, int numsSize){
    struct listnode* head=(struct listnode*)malloc(sizeof(struct listnode));
    struct listnode* head_flag=head;
    head->val=nums[0];
    
    if(numsSize==1){return nums[0];}
    for(int i=1;i<numsSize;i++){
        struct listnode* node=(struct listnode*)malloc(sizeof(struct listnode));
        node->val=nums[i];
        node->next=NULL;
        head->next=node;
        head=head->next;
    }

    int temp_value=head_flag->val;
    int count=1;
    struct listnode* node_now=head_flag;
    while(node_now->next){
        if(node_now->next->val==temp_value){
            count++;
            if(count>numsSize/2){return temp_value;}
            if(node_now->next->next){
                node_now->next=node_now->next->next;
            }
            else{
                node_now->next=NULL;
                head_flag=head_flag->next;
                temp_value=head_flag->val;
                node_now=head_flag;
            }  
        }
        else{
            node_now=node_now->next;
            if(!node_now->next){
                head_flag=head_flag->next;
                temp_value=head_flag->val;
                node_now=head_flag;
            }
        }
    }
    return temp_value;
}
```