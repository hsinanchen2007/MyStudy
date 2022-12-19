### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int isZichushu(int a){
    int c=a;
    while(a>0)
    {
        int b=a%10;
        if(b==0||c%b!=0){
            return false;
        }
        a/=10;
    }
    return 1;
}
int* selfDividingNumbers(int left, int right, int* returnSize){
    int i=left,count=0;
    int *res=(int*)malloc(sizeof(int)*(right-left+1));
    while(i<=right){
        if(isZichushu(i)==1){
            res[count++]=i;
        }
        i++;
    }
    *returnSize=count;
    return res;
}
```