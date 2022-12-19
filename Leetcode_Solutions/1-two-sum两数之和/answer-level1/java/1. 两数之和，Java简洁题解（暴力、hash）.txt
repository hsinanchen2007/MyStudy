# 审题
1. 都是整数，有可能有复数
2. 返回数组下标，下标不相同
3. 列表无序

# 思路
1. 暴力：两层循环求解
2. hash表：key为目标数与当前数之差
3. 双指针：夹逼找到是否有目标数

# 反馈：
1. 国际站有(log n)方法，一个数据排序双指针找，单独复制出来的数组用于找回下标

# 代码实现
1. 暴力法
2. hash方式
3. （不可用）双指针，除非列表有序

## 1.暴力法

```java
/**
    * 暴力法
    *
    * 执行用时 : 105 ms, 在所有 Java 提交中击败了 5.10% 的用户
    * 内存消耗 : 39.3 MB, 在所有 Java 提交中击败了 5.10% 的用户
    *
    * @param nums
    * @param target
    * @return
    */
private int[] directlySolution(int[] nums, int target) {
    if (nums == null || nums.length <= 1) {
        return null;
    }
    for (int i = 0; i < nums.length; i++) {
        for (int j = i + 1; j < nums.length; j++) {
            if (nums[i] + nums[j] == target) {
                return new int[] { i, j };
            }
        }
    }
    return null;
}
```

## 2.hash方式

```java
/**
    * hash方式
    *
    * 执行用时 : 2 ms, 在所有 Java 提交中击败了 99.50% 的用户
    * 内存消耗 : 41.5 MB, 在所有 Java 提交中击败了 5.10% 的用户
    *
    * @param nums
    * @param target
    * @return
    */
private int[] hashSolution(int[] nums, int target) {
    if (nums == null || nums.length <= 1) {
        return null;
    }
    Map<Integer, Integer> map = new HashMap<>(nums.length);
    for (int i = 0; i < nums.length; i++) {
        int v = target - nums[i];
        Integer exist = map.get(v);
        if (exist != null) {
            return new int[] { exist, i };
        }
        map.put(nums[i], i);
    }

    return null;
}
```

## 3.（不可用）双指针，除非列表有序

```java
private int[] squeezeSolution(int[] nums, int target) {
    if (nums == null || nums.length <= 1) {
        return null;
    }

    for (int i = 0, j = nums.length - 1; i < j;) {
        int sum = nums[i] + nums[j];
        if (sum == target) {
            return new int[] { i, j };
        }
        if (sum > target) {
            j--;
        } else {
            i++;
        }
    }
    return null;
}
```