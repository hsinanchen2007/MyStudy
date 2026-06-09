### 解题思路
遍历

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int min=nums1Size<nums2Size?nums1Size:nums2Size;
    int* num=(int*)malloc(sizeof(int)*min);
    int cnt=0;
    for(int i=0;i<nums1Size;i++)
    {
        for(int j=0;j<nums2Size;j++)
        {
            if(nums1[i]==nums2[j])
            {
                int flag=0;
                for(int k=0;k<min;k++)
                {
                    if(num[k]==nums1[i])
                    flag=1;
                }
                if(flag!=1)
                {
                    num[cnt++]=nums1[i];
                }
                
            }
        }
    }
    *returnSize=cnt;
    return num;
}


```