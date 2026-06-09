### 解题思路
只需要遍历一次数组即可，对于每个数，
判断是否在哈希表中出现过，如果没有，
设置hash[nums[i]] = 1，这表示这个数
已经出现过了，下次如果再遇到它，直接
返回这个数即可。

### 代码

```c


int findRepeatNumber(int* nums, int numsSize){
    int hash[100000] = {0};

    int i;
    for(i = 0;i < numsSize;i++){
        if(hash[nums[i]] == 0){
            hash[nums[i]] = 1;
        }
        else{
            return nums[i];
        }
    }

    return 0;

}


```