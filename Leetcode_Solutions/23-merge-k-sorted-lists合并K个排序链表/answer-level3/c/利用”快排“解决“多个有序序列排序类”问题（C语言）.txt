典型的多个有序序列，按顺序合并的问题。
通常的思路是利用各序列有序性，取出数据后，两两归并。
从另外一个角度考虑，由于各序列本身有序，因此将所有序列合并后进行快排，效率也能满足要求，且代码简洁清晰。
![image.png](https://pic.leetcode-cn.com/6934681fe9a658d67a1a00429eb77d918ac1e201a69967c1917f6ecc2590c46d-image.png)


```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#define MAX_LEN         10000

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

//【算法思路】合并多个有序序列，使用快排，思路简单效率高
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if(listsSize == 0)
        return NULL;
    
    int *res_ = (int *)malloc(MAX_LEN * sizeof(int));
    
    int cnt = 0;
    
    struct ListNode * cur;
    
    for(int i = 0; i < listsSize; i++)
    {
        cur = lists[i];
        
        while(cur != NULL)
        {
            res_[cnt++] = cur->val;
            
            cur = cur->next;
        }
    }
    
    if(cnt == 0)
        return NULL;
    
    qsort(res_, cnt, sizeof(int), compare);
    
    struct ListNode *res = (struct ListNode *)malloc(cnt * sizeof(struct ListNode));
    
    cur = &res[0];
    
    for(int i = 0; i < cnt - 1; i++)
    {
        cur->val = res_[i];
        
        cur->next = &res[i + 1];
        
        cur = cur->next;
    }
    
    cur->val = res_[cnt - 1];
    cur->next = NULL;
        
    return res;
}
```

