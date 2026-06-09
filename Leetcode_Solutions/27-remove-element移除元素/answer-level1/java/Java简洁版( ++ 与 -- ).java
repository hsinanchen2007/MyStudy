1. 原理不讲了，官方解释很详细
2. 主要是 ++、-- 的用法


**简洁版 - 1**
```java
class Solution {
    public int removeElement(int[] nums, int val) {
        int i = 0;
        for (int num : nums) {
            if (num != val)
                nums[i++] = num;
        }
        return i;
    }
}
```
——————————————————————————————————————————————————

**简洁版 - 2** *(若有疑惑，请往下看)*
```java
class Solution {
    public int removeElement(int[] nums, int val) {
        int len = nums.length;
        for (int i = 0; i < len; i++) {
            if (nums[i] == val)
                nums[i--] = nums[--len];
        }
        return len;
    }
}
```
——————————————————————————————————————————————————

##### 双指针 - *移除元素较少*

- 官方版
```java
class Solution {
    public int removeElement(int[] nums, int val) {
        int i = 0;
        int n = nums.length;
        while (i < n) {
            if (nums[i] == val) {
                // 思考第一点
                nums[i] = nums[n - 1];
                n--;
            } else {
                // 思考第二点
                i++;
            }
        }
        return n;
    }
    // 思考
    // 1. n-1 和 n-- 能否合并？
    // 2. i++ 和 if(nums[i] == val) 能否合并？
}
```

——————————————————————————

- while (合并版)
```java
class Solution {
    public int removeElement(int[] nums, int val) {
        int i = 0;
        int len = nums.length;
        while (i < len) {
            if (nums[i++] == val)
                nums[--i] = nums[--len]
        }
        return len;
    }
    // 思考：
    // 1. 变量i是否有操作的空间
}
```

- for (合并版)
```java
class Solution {
    public int removeElement(int[] nums, int val) {
        int len = nums.length;
        for (int i = 0; i < len; i++) {
            if (nums[i] == val)
                nums[i--] = nums[--len];
        }
        return len;
    }
}
```
