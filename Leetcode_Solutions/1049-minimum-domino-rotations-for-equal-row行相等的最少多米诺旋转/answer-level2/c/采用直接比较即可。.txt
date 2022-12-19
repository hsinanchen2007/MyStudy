### 解题思路
如果A中元素正好与B中元素相同，则任意选取一个就可以，因为A，B正好对等。

### 代码

```c


#define min(a,b) a>b?b:a
int comparearry(const void *a, const void * b)
{
    int *aa = (int *)a;
    int *bb = (int *)b;
    return *bb - *aa;
}

int minDominoRotations(int* A, int ASize, int* B, int BSize){

int map[7] = {0};
for(int i = 0 ;i < ASize ;i++)
{
    map[A[i]]++;
    map[B[i]]++;
}

int value = 0;
int pos = 0;
for(int i = 0 ; i < 7 ;i++) {
     if(map[i] > value)
     {
         value = map[i];
         pos = i;
     }
}
printf("%d",pos);
int cnt = 0;
int ret = 0;
for(int i = 0; i <ASize; i++)
{
    if(A[i] != pos)
    {
        if(B[i] == pos)
        {
            cnt++;
        }
        else
        {
            ret = -1;
            break;
        }
    }
}
int cnt1 = 0;
for(int i = 0; i <ASize; i++)
{
    if(B[i] != pos)
    {
        if(A[i] == pos)
        {
            cnt1++;
        }
        else
        {
            ret = -1;
            break;
        }
    }
}

if(ret != -1)
{
    ret = min(cnt,cnt1);
}

return ret;


}
```