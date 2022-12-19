### 写在前面：
如果您觉得写得还可以，那就来关注在下的微信公众号吧“张氏文画”，不光有新鲜的 LeetCode 题解（包教包会），还有经典的文章及短视频和大家分享，谢谢大家的关注！！！
![微信公众号.jpg](https://pic.leetcode-cn.com/123a63d71f1256d8e71c72b05c664a076f4f94a668ab66dcd3b31bb10b3eca63-%E5%BE%AE%E4%BF%A1%E5%85%AC%E4%BC%97%E5%8F%B7.jpg)


### 思路一（位运算）：

二进制异或。两位相同为0，不同得1。即两个数相同，异或得0。0和任何数异或得到的都是该数本身。将数组中所有数进行异或，其中出现两次的数抵消为0，剩下的就是出现一次的那个数。

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

观察如下数学公式，可以获得思路

```math
2∗(a+b+c)−(a+a+b+b+c)=c
```

因此，我们可以开辟 set 来存储去重之后的所有元素并求和得到 set_sum，2倍的 set_sum 减去 所有元素的和即为所求值。

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

### Result：

Runtime：7ms

Your runtime beats 30.21% of java submissions.

### 思路四（哈希）：

哈希集有个重要特性，即不包含任何重复元素的无序集合。所以，对于此题是相当适用的，毕竟我们要求的值就是唯一的。

故当我们向哈希集添加元素时，先检查，如果有了直接移除掉；否则，添加新元素，最后剩下的就是唯一的元素。

注意：Java 中的 Set 集合，无法像 list 一样根据索引获取数据

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

### Result：

Runtime：15ms

Your runtime beats 14.57% of java submissions.