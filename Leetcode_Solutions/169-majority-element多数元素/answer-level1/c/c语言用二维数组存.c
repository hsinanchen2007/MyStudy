
```
int majorityElement(int* nums, int numsSize){
    int i,k;
    int aban[100][2] = {0};
    for(int j=0;j<numsSize;j++)
    {

        i = 0;
        k = 0;
        while(aban[i][0]!='\0')
        {
            if(aban[i][0] == nums[j])
            {
                 aban[i][1]=aban[i][1]+1;
                 k = 1;
                 if(aban[i][1]>(numsSize/2))
                 return aban[i][0];
            }
            i++;
        }
        if(k==0)
        {
            aban[i][0]=nums[j];
            aban[i][1]= 1;
            if(aban[i][1]>(numsSize/2))
                 return aban[i][0];
        }
    }
    return 0;
    }
```