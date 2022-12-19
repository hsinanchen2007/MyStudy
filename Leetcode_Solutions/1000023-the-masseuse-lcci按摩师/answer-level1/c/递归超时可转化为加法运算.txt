### 解题思路
# **- 递归（超时）**
1. 当选取第一个数字的时候，那么第二个数字就不能选，从第三个数字开始选相当于计算m(3);
2. 当不选取第一个数字的时候，那么就相当于计算m(2), 也就是从第2个数字开始计算最大值;
3. 比较两种选法那种获得的值大，就选择那种;

### 代码
```c
int massage(int* nums, int numsSize){
    if (numsSize == 0){
        return 0;
    }else if (numsSize == 1){
        return nums[0];
    }else if (numsSize == 2){
        return nums[0] > nums[1] ? nums[0] : nums[1];
    }else if (numsSize == 3){
        return nums[0] + nums[2] > nums[1] ? nums[0] + nums[2] : nums[1];
    }

    int m1 = massage(nums + 2, numsSize - 2) + nums[0];
    int m2 = massage(nums + 1, numsSize - 1);

    if (m1 > m2){
        return m1;
    }else{
        return m2;
    }
}
```

# **- 归纳（这应该叫什么呢。。。）**
1. 递归是从开始选取，我们反向推导，不难得出，如果要计算一个长度为 N 的数组的最大值，转化为计算 m(N-1) 和 nums[N-1] + m(N-2) 并选择其中的最大值。
2. 临界条件: m(1) = nums[0]; m(2) = nums[1] > nums[0] ? nums[1] : nums[0];

### 代码

```c
int massage(int* nums, int numsSize){
    if (numsSize == 0){
        return 0;
    }else if (numsSize == 1){
        return nums[0];
    }else if (numsSize == 2){
        return nums[0] > nums[1] ? nums[0] : nums[1];
    }else if (numsSize == 3){
        return nums[0] + nums[2] > nums[1] ? nums[0] + nums[2] : nums[1];
    }

    int i, best = 0;
    int mi_2 = nums[0];
    int mi_1 = nums[1] > nums[0] ? nums[1] : nums[0];

    for (i=3; i <= numsSize; i++){
        if (mi_1 > nums[i-1] + mi_2){
            best = mi_1;
        }else{
            best = nums[i-1] + mi_2;
        }
        mi_2 = mi_1;
        mi_1 = best;
    }

    return best;
}
```