
```
#define Begin 0
#define Up 1
#define Down 2
int wiggleMaxLength(int* nums, int numsSize){
    if(numsSize==0)
    return 0;
    int State=Begin,i=1,max=1;
    int maximum,minimum;
    while(i<numsSize)
    {
        switch(State)
        {
            case Begin:
            if(nums[i]==nums[0])//没有摇摆  
            max=1;
            else if(nums[i]>nums[0])//UP
            {
                State=Up;
                maximum=nums[i];
                max++;
            }
            else//Down
            {
                State=Down;
                minimum=nums[i];
                max++;
            }
            break;
            case Up:
            if(nums[i]<maximum)//Down
            {
                State=Down;
                minimum=nums[i];
                max++;
            }
            else{
                maximum=nums[i];
            }
            break;
            case Down:
            if(nums[i]>minimum)//Up
            {
                State=Up;
                maximum=nums[i];
                max++;
            }
            else
            minimum=nums[i];
            break;
        }
        i++;
        
    }
    return max;
}
```
