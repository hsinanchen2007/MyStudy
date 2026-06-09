提供两种做法。
做法一：
```c
int findNumbers(int* nums, int numsSize){
    int i,count=0,digit;
    for(i=0;i<numsSize;i++){
        if (nums[i]==0) continue;
        digit=0;
        while(nums[i]!=0){
            digit++;
            nums[i]=nums[i]/10;
        }
        if(digit%2==0) count++;
    }
    return count;
}
```
做法二：
```c
int findNumbers(int* nums, int numsSize){
    short i,count=0;
    for(i=0;i<numsSize;i++)
        if((nums[i]>=10&&nums[i]<100)||(nums[i]>=1000&&nums[i]<10000)) count++;
    return count;
}