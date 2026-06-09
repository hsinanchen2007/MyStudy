### 解题思路
![image.png](https://pic.leetcode-cn.com/1380a830ed581e6b32860238bdf4fe274ebef4e2660baaab1abaaa3ab5d4a92a-image.png)
窗口长度由短至长，符合要求直接输出窗口长度；
一开始搞了三重循环超时了，优化了一下，搞了一个数组存每次求和的数值，以备窗口变长时使用，这样就不用再来一重循环求窗口内的和了。

### 代码

```c
int minSubArrayLen(int s, int* nums, int numsSize){
    if(numsSize == 0) {
        return 0;
    }
    int i, j, k;
    int sum = 0;
    int* temp = (int*)malloc(sizeof(int) * numsSize);
    memset(temp, 0, sizeof(int) * numsSize);

    for(i = 1; i < numsSize + 1; i++) {
        for(j = 0; j < numsSize + 1 - i; j++) {
            sum = temp[j] + nums[j + i - 1];
            temp[j] = sum;
            if(sum >= s) {
                return i;
            }
        }
    }
    return 0;
}
```