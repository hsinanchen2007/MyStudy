### 解题思路
![image.png](https://pic.leetcode-cn.com/5ee56388dcd7985e774512f604dbe732b1b8baa6c5e94407a42abe3f1a3bc8fa-image.png)
平淡无奇的哈希表

### 代码

```c
int missingNumber(int* nums, int numsSize){
    int* hash = (int*)malloc(sizeof(int) * (numsSize + 1));
    int i;
    for(i = 0; i < numsSize + 1; i++) {
        hash[i] = 0;
    }
    for(i = 0; i < numsSize; i++) {
        hash[nums[i]] = 1;
    }
    for(i = 0; i < numsSize + 1; i++) {
        if(hash[i] == 0) {
            break;
        }
    }
    return i;
}
```