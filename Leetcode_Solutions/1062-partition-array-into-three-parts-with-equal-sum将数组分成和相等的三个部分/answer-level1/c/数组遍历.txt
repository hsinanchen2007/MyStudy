### 解题思路

给你一个整数数组 A，只有可以将其划分为三个和相等的非空部分时才返回 true，否则返回 false。
形式上，如果可以找出索引 i+1 < j 且满足 (A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1] + ... + A[A.length - 1]) 就可以将数组三等分。

bool canThreePartsEqualSum(int* A, int ASize){
    int sum=0;
    int i;
    for(i=0;i<ASize;i++)
        sum+=A[i];
    if(sum%3!=0) return false;
    int sum1=0;
    int count=0;
    for(i=0;i<ASize;i++)
    {   
        sum1+=A[i];
        if(sum1==(sum/3)){
            sum1=0;
            count++;
            if(count==2&&i<ASize-1) return true;
        }
    }
    return false;
}

### 代码

```c
bool canThreePartsEqualSum(int* A, int ASize){
    int sum=0;
    int i;
    for(i=0;i<ASize;i++)
        sum+=A[i];
    if(sum%3!=0) return false;
    int sum1=0;
    int count=0;
    for(i=0;i<ASize;i++)
    {   
        sum1+=A[i];
        if(sum1==(sum/3)){
            sum1=0;
            count++;
            if(count==2&&i<ASize-1) return true;
        }
    }
    return false;
}
```