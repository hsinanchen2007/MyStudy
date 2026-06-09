```
//本来数组里就分为两派，众数和非众数

//如果以众数为candidate那么自然会抵消一半
//当count为0时，我们仍然可以按剩下的分辨出谁是众数

//如果以非众数为candidate,碰到众数当然会抵消了
//碰到了其他非众数，那就做族内消耗，哈哈，削了之后，更方便众数胜出了
int majorityElement(int* nums, int numsSize){
    int i;
    int candidate=nums[0];
    int count=1;
    for(i=1;i<numsSize;i++){
        count=nums[i]==candidate?count+1:count-1;
        if(count==0&&i<numsSize-1){
            candidate=nums[i+1];
            count=0;
        }
    }
    return candidate;
}
```
