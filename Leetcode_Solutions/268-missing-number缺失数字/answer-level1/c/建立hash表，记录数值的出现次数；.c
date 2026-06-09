### 解题思路
建立一个以数组的序列的值作为下标的hash表，记录数值的出现次数；最后遍历一遍hash表确认次数为0的，就是缺失的数字


### 代码

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define MAX 10000

int missingNumber(int* nums, int numsSize){
    if((NULL == nums) || (0 == numsSize)){
        printf("error input.");
        return -1;
    }
    int hash[numsSize + 1];
    memset((void *)hash, 0, (numsSize + 1)*sizeof(int));
    
    for(int i = 0; i < numsSize; i++){
        hash[nums[i]]++; //使用数字作为下标，通过hash表记录数字出现的次数，即 如果出现 将被记录为1；否则没有出现就是 0；
    }

    for(int i = 0; i < numsSize + 1; i++){
        if(0 == hash[i]){
            return i;
        }
    }

    printf("Not find.\n");
    return -1;

}
```