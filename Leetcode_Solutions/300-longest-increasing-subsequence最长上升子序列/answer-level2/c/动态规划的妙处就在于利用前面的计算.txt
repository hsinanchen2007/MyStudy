### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/0d6a62f5b0632e8002b2ca3829ee5a46b328ec504ebbbff31d50a34741e7320c-image.png)

### 代码

```c
int lengthOfLIS(int* nums, int numsSize){
    if (numsSize == 0) {
        return 0;
    }
    int *len = calloc(numsSize, sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        len[i] = 1;
    }

    for (int i = 1; i < numsSize; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j] && len[i] < len[j] + 1) {
                len[i] = len[j] + 1;
            }
        }
    }

    int res = 0;
    for (int i = 0; i < numsSize; i++) {
        if (len[i] > res) {
            res = len[i];
        }
    }

    return res;
}
```