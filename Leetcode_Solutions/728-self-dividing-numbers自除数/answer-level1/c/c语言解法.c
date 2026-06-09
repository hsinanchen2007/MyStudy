### 解题思路
先malloc一个足够大的数组，然后在区间内遍历，如果发现整数中存在0或者不是自除数，flag=1，跳出循环。如果flag为0，则进行赋值，cnt用来记录数组大小。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* selfDividingNumbers(int left, int right, int* returnSize){
    int cnt=0;
    int*num=(int*)malloc(sizeof(int)*(right-left+1));
    for(int i=left;i<=right;i++)
    {
        int temp=i;
        int flag=0;
        while(temp!=0)
        {
            if(temp%10==0||(i%(temp%10))!=0)
            {
                flag=1;
                break;
            }
            temp/=10;
        }
        if(flag!=1)
        num[cnt++]=i;
    }
    *returnSize=cnt;
    return num;
}


```