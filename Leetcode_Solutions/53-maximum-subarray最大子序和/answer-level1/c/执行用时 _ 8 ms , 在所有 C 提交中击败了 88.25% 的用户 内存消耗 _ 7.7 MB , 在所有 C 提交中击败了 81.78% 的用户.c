
#define MAX(a,b) ((a)>(b)?(a):(b))

int maxSubArray(int* nums, int numsSize){


    int *p = (int*)malloc(sizeof(int)*numsSize);
    p[0] = nums[0];
    for(int i =1; i<numsSize; i++){
        p[i] = MAX(p[i-1]+nums[i], nums[i]);
    }
    int max = INT_MIN;//////!!!!!!!!!!!!!!!!!!!定义最小int
    for(int i=0; i<numsSize; i++)
    {
        //printf("p[%d]:%d\n", i, p[i]);
        max = MAX(max, p[i]);
    }
    return max;   

}