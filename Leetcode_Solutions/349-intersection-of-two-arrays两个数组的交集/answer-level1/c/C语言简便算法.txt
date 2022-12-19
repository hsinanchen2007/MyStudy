```
#include <stdlib.h>
int cmp ( const void *a , const void *b ) 
{
    return *(int *)a - *(int *)b; 
}
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    if(nums1Size==0 || nums2Size==0){
        *returnSize = 0;
        return 0;
    }
    
    int max = (nums1Size>nums2Size) ? nums1Size : nums2Size;

    int* bot = (int*)malloc(sizeof(int)*max);
    int i, j, k = 0, u, z = 1;
    for(i = 0; i < nums1Size; i++){
        for(j = 0; j < nums2Size; j++)
            if(nums1[i]==nums2[j]){
                bot[k++] = nums1[i];
                continue;
            }
    }

    if(k==0){
        *returnSize = 0;
        return 0;
    }

    // 对u排序
    qsort(bot,k,sizeof(bot[0]),cmp);

    for(u = 1; u < k; u++){
        if(bot[z-1]==bot[u]) continue;
        else bot[z++] = bot[u];
    }
    
    *returnSize = z;
    return bot;
}
```
