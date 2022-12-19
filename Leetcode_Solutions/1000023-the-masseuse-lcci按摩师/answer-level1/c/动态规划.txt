### 解题思路
此处撰写解题思路

### 代码

```c
int massage(int* nums, int numsSize){
    if (!nums || numsSize < 1) {
        return 0;
    }

    int a = 0;
    int b = 0;
    for (int i = 0; i < numsSize; i++) {
        int c = b > (a + nums[i]) ? b : (a + nums[i]);
        a = b;
        b = c;
    }
    return b;
}
```