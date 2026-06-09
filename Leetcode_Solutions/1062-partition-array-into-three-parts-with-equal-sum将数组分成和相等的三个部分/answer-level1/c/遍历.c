### 解题思路
总和是否能被三整除
能否找到和为总和1/3的两个部分且数组元素未全部被遍历
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