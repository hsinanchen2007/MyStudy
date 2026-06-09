### 解题思路
此处撰写解题思路

### 代码

```c
int findNumbers(int* nums, int numsSize){
    int count = 0;
    for(int i=0;i<numsSize;i++){
	char str[6];
        sprintf(str,"%d",nums[i]);
        if(strlen(str)% 2 == 0){
            count += 1;
        }
    }
    return count;
}
```