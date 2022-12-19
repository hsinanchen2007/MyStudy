

```
 int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    #define H_SIZE 100
    typedef struct member_tag
    {
        int val;
        int index;
        struct member_tag *next;
    }member_t;
    
    member_t **h_table = malloc(H_SIZE * sizeof(struct member_tag *));
    if(h_table == NULL)
        return NULL;
    memset(h_table, 0, H_SIZE * sizeof(struct member_tag *));
    
    int i;
    for(i = 0; i < numsSize; i++)
    {
        member_t *tmp = malloc(sizeof(struct member_tag));
        if(tmp == NULL)
            return NULL;
        
        tmp->val = nums[i];
        tmp->index = i;
        
        int k = abs(nums[i]) % H_SIZE;
        tmp->next = h_table[k];
        h_table[k] = tmp;
    }
    
    int find_flag = 0;
    int *result = NULL;
    for(i = 0; i < numsSize; i++)
    {
        int value = target - nums[i];
        int k = abs(value) % H_SIZE;
        
        member_t *tmp = h_table[k];
        while(tmp != NULL)
        {
            if(tmp->val == value && tmp->index != i)
            {
                result = malloc(2 * sizeof(int));
                if(result == NULL)
                    return NULL;
                
                result[0] = i;
                result[1] = tmp->index;
                *returnSize = 2;
                find_flag = 1;
                break;
            }
            
            tmp = tmp->next;
        }
        
        if(find_flag)
            break;
    }
    
    for(i = 0; i < H_SIZE; i++)
    {
        while(h_table[i] != NULL)
        {
            member_t *tmp = h_table[i];
            h_table[i] = tmp->next;
            free(tmp);
        }
    }
    free(h_table);
    
    return result;
}


```
