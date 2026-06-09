### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumZero(int n, int* returnSize){   
        int *num;
        num = calloc(n,sizeof(int));
        int i =0;
        for(int j =0;j<n;j++) printf("%d",num[j]);
        for(;i<n/2;i++)
        {
            
            num[i] = -i-1;
            num[n-i-1] = i+1;
        }
        for(int j =0;j<n;j++) printf("%d",num[j]);
        *returnSize = n;
        return num;
}
```