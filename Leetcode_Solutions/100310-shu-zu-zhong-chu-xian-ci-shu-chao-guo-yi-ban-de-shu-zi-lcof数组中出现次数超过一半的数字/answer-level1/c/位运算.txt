### 解题思路
如果这个数超过一半的话，那么这个数位数为1的位一定也超过一半。
比如[1, 2, 3, 2, 2, 2, 5, 4, 2]，写成二进制为：
                                            1：001
                                            2：0**1**0
                                            3：0**1**1
                                            2：0**1**0
                                            2：0**1**0
                                            2：0**1**0
                                            5：101
                                            4：100
                                            2：0**1**0
                                            ........↑
.....6个1
即使去掉3中的那个1，也有5个，并且最少也有5个，因为根据题意2就不少于5个。


### 代码

```c
int majorityElement(int* nums, int numsSize){
    int ans = 0;
    int i, j;

    for (i = 0; i < 32; i++) {
        int p = UINT32_C(1) << i;
        int count = 0;
        for (j = 0; j < numsSize; j++) {
            if (nums[j] & p) {
                count++;
            }
        }
        if (count > (numsSize / 2)) {
            ans ^= p;
        }
    }

    return ans;
}
```