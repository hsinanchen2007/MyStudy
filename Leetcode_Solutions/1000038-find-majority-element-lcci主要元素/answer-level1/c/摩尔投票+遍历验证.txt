### 解题思路
此处撰写解题思路

### 代码

```c
int majorityElement(int* nums, int numsSize){
    int cnt=1, i, len;
    int mor = nums[0];
    for (i=1; i<numsSize; i++){
        if (nums[i]==mor)
         cnt++;
        else {
            cnt--;
        }
        if (cnt==0) {
            mor = nums[i];
            cnt = 1;
        }
    }
    cnt = 0;
    len = numsSize/2 + 1;
    for (i=0; i<numsSize; i++){
        if (nums[i]==mor) {
            cnt++;
        }
    }
    if (cnt>=len) return mor;
    else return -1;
}
```