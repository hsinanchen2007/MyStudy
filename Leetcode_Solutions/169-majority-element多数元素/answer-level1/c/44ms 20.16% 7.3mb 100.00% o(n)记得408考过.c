### 解题思路
此处撰写解题思路

### 代码

```c
int majorityElement(int* nums, int numsSize){
    int temp=1,i=1,k=nums[0];
    while(i<numsSize){
        if(nums[i]==k){
            temp++;
        }else{
            temp--;
        }
        if(temp==0){
            k=nums[i];
            temp=1;
        }
        i++;
    }
    return k;
}
```