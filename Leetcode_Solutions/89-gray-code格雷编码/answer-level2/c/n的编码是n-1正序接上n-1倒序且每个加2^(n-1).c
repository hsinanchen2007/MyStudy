### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 //n的编码是n-1正序接上n-1倒序且每个加2^(n-1)
int* grayCode(int n, int* returnSize)
{
    int l=pow(2,n);
    int*gray=(int*)malloc(sizeof(long int)*(l));
    gray[0]=0;
    //if(n==0)
    //{
    //    free(gray);
    //    returnSize=1;
    //    return  gray;
    //}
    for(int i=1;i<=n;i++)
    {
        int temp=1;
        int lo=pow(2,(i-1));
        int lon=pow(2,(i));
        for(int j=lo;j<lon;j++)
        {
            if(lo-temp>=0)
            { 
                 gray[j]=gray[lo-temp]+lo;
                 temp++;
            }
          
        }
    }
    *returnSize=l;
    //free(gray);
    return gray;
}


```