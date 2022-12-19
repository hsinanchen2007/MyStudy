int max(int a, int b){
    return (a>b)?a:b;
}


int rob(int* nums, int numsSize){
    int currmax = 0;
    int premax = 0;
    int temp;
    
    for(int i=0; i<numsSize; i++){
        temp = currmax;
        currmax = max(nums[i]+premax, currmax);
        premax = temp;
    }

    return currmax;

}