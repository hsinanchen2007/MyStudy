剑指里做过，记录cnt
```
int majorityElement(int* nums, int numsSize){
    int d = nums[0], cnt = 1;;
    for(int i=1 ; i<numsSize ; i++){
        int tmp = nums[i];
        if(tmp == d) cnt++;
        else cnt--;
        if(cnt==0) {
            d = tmp;
            cnt = 1;
        }
    }
    return d;
}
```
