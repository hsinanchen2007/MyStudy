### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/01e5ecf72f69d3306e30e45d9e0b37192dab0c3a467ee2d48859889c5e064307-image.png)

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize){
    int* data_buf=(int*)malloc(sizeof(int)*(numsSize+1));
    memset(data_buf,'\0',sizeof(int)*(numsSize+1));

    for(int i=0;i<numsSize;i++){
        for(int j=0;j<numsSize;j++){
            if(nums[j]<nums[i])
                data_buf[i]++;
        }
    }

    data_buf[numsSize]='\0';
    *returnSize=numsSize;

    return data_buf;
}
```