# 审题
1. 非负整数
2. n>=2

# 思路
1. 暴力：两层循环，找出最大的
2. 左右夹逼，移动矮的指针

# 反馈
1. 中文站题解
2. 国际站题解

# 代码实现
1. 暴力法求解
2. 左右夹逼计算，移动矮的指针
3. 左右夹逼计算快速版
4. 左右夹逼计算急速版，国际站大佬提供

## 1.暴力法求解

```java
/**
    * 暴力法求解
    * i,j两层循环要写熟练
    *
    * 执行用时 : 481 ms, 在所有 Java 提交中击败了 7.41% 的用户
    * 内存消耗 : 41.5 MB, 在所有 Java 提交中击败了 5.05% 的用户
    *
    * @param height
    * @return
    */
private int directlySolution(int[] height) {
    int max = 0;
    for (int i=0; i<height.length; i++) {
        for (int j=i+1; j<height.length; j++) {
            max = Math.max(max, (j - i) * Math.min(height[i], height[j]));
        }
    }
    return max;
}
```

## 2.左右夹逼计算，移动矮的指针

```java
/**
    * 左右夹逼计算，移动矮的指针
    *
    * 执行用时 : 4 ms, 在所有 Java 提交中击败了 75.11% 的用户（第一次貌似会慢一些）
    * 内存消耗 : 41.2 MB, 在所有 Java 提交中击败了 5.05% 的用户
    * @param height
    * @return
    */
private int squeezeSolution(int[] height) {
    int max = 0;
    int head = 0;
    int tail = height.length - 1;
    while (head < tail) {
        max = Math.max(max, (tail - head) * Math.min(height[head], height[tail]));
        if (height[head] < height[tail]) {
            head++;
        } else {
            tail--;
        }
    }
    return max;
}
```

## 3.左右夹逼计算快速版

```java
/**
    * 左右夹逼计算快速版
    * @param height
    * @return
    */
private int squeezeFastSolution(int[] height) {
    int maxArea = 0;
    int head = 0;
    int tail = height.length - 1;
    while (head < tail) {
        int hh = height[head];
        int th = height[tail];
        int thisArea;
        // 提速关键1，减少逻辑判断次数
        if (hh < th) {
            thisArea = (tail - head) * hh;
            head++;
        } else {
            thisArea = (tail - head) * th;
            tail--;
        }
        // 提速关键2，减少赋值次数
        if (thisArea > maxArea) {
            maxArea = thisArea;
        }
    }
    return maxArea;
}
```

## 4.左右夹逼计算急速版，国际站大佬提供

```java
/**
    * 左右夹逼计算急速版，国际站大佬提供
    * @param height
    * @return
    */
private int squeezeZoomSolution(int[] height) {
    int water = 0;
    int i = 0, j = height.length - 1;
    while (i < j) {
        int h = Math.min(height[i], height[j]);
        water = Math.max(water, h * (j - i));
        // 提速关键，找到下一个更长的
        while (height[i] <= h && i < j) i++;
        while (height[j] <= h && i < j) j--;
    }
    return water;
}
```