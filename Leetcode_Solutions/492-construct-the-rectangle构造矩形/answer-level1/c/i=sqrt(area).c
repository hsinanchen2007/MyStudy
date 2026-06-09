### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructRectangle(int area, int* returnSize){
    if(area==0){
        *returnSize=0;
        return NULL;
    } 
    int *ret,i,j;
    ret=(int*)malloc(sizeof(int)*2);
    *returnSize=2;
    for(i=sqrt(area);i>0;i--){
        j=area/i;
        if(i*j==area){
            ret[0]=j;
            ret[1]=i;
            return ret;
        }
    }
    return NULL;
}
```