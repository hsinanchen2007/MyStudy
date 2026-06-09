### 解题思路
0 ^ 4 = 4  
4 ^ 4 = 0  
数列中的数是0~n少一个，数组下标是0 ~ n - 1，补一个n就是下标0~n了，数列元素和数组下标相互异或，异或具有结合律，故最后悔剩下缺失的那个下标(元素)  
如[0, 1, 3, 4]和下标0, 1, 2, 3, 4(补充的第n个下标)

### 代码

```c
int missingNumber(int* nums, int numsSize){
    //异或
    int res = numsSize;
    for(int i = 0; i < numsSize; i++){
        res ^= i ^ nums[i];
    }
    return res;
}


```