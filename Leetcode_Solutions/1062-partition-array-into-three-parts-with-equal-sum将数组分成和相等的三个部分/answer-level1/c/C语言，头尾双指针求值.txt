### 解题思路
数组和三分；
如果数组和不能被3整除，直接返回false；
双指针分别求头部和、尾部和；
头部指针范围：(0,ASize-2);
尾部指针范围：(ASize-1,1);
先求头部和，满足SUM/3的条件之后再求尾部和；
尾部和=SUM/3的同时检查j>i+1是否成立；
成立则返回TRUE；
否则整个循环完成后返回FALSE；

### 代码

```c
bool canThreePartsEqualSum(int* A, int ASize)
{
    int sum=0;
    int presum=0;//切记不要在循环内给变量赋初值。
    int tailsum=0;
    for(int i=0;i<ASize;i++)
        sum+=A[i];
    if(sum%3)
        return false;
    for(int i=0;i<ASize-2;i++)
    {
        
        presum+=A[i];
        if(presum==(sum/3))
        {
            for(int j=ASize-1;j>1;j--)
            {
                
                tailsum+=A[j];
                if((j>i+1)&&tailsum==(sum/3))
                    return true;
            }
        }
    }
    return false;

}
```