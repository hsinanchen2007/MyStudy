
这道题据说是面试的高频考题，同时也是基础算法的应用。

![image.png](https://pic.leetcode-cn.com/97186c31a9c3a4af8654c52e5e15e1073d623a57fb4d7fc04b32cc914b906c12-image.png)



### 方法一：暴力解法


题目要求我们找到“数组排序后的第 $k$ 个最大的元素，而不是第 $k$ 个不同的元素” ，

语义是从右边往左边数第 $k$ 个元素（从 $1$ 开始），那么从左向右数是第几个呢，我们列出几个找找规律就好了。

+ 一共 $6$ 个元素，找第 $2$ 大，索引是 $4$；
+ 一共 $6$ 个元素，找第 $4$ 大，索引是 $2$。

因此，升序排序以后，**目标元素的索引是 `len - k`**。这是最简单的思路，如果只答这个方法，面试官可能并不会满意，但是在我们平时的开发工作中，还是不能忽视这种思路简单的方法，理由如下：

+ 最简单同时也一定是最容易编码的，编码成功的几率最高，可以用这个最简单思路编码的结果和其它思路编码的结果进行比对，验证高级算法的正确性；

+ 在数据规模小、对时间复杂度、空间复杂度要求不高的时候，简单问题简单做；

+ 思路简单的算法考虑清楚了，有些时候能为实现高级算法铺路，这道题也是如此；

+ 低级算法往往容错性最好，即在输入不满足题目条件的时候，往往还能得到正确的答案，而高级算法对输入数据的要求就非常苛刻，这一点可以参考 [「力扣」第 4 题：“寻找两个有序数组的中位数”](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/)。

**参考代码 1**：

```Java []
import java.util.Arrays;

public class Solution {

    public int findKthLargest(int[] nums, int k) {
        int len = nums.length;
        Arrays.sort(nums);
        return nums[len - k];
    }
}
```
```C++ []
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        int size = nums.size();
        sort(begin(nums), end(nums));
        return nums[size - k];
    }
};
```
```Python []
from typing import List


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        size = len(nums)
        nums.sort()
        return nums[size - k]
```


**复杂度分析**：
+ 时间复杂度：$O(N \log N)$，这里 $N$ 是数组的长度，算法的性能消耗主要在排序，JDK 默认使用快速排序，因此时间复杂度为 $O(N \log N)$。
+ 空间复杂度：$O(1)$，这里是原地排序，没有借助额外的辅助空间。

到这里，我们已经分析出了：

1、我们应该返回最终排定以后位于 `len - k` 的那个元素；
2、性能消耗主要在排序，JDK 默认使用快速排序。

学习过 “快速排序” 的朋友，一定知道一个操作叫 partition，它是 “分而治之” 思想当中 “分” 的那一步。经过 partition 操作以后，每一次都能排定一个元素，并且这个元素左边的数都不大于它，这个元素右边的数都不小于它，并且我们还能知道排定以后的元素的索引。于是可以应用 “减而治之”（分治思想的特例）的思想，把问题规模转化到一个更小的范围里。

于是得到方法二。


### 方法二：借助 partition 操作定位到最终排定以后索引为 `len - k` 的那个元素（特别注意：随机化切分元素）

以下是注意事项，因为很重要，所以放在前面说：

> **快速排序虽然快，但是如果实现得不好，在遇到特殊测试用例的时候，时间复杂度会变得很高。如果你使用 `partition` 的方法完成这道题，时间排名不太理想，可以考虑一下是什么问题，这个问题很常见。**

以下的描述基于 “快速排序” 算法知识的学习，如果忘记的朋友们可以翻一翻自己的《数据结构与算法》教材，复习一下，partition 过程、分治思想和 “快速排序” 算法的优化。

分析：我们在学习 “快速排序” 的时候，接触的第 1 个操作就是 partition（切分），简单介绍如下：

partition（切分）操作，使得：

+ 对于某个索引 `j`，`nums[j]` 已经排定，即 `nums[j]` 经过 partition（切分）操作以后会放置在它 “最终应该放置的地方”；
+ `nums[left]` 到 `nums[j - 1]` 中的所有元素都不大于 `nums[j]`；
+ `nums[j + 1]` 到 `nums[right]` 中的所有元素都不小于 `nums[j]`。

![image.png](https://pic.leetcode-cn.com/65ec311c3e9792bb17e9c08cabd4a07f251c9cd65a011b6c5ffb54b46d8e5012-image.png)


partition（切分）操作总能排定一个元素，还能够知道这个元素它最终所在的位置，这样每经过一次 partition（切分）操作就能缩小搜索的范围，这样的思想叫做 “减而治之”（是 “分而治之” 思想的特例）。

切分过程可以不借助额外的数组空间，仅通过交换数组元素实现。下面是参考代码：

**参考代码 2**：

```Java []
public class Solution {

    public int findKthLargest(int[] nums, int k) {
        int len = nums.length;
        int left = 0;
        int right = len - 1;

        // 转换一下，第 k 大元素的索引是 len - k
        int target = len - k;

        while (true) {
            int index = partition(nums, left, right);
            if (index == target) {
                return nums[index];
            } else if (index < target) {
                left = index + 1;
            } else {
                right = index - 1;
            }
        }
    }

    /**
     * 在数组 nums 的子区间 [left, right] 执行 partition 操作，返回 nums[left] 排序以后应该在的位置
     * 在遍历过程中保持循环不变量的语义
     * 1、[left + 1, j] < nums[left]
     * 2、(j, i] >= nums[left]
     *
     * @param nums
     * @param left
     * @param right
     * @return
     */
    public int partition(int[] nums, int left, int right) {
        int pivot = nums[left];
        int j = left;
        for (int i = left + 1; i <= right; i++) {
            if (nums[i] < pivot) {
                // 小于 pivot 的元素都被交换到前面
                j++;
                swap(nums, j, i);
            }
        }
        // 在之前遍历的过程中，满足 [left + 1, j] < pivot，并且 (j, i] >= pivot
        swap(nums, j, left);
        // 交换以后 [left, j - 1] < pivot, nums[j] = pivot, [j + 1, right] >= pivot
        return j;
    }

    private void swap(int[] nums, int index1, int index2) {
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }
}
```
```Python []
from typing import List
import random


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        size = len(nums)

        target = size - k
        left = 0
        right = size - 1
        while True:
            index = self.__partition(nums, left, right)
            if index == target:
                return nums[index]
            elif index < target:
                # 下一轮在 [index + 1, right] 里找
                left = index + 1
            else:
                right = index - 1

    #  循环不变量：[left + 1, j] < pivot
    #  (j, i) >= pivot
    def __partition(self, nums, left, right):

        pivot = nums[left]
        j = left
        for i in range(left + 1, right + 1):
            if nums[i] < pivot:
                j += 1
                nums[i], nums[j] = nums[j], nums[i]

        nums[left], nums[j] = nums[j], nums[left]
        return j
```

**复杂度分析**：
+ 时间复杂度：$O(N)$，这里 $N$ 是数组的长度，理由可以参考本题解下用户 @ZLW 的评论，需要使用主定理进行分析。
+ 空间复杂度：$O(1)$，原地排序，没有借助额外的辅助空间。

> **注意：本题必须随机初始化 `pivot` 元素，否则通过时间会很慢，因为测试用例中有极端测试用例。**

为了应对极端测试用例，使得递归树加深，可以在循环一开始的时候，随机交换第 $1$ 个元素与它后面的任意 $1$ 个元素的位置；

说明：最极端的是顺序数组与倒序数组，此时递归树画出来是链表，时间复杂度是 $O(N^2)$，根本达不到减治的效果。

**参考代码 3**：

```Java []
import java.util.Random;

public class Solution {

    private static Random random = new Random(System.currentTimeMillis());

    public int findKthLargest(int[] nums, int k) {
        int len = nums.length;
        int target = len - k;
        int left = 0;
        int right = len - 1;
        while (true) {
            int index = partition(nums, left, right);
            if (index < target) {
                left = index + 1;
            } else if (index > target) {
                right = index - 1;
            } else {
                return nums[index];
            }
        }
    }

    // 在区间 [left, right] 这个区间执行 partition 操作

    private int partition(int[] nums, int left, int right) {
        // 在区间随机选择一个元素作为标定点
        if (right > left) {
            int randomIndex = left + 1 + random.nextInt(right - left);
            swap(nums, left, randomIndex);
        }

        int pivot = nums[left];
        int j = left;
        for (int i = left + 1; i <= right; i++) {
            if (nums[i] < pivot) {
                j++;
                swap(nums, j, i);
            }
        }
        swap(nums, left, j);
        return j;
    }

    private void swap(int[] nums, int index1, int index2) {
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }
} 
```
```Python []
from typing import List
import random


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        size = len(nums)

        target = size - k
        left = 0
        right = size - 1
        while True:
            index = self.__partition(nums, left, right)
            if index == target:
                return nums[index]
            elif index < target:
                # 下一轮在 [index + 1, right] 里找
                left = index + 1
            else:
                right = index - 1

    #  循环不变量：[left + 1, j] < pivot
    #  (j, i) >= pivot
    def __partition(self, nums, left, right):
        # 随机化切分元素
        # randint 是包括左右区间的
        random_index = random.randint(left, right)
        nums[random_index], nums[left] = nums[left], nums[random_index]

        pivot = nums[left]
        j = left
        for i in range(left + 1, right + 1):
            if nums[i] < pivot:
                j += 1
                nums[i], nums[j] = nums[j], nums[i]

        nums[left], nums[j] = nums[j], nums[left]
        return j
```

2、使用双指针，将与 `pivot` 相等的元素等概论地分到 `pivot` 最终排定位置的两边。

**参考代码 4**：使用双指针的办法找到切分元素的位置。

```Java []
import java.util.Random;

public class Solution {

    private static Random random = new Random(System.currentTimeMillis());

    public int findKthLargest(int[] nums, int k) {
        int len = nums.length;
        int left = 0;
        int right = len - 1;

        // 转换一下，第 k 大元素的索引是 len - k
        int target = len - k;

        while (true) {
            int index = partition(nums, left, right);
            if (index == target) {
                return nums[index];
            } else if (index < target) {
                left = index + 1;
            } else {
                right = index - 1;
            }
        }
    }

    public int partition(int[] nums, int left, int right) {
        // 在区间随机选择一个元素作为标定点
        if (right > left) {
            int randomIndex = left + 1 + random.nextInt(right - left);
            swap(nums, left, randomIndex);
        }

        int pivot = nums[left];

        // 将等于 pivot 的元素分散到两边
        // [left, lt) <= pivot
        // (rt, right] >= pivot

        int lt = left + 1;
        int rt = right;

        while (true) {
            while (lt <= rt && nums[lt] < pivot) {
                lt++;
            }
            while (lt <= rt && nums[rt] > pivot) {
                rt--;
            }

            if (lt > rt) {
                break;
            }
            swap(nums, lt, rt);
            lt++;
            rt--;
        }

        swap(nums, left, rt);
        return rt;
    }

    private void swap(int[] nums, int index1, int index2) {
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }
}
```
```C++ []
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int partition(vector<int> &nums, int left, int right) {
        // 随机在 [left, right] 中, 选择一个数值作为标定点 pivot
        swap(nums[left], nums[rand() % (right - left + 1) + left]);

        int pivot = nums[left];
        while (left < right) {
            while (left < right & nums[right] >= pivot) {
                right--;
            }
            nums[left] = nums[right];
            while (left < right & nums[left] < pivot) {
                left++;
            }
            nums[right] = nums[left];
        }
        nums[left] = pivot;
        return left;
    }

public:
    int findKthLargest(vector<int> &nums, int k) {
        int size = nums.size();
        int target = size - k;

        int left = 0;
        int right = size - 1;
        while (true) {
            int p = partition(nums, left, right);
            if (p == target) {
                return nums[p];
            } else if (target < p) {
                right = p - 1;
            } else {
                left = p + 1;
            }
        }
    }
};
```
```Python []
from typing import List
import random


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        size = len(nums)

        target = size - k
        left = 0
        right = size - 1
        while True:
            index = self.__partition(nums, left, right)
            if index == target:
                return nums[index]
            elif index < target:
                # 下一轮在 [index + 1, right] 里找
                left = index + 1
            else:
                right = index - 1

    # 循环不变量：
    # [left + 1, lt） <= pivot
    # (rt, right] >= pivot
    def __partition(self, nums, left, right):
        # randint 是包括左右区间的
        random_index = random.randint(left, right)
        nums[random_index], nums[left] = nums[left], nums[random_index]

        pivot = nums[left]

        lt = left + 1
        rt = right

        while True:
            while lt <= rt and nums[lt] < pivot:
                lt += 1
            while lt <= rt and nums[rt] > pivot:
                rt -= 1

            if lt > rt:
                break
            nums[lt], nums[rt] = nums[rt], nums[lt]
            lt += 1
            rt -= 1

        nums[left], nums[rt] = nums[rt], nums[left]
        return rt
```



### 方法三：优先队列

优先队列的思路是很朴素的。因为第 `K` 大元素，其实就是整个数组排序以后后半部分最小的那个元素。因此，我们可以维护一个有 `K` 个元素的最小堆：

1、如果当前堆不满，直接添加；

2、堆满的时候，如果新读到的数小于等于堆顶，肯定不是我们要找的元素，只有新都到的数大于堆顶的时候，才将堆顶拿出，然后放入新读到的数，进而让堆自己去调整内部结构。

说明：这里最合适的操作其实是 `replace`，即直接把新读进来的元素放在堆顶，然后执行下沉（`siftDown`）操作。Java 当中的 `PriorityQueue` 没有提供这个操作，只好先 `poll()` 再 `offer()`。 

优先队列的写法就很多了，这里例举一下我能想到的（以下的写法大同小异，没有本质差别）。

假设数组有 `len` 个元素。

思路1：把 `len` 个元素都放入一个最小堆中，然后再 `pop()` 出 `len - k` 个元素，此时最小堆只剩下 `k` 个元素，堆顶元素就是数组中的第 `k` 个最大元素。

思路2：把 `len` 个元素都放入一个最大堆中，然后再 `pop()` 出 `k - 1` 个元素，因为前 `k - 1` 大的元素都被弹出了，此时最大堆的堆顶元素就是数组中的第 `k` 个最大元素。

根据以上思路，分别写出下面的代码：

**参考代码 5**：

```Java []
import java.util.PriorityQueue;

public class Solution {

    public int findKthLargest(int[] nums, int k) {
        int len = nums.length;
        // 使用一个含有 len 个元素的最小堆，默认是最小堆，可以不写 lambda 表达式：(a, b) -> a - b
        PriorityQueue<Integer> minHeap = new PriorityQueue<>(len, (a, b) -> a - b);
        for (int i = 0; i < len; i++) {
            minHeap.add(nums[i]);
        }
        for (int i = 0; i < len - k; i++) {
            minHeap.poll();
        }
        return minHeap.peek();
    }
}
```

**参考代码 6**：

```Java []
import java.util.PriorityQueue;

public class Solution {

    public int findKthLargest(int[] nums, int k) {
        int len = nums.length;
        // 使用一个含有 len 个元素的最大堆，lambda 表达式应写成：(a, b) -> b - a
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(len, (a, b) -> b - a);
        for (int i = 0; i < len; i++) {
            maxHeap.add(nums[i]);
        }
        for (int i = 0; i < k - 1; i++) {
            maxHeap.poll();
        }
        return maxHeap.peek();
    }
}
```

思路 3：只用 `k` 个容量的优先队列，而不用全部 `len` 个容量。

**参考代码 7**：

```Java []
import java.util.PriorityQueue;

public class Solution {

    public int findKthLargest(int[] nums, int k) {
        int len = nums.length;
        // 使用一个含有 k 个元素的最小堆
        PriorityQueue<Integer> minHeap = new PriorityQueue<>(k, (a, b) -> a - b);
        for (int i = 0; i < k; i++) {
            minHeap.add(nums[i]);
        }
        for (int i = k; i < len; i++) {
            // 看一眼，不拿出，因为有可能没有必要替换
            Integer topEle = minHeap.peek();
            // 只要当前遍历的元素比堆顶元素大，堆顶弹出，遍历的元素进去
            if (nums[i] > topEle) {
                minHeap.poll();
                minHeap.add(nums[i]);
            }
        }
        return minHeap.peek();
    }
}
```
```Python []
from typing import List
import heapq


class Solution:

    # 使用容量为 k 的小顶堆
    # 元素个数小于 k 的时候，放进去就是了
    # 元素个数大于 k 的时候，小于等于堆顶元素，就扔掉，大于堆顶元素，就替换

    def findKthLargest(self, nums: List[int], k: int) -> int:
        size = len(nums)
        if k > size:
            raise Exception('程序出错')

        L = []
        for index in range(k):
            # heapq 默认就是小顶堆
            heapq.heappush(L, nums[index])

        for index in range(k, size):
            top = L[0]
            if nums[index] > top:
                # 看一看堆顶的元素，只要比堆顶元素大，就替换堆顶元素
                heapq.heapreplace(L, nums[index])
        # 最后堆顶中的元素就是堆中最小的，整个数组中的第 k 大元素
        return L[0]
```

思路 4：用 `k + 1` 个容量的优先队列，使得上面的过程更“连贯”一些，到了 `k` 个以后的元素，就进来一个，出去一个，让优先队列自己去维护大小关系。


**参考代码 8**：

```Java []
import java.util.PriorityQueue;

public class Solution {

    public int findKthLargest(int[] nums, int k) {
        int len = nums.length;
        // 最小堆
        PriorityQueue<Integer> priorityQueue = new PriorityQueue<>(k + 1, (a, b) -> (a - b));
        for (int i = 0; i < k; i++) {
            priorityQueue.add(nums[i]);
        }
        for (int i = k; i < len; i++) {
            priorityQueue.add(nums[i]);
            priorityQueue.poll();
        }
        return priorityQueue.peek();
    }
}
```
```Java []
import java.util.PriorityQueue;

public class Solution5 {
    public int findKthLargest(int[] nums, int k) {
        int len = nums.length;
        // 最小堆
        PriorityQueue<Integer> priorityQueue = new PriorityQueue<>(k + 1, (a, b) -> (a - b));
        for (int num : nums) {
            priorityQueue.add(num);
            if (priorityQueue.size() == k + 1) {
                priorityQueue.poll();
            }
        }
        return priorityQueue.peek();
    }
}
```

思路 5：综合考虑以上两种情况，总之都是为了节约空间复杂度。即 `k` 较小的时候使用最小堆，`k` 较大的时候使用最大堆。

**参考代码 9**：

```Java []
import java.util.PriorityQueue;

public class Solution {

    // 根据 k 的不同，选最大堆和最小堆，目的是让堆中的元素更小
    // 思路 1：k 要是更靠近 0 的话，此时 k 是一个较大的数，用最大堆
    // 例如在一个有 6 个元素的数组里找第 5 大的元素
    // 思路 2：k 要是更靠近 len 的话，用最小堆

    // 所以分界点就是 k = len - k

    public int findKthLargest(int[] nums, int k) {
        int len = nums.length;
        if (k <= len - k) {
            // System.out.println("使用最小堆");
            // 特例：k = 1，用容量为 k 的最小堆
            // 使用一个含有 k 个元素的最小堆
            PriorityQueue<Integer> minHeap = new PriorityQueue<>(k, (a, b) -> a - b);
            for (int i = 0; i < k; i++) {
                minHeap.add(nums[i]);
            }
            for (int i = k; i < len; i++) {
                // 看一眼，不拿出，因为有可能没有必要替换
                Integer topEle = minHeap.peek();
                // 只要当前遍历的元素比堆顶元素大，堆顶弹出，遍历的元素进去
                if (nums[i] > topEle) {
                    minHeap.poll();
                    minHeap.add(nums[i]);
                }
            }
            return minHeap.peek();

        } else {
            // System.out.println("使用最大堆");
            assert k > len - k;
            // 特例：k = 100，用容量为 len - k + 1 的最大堆
            int capacity = len - k + 1;
            PriorityQueue<Integer> maxHeap = new PriorityQueue<>(capacity, (a, b) -> b - a);
            for (int i = 0; i < capacity; i++) {
                maxHeap.add(nums[i]);
            }
            for (int i = capacity; i < len; i++) {
                // 看一眼，不拿出，因为有可能没有必要替换
                Integer topEle = maxHeap.peek();
                // 只要当前遍历的元素比堆顶元素大，堆顶弹出，遍历的元素进去
                if (nums[i] < topEle) {
                    maxHeap.poll();
                    maxHeap.add(nums[i]);
                }
            }
            return maxHeap.peek();
        }
    }
}
```