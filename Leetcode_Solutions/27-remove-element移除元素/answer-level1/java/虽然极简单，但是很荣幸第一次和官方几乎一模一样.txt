![image.png](https://pic.leetcode-cn.com/1e037fb349e02d726c99e806749c2af8a4134cc1d5f91895f66ab3db6512cb01-image.png)

利用双指针，利用覆盖代替交换

```
    int N = nums.length;
    int i = 0;
    for(int j = 0; j < N; j++) {
        if(nums[j] != val) {
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
```
