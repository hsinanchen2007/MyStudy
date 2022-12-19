```
int distributeCandies(int* candies, int candiesSize)
{
    int arr[200001]={0};
    int i,sum,max;
    for(i=0;i<candiesSize;i++)
    {
        arr[100000 + candies[i] ]++;
    }
    for(i=0,sum=0;i<200001;i++)
    {
        if(arr[i]!=0)
            sum++;
    }
    max = candiesSize/2;
    return max > sum ? sum : max;
}
```
