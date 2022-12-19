```

int cmp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
int findRadius(int* houses, int housesSize, int* heaters, int heatersSize){
    qsort(houses,housesSize,sizeof(int),cmp);
    qsort(heaters,heatersSize,sizeof(int),cmp);
    int i,j=0,count=0,sum=0,nums[housesSize];
    for(i=0;i<housesSize;i++)
    {
        count=abs(houses[i]-heaters[0]);
        for(;j<heatersSize;j++)
        {
            if(abs(houses[i]-heaters[j])>count)
                break;
            if(count>abs(houses[i]-heaters[j]))
                count=abs(houses[i]-heaters[j]);
        }
        nums[i]=count;
        j--;
    }
    qsort(nums,housesSize,sizeof(int),cmp);
    return nums[housesSize-1];
}            

```