### 解题思路
![2.jpg](https://pic.leetcode-cn.com/0ff6f96d4230f549fe6c153f2e0caa8787c4c6fa2984a4dedb860af7bf313c6b-2.jpg)

此处撰写解题思路

### 代码

```c
int removeDuplicates(int* nums, int numsSize){
    int temp=nums[0],count=1;                   //nums[0]为新数组第一个元素，temp用于判断是否重复
    if(numsSize==0) return 0;
    for(int i=1;i<numsSize;i++){
        if(temp!=nums[i]){
            temp=nums[count++]=nums[i];         //不同则将当前nums[i]接在“新”数组后面并赋值给temp
        }
    }
    return count;
}
```