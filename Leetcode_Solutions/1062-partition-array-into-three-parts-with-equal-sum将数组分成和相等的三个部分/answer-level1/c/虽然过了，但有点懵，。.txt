bool canThreePartsEqualSum(int* A, int ASize){
    int sum=0;
    for(int i=0;i<ASize;i++)
    {
        sum+=A[i];
    }
    if(sum/3.0 != sum/3){
        return false;
    }
    int tag=sum/3;
    int t=0,num=0;
    for(int i=0;i<ASize;i++)
    {
        t+=A[i];
        if(t==tag){
            t=0;
            num++;
        }
    }
    if(num>=3)return true;//为什么这里大于3就可以了呢
    else return false;
}