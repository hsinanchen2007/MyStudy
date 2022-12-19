```C
double* sampleStats(int* count, int countSize, int* returnSize){
    double minv=INT_MAX,maxv=INT_MIN,sum=0,maxcnt=0,most=0,mid,mid1,mid2;
    int n=countSize,tmp=0,cnt=0;
    for(int i=0;i<n;i++){
        if(count[i]) minv=fmin(i,minv);
        if(count[i]) maxv=fmax(i,maxv);
        sum+=count[i]*i;
        cnt+=count[i];
        if(maxcnt<count[i]){
            maxcnt=count[i];most=i;
        }
    }
    for(int i=0;i<n;i++){
        if(tmp<cnt/2&&tmp+count[i]>=cnt/2) mid1=i;
        if(tmp<cnt/2+1&&tmp+count[i]>=cnt/2+1) mid2=i;
        tmp+=count[i];
    }
    mid=n%2?mid2:(mid1+mid2)/2;
    *returnSize=5;
    double* ans=(double*)calloc(*returnSize, sizeof(double));
    ans[0]=minv,ans[1]=maxv,ans[2]=sum/cnt,ans[3]=mid,ans[4]=most;
    return ans;
}
```
