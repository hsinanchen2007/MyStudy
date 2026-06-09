### 解题思路
此处撰写解题思路

### 代码

```c
int minDominoRotations(int* A, int ASize, int* B, int BSize){
    //C语言法：哈希表的思想
    int hash[7]={0};
    for(int i=0;i<ASize;i++)
    {
        hash[A[i]]++;
        hash[B[i]]++;
    }

    int max=INT_MIN,target=0;
    for(int i=1;i<=6;i++){
        if(hash[i]>max)
        {
            max=hash[i];  target=i;  //记录是哪一个数字
        }
    }

    if(max<ASize)
        return -1;
    //开始翻转：1.假设翻转A数组可以实现  2.假设翻转B数组可以实现
    int cnt1=0, cnt2=0;
    for(int i=0;i<ASize;i++)
    {
        if(A[i]==target)  continue;
        if(B[i]!=target)  return -1;
        else   cnt1++;
    }

    for(int i=0;i<BSize;i++)
    {
        if(B[i]==target) continue;
        if(A[i]!=target) return -1;
        else cnt2++;
    }
    return cnt1>cnt2? cnt2:cnt1;
}
```