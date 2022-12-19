### 思路一（位运算）：

二进制异或，两位相同为0，不同得1。即两个数相同，异或得0。0和任何数异或得到该数本身。将数组中所有数进行异或，其中出现两次的数抵消为0，剩下的就是出现一次的那个数。

### 代码：

时间复杂度O(n)，空间复杂度O(1)

```java
class Solution {
    public int singleNumber(int[] nums) {
        if (nums.length == 1) {
            return nums[0];
        }
        int res = 0;
        for (int x : nums) {
            res ^= x;
        }
        return res;
    }
}
```

### Result：

Runtime：1ms

Your runtime beats 99.60% of java submissions.

### 思路二（快排）：

先排序，每相邻两位相等，不等则输出

### 代码：

时间复杂度O(n log(n))，空间复杂度O(1)

```java
class Solution {
    public int singleNumber(int[] nums) {
        if (nums.length == 1) {
            return nums[0];
        }
        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 1; i += 2) {
            if (nums[i] != nums[i + 1]) {
                return nums[i];
            }
        }
        return nums[nums.length - 1];
    }
}
```

### Result：

Runtime：6ms

Your runtime beats 32.32% of java submissions.

### 思路三（数学）：

数学

```math
2∗(a+b+c)−(a+a+b+b+c)=c
```

所以，开辟 set 存储唯一元素求和

### 代码：

时间复杂度O(n)，空间复杂度O(n)

```java
class Solution {
    public int singleNumber(int[] nums) {
        if (nums.length == 1) {
            return nums[0];
        }
        int sum_all = 0, set_sum = 0;
        Set<Integer> set = new HashSet<Integer>();

        for (int i = 0; i < nums.length; i++) {
            sum_all += nums[i];
            set.add(nums[i]);
        }
        for (int x : set) {
            set_sum += x;
        }
        return 2 * set_sum - sum_all;
    }
}
```

### 思路四（哈希）：

哈希集有个重要特性，即不包含任何重复元素的无序集合。所以，对于此题可谓是相当适用的，毕竟我们要求的值就是唯一的。

故当我们向哈希集添加元素时，先检查，如果有了直接移除掉；否则，添加新元素，最后剩下的就是唯一的元素。

### 代码：

时间复杂度O(n)，空间复杂度O(n)

```java
class Solution {
    public int singleNumber(int[] nums) {
        if (nums.length == 1) {
            return nums[0];
        }

        Set<Integer> set = new HashSet<Integer>();
        for (int i = 0; i < nums.length; i++) {
            if (set.contains(nums[i])) {
                set.remove(nums[i]);
            } else {
                set.add(nums[i]);
            }
        }
        // Java 中 Set 集合中无法像 list 一样根据索引获取数据
        return set.iterator().next();
    }
}
```