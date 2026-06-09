
![image.png](https://pic.leetcode-cn.com/0f6dc2f4136ae4642464d4613d391fbe7d237943e7d47707ff3324ebdb0f769c-image.png)


这道题得先读懂题目的意思：存在性问题，找到符合题意的“数据对”即可返回 `true`，所有可能的情况都看完以后没有找到才返回 `false`。

题目意思翻译一下：**在数组 `nums[i]` 中，在任意有效区间 `[i, i + k]` 里是否存在两个数的绝对值小于等于 `t`**，存在则返回 `true`，不存在返回 `false`。

### 方法一：暴力解法
枚举所有长度小于等于 `k + 1` 的“下标对`（）`”，只要发现 `nums[i] - nums[j]` 的绝对值小于 `t` ，就返回 `true`。

**参考代码 1**：

```Java []
public class Solution {

    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        int len = nums.length;
        long a;
        long b;

        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len && j <= i + k; j++) {
                a = nums[i];
                b = nums[j];
                if (Math.abs(a - b) <= t) {
                    return true;
                }
            }
        }
        return false;
    }
}
```

**复杂度分析**：

+ 时间复杂度：$O(N^2)$，这里数组的长度为 $N$，枚举可能的数对 $(i, j)$ 。
+ 空间复杂度：$O(1)$。

很容易想到的优化的思路是：以空间换时间，这里的空间还需要有比较大小的功能，比较容易想到的数据结构是二叉搜索树。



### 方法二：滑动窗口（以空间换时间）
题目意思翻译一下：在数组 `nums[i]` 中，在任意有效区间 `[i, i + k]` 里是否存在两个数的绝对值小于等于 `t`，即 

$$
|nums[i] - nums[j] | <= t
$$

等价于 $nums[i] - nums[j] <= t$ 并且 $nums[i] - nums[j] >= -t$，

整理得：$nums[i] <= t + nums[j]$ 并且 $nums[i] >= nums[j] - t$。

于是算法可以在遍历的时候，把遍历到的数存到 `BST` 中，边遍历边查找。

根据刚才得到式子 $nums[i] >= nums[j] - t$，假设当前遍历到的数是 $nums[j]$，$nums[i]$ 就是 $nums[j] - t$ 的天花板数（`ceiling`），这个数同时还要小于等于 $t + nums[j]$。根据这一点写滑动窗口的代码。

+ `ceiling(key)` 函数：返回大于等于 `key` 的最小元素，如果不存在，返回空。下面的是这个函数的文档（通过 Intellij IDEA 查看）。

```Java
/**
  * Returns the least key greater than or equal to the given key,
  * or {@code null} if there is no such key.
  *
  * @param key the key
  * @return the least key greater than or equal to {@code key},
  *         or {@code null} if there is no such key
  * @throws ClassCastException if the specified key cannot be compared
  *         with the keys currently in the map
  * @throws NullPointerException if the specified key is null
  *         and this map does not permit null keys
  */
K ceilingKey(K key);
```

**参考代码 2**：

```Java []
import java.util.TreeSet;

public class Solution {

    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        // 滑动窗口结合查找表，此时滑动窗口即为查找表本身（控制查找表的大小即可控制窗口大小）
        TreeSet<Long> set = new TreeSet<>();
        for (int i = 0; i < nums.length; i++) {
            // 边添加边查找
            // 查找表中是否有大于等于 nums[i] - t 且小于等于 nums[i] + t 的值
            Long ceiling = set.ceiling((long) nums[i] - (long) t);
            if (ceiling != null && ceiling <= ((long) nums[i] + (long) t)) {
                return true;
            }
            // 添加后，控制查找表（窗口）大小，移除窗口最左边元素
            set.add((long) nums[i]);
            if (set.size() == k + 1) {
                set.remove((long) nums[i - k]);
            }
        }
        return false;
    }
}
```

**复杂度分析**：

+ 时间复杂度：$O(N\log K)$，遍历数组使用 $O(N)$，在遍历的同时向二叉搜索树中插入元素和移除元素的时间复杂度是 $O(\log K)$。
+ 空间复杂度：$O(1)$。

另一种写法：在一开始就把滑动窗口左边的元素删除。

**参考代码 3**：

```Java []
import java.util.TreeSet;

public class Solution11 {

    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        int len = nums.length;
        // 特判
        if (len == 0 || k <= 0 || t < 0) {
            return false;
        }

        TreeSet<Long> set = new TreeSet<>();

        for (int i = 0; i < len; i++) {
            if (i > k) {
                set.remove((long) nums[i - k - 1]);
            }

            Long ceiling = set.ceiling((long) nums[i] - (long) t);
            if (ceiling != null && ceiling <= (long) nums[i] + (long) t) {
                return true;
            }

            set.add((long) nums[i]);
        }
        return false;
    }
}
```


**复杂度分析**：（同上）


