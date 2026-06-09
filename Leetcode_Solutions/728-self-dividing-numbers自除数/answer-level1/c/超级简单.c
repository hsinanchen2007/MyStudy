### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 bool iszichushu(int num){
     int temp=num;
     while(temp){
         int i=temp%10;
         temp/=10;
         if(i==0)
            return 0;
         if(num%i){
             return 0;
         }
     }
     return 1;
 }
int* selfDividingNumbers(int left, int right, int* returnSize){
    int* res=(int*)calloc((right-left+1),sizeof(int));
    int temp=left;
    int i=0;
    while(temp<=right){
        if(iszichushu(temp))
            res[i++]=temp;
        temp++;
    }
    *returnSize=i;
    return res;
}
```