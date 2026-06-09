### 解题思路
1.计算数组总和能否被3整除。
2.遍历的时候累加判断等不等于sum/3,然后累加置零，标志位加一；
3.判断分成了几部分。大于等于三部分返回true（大于三部分的情况只有总和为0，分部有多处为0），否则返回false


### 代码

```c
bool canThreePartsEqualSum(int* A, int ASize){
    if(ASize<3)
        return false;
    else{
    int sum=0,i=0,j=0,flag=0;
    for(i=0;i<ASize;i++)
        sum+=A[i];
    if(sum%3!=0)
        return false;
    else
        {
            sum=sum/3;
            for(i=0;i<ASize;i++)
            {
                j=j+A[i];
                if(j==sum)
                {
                    j=0;
                    flag++;
                }
            }
            if(flag>=3)
                return true;
            else
                return false;
        }
    }
}
```