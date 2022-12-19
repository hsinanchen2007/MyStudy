### 解题思路
此处撰写解题思路

### 代码

```c

int singleNumber(int* nums, int numsSize){
    int a=0,i=0;
    while(i<numsSize){
        a=a^nums[i];
        i++;
    }
    return a;
}
```