### 解题思路
一般思路

### 代码

```c
int removeDuplicates(int* nums, int numsSize){
    if(numsSize==0)//长度为0的情况
        return 0;
    int len=1;
    int a=nums[0];
    int j=1;
    for(int i=1;i<numsSize;i++){
        if(nums[i]==a){//如果与前面的元素相同，进入下一次循环
            continue;
        }
        else{//否则，a和nums[j]记录下当前的值，长度+1
            a=nums[i];
            nums[j++]=a;
            len++;
        }
    }
    return len;

}
```