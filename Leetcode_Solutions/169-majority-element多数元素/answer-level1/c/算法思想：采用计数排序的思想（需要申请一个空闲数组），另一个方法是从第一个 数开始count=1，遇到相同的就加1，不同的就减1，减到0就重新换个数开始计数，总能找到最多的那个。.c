### 解题思路
此处撰写解题思路

### 代码

```c
int majorityElement(int* nums, int numsSize){
//  假设第一个是多数元素
    int key = nums[0];
    int count = 0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]==key) count++;
        else count--;
        if(count<=0) key=nums[i+1];
    }
    return key;
}
```