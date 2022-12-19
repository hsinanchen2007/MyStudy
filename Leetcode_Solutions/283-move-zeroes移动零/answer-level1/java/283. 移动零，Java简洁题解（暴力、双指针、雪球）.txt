# 审题
1. 结果是原数组
2. 数组末尾都是0就行
3. 其他元素是`相对顺序`
4. 可能有复数

# 思路
1. 暴力：遇到0就删除后放到数组最后一位
2. 双指针：指针1记录最近非0的位置，指针2往后找非0元素前移

# 反馈
1. 中文站解题
2. 国际站解题

# 代码实现
1. 暴力：遇到0就删除后放到数组最后一位
2. 双指针：指针1记录最近非0的位置，指针2往后找非0元素前移
3. 双指针：指针1记录最近非0的位置，指针2往后找非0元素前移，最后清0
4. 额外空间：在申请一个空间存非零，最后再导回来 中文站提供
5. 滚雪球：记录0步长为雪球，遇非0交换雪球的第一个 国际站提供

## 1.暴力：遇到0就删除后放到数组最后一位，直到后面都是0

```java
/**
    * 暴力：遇到0就删除后放到数组最后一位，直到后面都是0
    *
    * 执行用时 : 14 ms, 在所有 Java 提交中击败了 12.73% 的用户
    * 内存消耗 : 42.1 MB, 在所有 Java 提交中击败了 5.01% 的用户
    * @param nums
    */
private void directlySolution(int[] nums) {
    // 1 check bound
    if (nums == null || nums.length <= 1) {
        return;
    }

    // 2 move
    for (int i = 0; i < nums.length;) {
        if (nums[i] != 0) {
            i++;
            continue;
        }

        boolean isZeroEnd = true;
        int del = nums[i];
        for (int j = i+1; j < nums.length; j++) {
            nums[j-1] = nums[j];
            if (nums[j] != 0) {
                isZeroEnd = false;
            }
        }
        nums[nums.length - 1] = del;
        if (isZeroEnd) {
            break;
        }
    }
}
```

## 2.双指针：固定非0元素

```java
/**
    * 双指针：固定非0元素
    *
    * 执行用时 : 0 ms, 在所有 Java 提交中击败了 100.00% 的用户
    * 内存消耗 : 42.2 MB, 在所有 Java 提交中击败了 5.01% 的用户
    * @param nums
    */
private void fixedSolution(int[] nums) {
    // 1 check bound
    if (nums == null || nums.length <= 1) {
        return;
    }
    // 2 move
    for (int i = 0, j = 0; j < nums.length; j++) {
        if (nums[j] != 0) {
            if (i != j) {
                nums[i] = nums[j];
                nums[j] = 0;
            }
            i++;
        }
    }
}

// 简洁版
private void fixedCleanSolution(int[] nums) {
    for (int i = 0, j = 0; j < nums.length; j++) {
        if (nums[j] != 0) {
            int tmp = nums[j];
            nums[j] = nums[i];
            nums[i++] = tmp;
        }
    }
}
```

## 3.固定非0，最后清0数组

```java
private void fixedLazySolution(int[] nums) {
    // 1 check bound
    if (nums == null || nums.length <= 1) {
        return;
    }
    // 2 move
    int fixed = 0;
    for (int j = 0; j < nums.length; j++) {
        if (nums[j] != 0) {
            nums[fixed] = nums[j];
            fixed++;
        }
    }
    for (; fixed < nums.length; fixed++) {
        nums[fixed] = 0;
    }
}
```

## 4.使用额外空间

```java
private void extraSolution(int[] nums) {
    // 1 check bound
    if (nums == null || nums.length <= 1) {
        return;
    }
    // 2 move
    int[] extra = new int[nums.length];
    for (int i = 0, j = 0; i < nums.length; i++) {
        if (nums[i] != 0) {
            extra[j] = nums[i];
            j++;
        }
    }
    System.arraycopy(extra, 0, nums, 0, nums.length);
}
```

## 5.滚雪球

```java
private void snowBallSolution(int[] nums) {
    int ballSize = 0;
    for (int i = 0; i < nums.length; i++) {
        if (nums[i] == 0) {
            ballSize++;
        } else if (ballSize > 0) {
            nums[i - ballSize] = nums[i];
            nums[i] = 0;
        }
    }
}
```