### 解题思路
考虑问题要周全，分成三个数组，每个数组都不是空的。

### 代码

```c
bool canThreePartsEqualSum(int* A, int ASize){
    int i,j;
    int flag1=0,flag2=0;
    int sum=0;
    int temp=0;
    for(i=0;i<ASize;i++){
        sum+=A[i];
    }
    if(sum%3!=0){
        return false;
    }
    i=1;
    temp=A[0];
    while(i<=ASize-1){
        if(temp==sum/3){
            flag1=1;
            break;
        }
        temp+=A[i++];
    }
    temp=A[ASize-1];
    j=ASize-2;
    while(j>=0){
        if(temp==sum/3){
            flag2=1;
            break;
        }
        temp+=A[j--];
    }
    if(flag1&&flag2&&i<=j){
        return true;
    }
    return false;

}


```