### 此处撰写解题思路
常规思路
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* printNumbers(int n, int* returnSize){
    int size=pow(10,n);
    int* num=(int*)malloc(sizeof(int)*size);
    int cnt=0;
    for(int i=1;i<size;i++)
    {
        num[cnt++]=i;
    }
    *returnSize=cnt;
    return num;
}
```