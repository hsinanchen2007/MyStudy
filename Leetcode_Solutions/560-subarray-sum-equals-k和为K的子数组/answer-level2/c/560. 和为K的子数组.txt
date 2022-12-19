### 解题思路
暴力解法
![image.png](https://pic.leetcode-cn.com/d7b8caba96a0c6276b79ed6b490850b35b1c278ab339c50174bfd95fb1cbe2da-image.png)

### 代码

```c
int subarraySum(int* nums, int numsSize, int k){
    if (nums == NULL || numsSize < 1) return 0;

    int *sum = (int *)malloc(sizeof(int) * (numsSize + 1));
    if (sum == NULL) return 0;
    sum[0] = 0;
    for (int i=1; i<numsSize + 1; i++) {
        sum[i] = sum[i-1] + nums[i-1];
    }

    int ret = 0;
    for (int i=0; i<numsSize; i++) {
        for (int j=i+1; j<=numsSize; j++) {
            if (sum[j] - sum[i] == k) {
                ret++;
            }
        }
    }
    free(sum);
    return ret;
}

/* test case 
[1,1,1]
2

[1]
1

[1]
0

[1]
2

[]
0

[]
1

[1,2,3,4,5]
4

[1,2,3,4,5]
3

[1,-1,2,-2,4,-4,5,6,-6,-5]
0

*/
```