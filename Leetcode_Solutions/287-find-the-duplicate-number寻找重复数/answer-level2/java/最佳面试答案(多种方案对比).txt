#### 哈希判重解法
```java
// 哈希判重
// 时间复杂度是 O(n)，小于 O(n^2)
// 空间复杂度是 O(n)，大于 O(1)，不符合题目要求
public int findDuplicate(int[] nums) {
    Set<Integer> set = new HashSet<>();
    for (int num : nums) {
        if (set.contains(num)) return num;
        set.add(num);
    }
    return -1;
}
```

#### 普通排序
```java
// 排序
// 时间复杂度是 O(nlogn)，小于 O(n^2)
// 空间复杂度是 O(1)，符合要求
// 但是我们对原数组 nums 进行了更改，所以不符合题目的要求
public int findDuplicate(int[] nums) {
    Arrays.sort(nums);

    for (int i = 1; i < nums.length; i++) {
        if (nums[i] == nums[i - 1]) return nums[i];
    }

    return -1;
}
```

#### 桶排序
```java
// 桶排序
// 时间复杂度是 O(n)，小于 O(n^2)
// 空间复杂度是 O(n)，大于 O(1)，不符合要求
public int findDuplicate(int[] nums) {
    int[] buckets = new int[nums.length];

    for (int num : nums) {
        buckets[num - 1]++;
        if (buckets[num - 1] > 1) return num;
    }

    return -1;
}
```

#### 二分查找
```java
// 二分查找，例子：
/*
    以 [1, 2, 2, 3, 4, 5, 6, 7] 为例，一共 8 个数，n + 1 = 8，n = 7，根据题目意思，每个数都在 1 和 7 之间。

    例如：区间 [1, 7] 的中位数是 4，遍历整个数组，统计小于等于 4 的整数的个数，至多应该为 4 个。
    换句话说，整个数组里小于等于 4 的整数的个数如果严格大于 4 个，就说明重复的数存在于区间[1, 4]，
    它的反面是：重复的数存在于区间 [5, 7]。
*/

// 时间复杂度是 O(nlogn)，小于 O(n^2)
// 空间复杂度是 O(n)，大于 O(1)，符合要求
public int findDuplicate(int[] nums) {
    int left = 1;
    int right = nums.length - 1;
    while (left < right) {
        // 计算出区间 [left, right] 的中位数
        int mid = (right + left) >> 1;

        // 统计数组中小于等于中位数的个数
        int cnt = 0;
        for (int num : nums) {
            if (num <= mid) cnt++; 
        }

        // 按道理，正常情况下，小于等于中位数的个数应该是等于中位数的
        // 但是，如果小于等于中位数的个数大于中位数的话，那么重复的数字肯定在中位数的左边
        if (cnt > mid) {
            right = mid;
        } else { // 否则，重复的数字在右边
            left = mid + 1;
        }   
    }

    // 返回重复的数字
    return left;
}
```