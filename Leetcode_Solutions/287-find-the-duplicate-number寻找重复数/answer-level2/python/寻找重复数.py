**注释 ：**
前面的两种方法不满足提示中给出的约束条件，但它们是您在技术面试中可能会想到的解决方案。作为一名面试官，我个人不希望有人提出循环解决方案。

 **证明：**
 证明 `nums` 中存在至少一个副本是鸽子洞原理的简单应用。这里，`nums` 中的每个数字都是一个 “鸽子”，`nums` 中可以出现的每个不同的数字都是一个 “鸽子洞”。因为有 $n+1$ 个数是 $n$ 个不同的可能数，鸽子洞原理意味着至少有一个数是重复的。 

####  方法一：排序
如果对数字进行排序，则任何重复的数字都将与排序后的数组相邻。

**算法：**
算法相当简单。首先，我们对数组进行排序，然后将每个元素与前一个元素进行比较。因为数组中只有一个重复的元素，所以我们知道数组的长度至少为 2，一旦找到重复的元素，我们就可以返回它。 

```Java [ ]
class Solution {
    public int findDuplicate(int[] nums) {
        Arrays.sort(nums);
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == nums[i-1]) {
                return nums[i];
            }
        }

        return -1;
    }
}
```

```Python [ ]
class Solution:
    def findDuplicate(self, nums):
        nums.sort()
        for i in range(1, len(nums)):
            if nums[i] == nums[i-1]:
                return nums[i]
```

**复杂度分析**

* 时间复杂度：$O(nlgn)$。排序调用在 Python 和 Java 中花费 ${O}(nlgn)$ 时间，因此它支配后续的线性扫描。
* 空间复杂度：${O}(1)$ (or ${O}(n)$)，在这里，我们对 `nums` 进行排序，因此内存大小是恒定的。如果我们不能修改输入数组，那么我们必须为 `nums` 的副本分配线性空间，并对其进行排序。 


####  方法二：集合
如果我们在数组上迭代时存储每个元素，我们可以在数组上迭代时简单地检查每个元素。 

**算法：**
为了实现线性时间复杂性，我们需要能够在恒定时间内将元素插入数据结构（并查找它们）。`set` 很好地满足这些约束，所以我们迭代数组并将每个元素插入 `seen` 中。在插入之前，我们检查它是否已经存在。如果是，那么我们找到了我们的副本，所以我们返回它。 

```Java [ ]
class Solution {
    public int findDuplicate(int[] nums) {
        Set<Integer> seen = new HashSet<Integer>();
        for (int num : nums) {
            if (seen.contains(num)) {
                return num;
            }
            seen.add(num);
        }

        return -1;
    }
}
```

```Python [ ]
class Solution:
    def findDuplicate(self, nums):
        seen = set()
        for num in nums:
            if num in seen:
                return num
            seen.add(num)
```

**复杂度分析**

* 时间复杂度：$O(n)$。Python 和 Java 都依赖于底层的哈希表，所以插入和查找有固定的时间复杂度。因此，该算法是线性的，因为它由一个执行 $N$ 次恒定工作的 `for` 循环组成。 
* 空间复杂度：$O(n)$，在最坏的情况下，重复元素出现两次，其中一次出现在数组索引 $n-1$ 处。在这种情况下，`seen` 将包含 $n-1$ 不同的值，因此将占用 $O(n)$ 空间。


####  方法三：弗洛伊德的乌龟和兔子（循环检测） 
如果我们对 `nums` 进行这样的解释，即对于每对索引 $i$ 和值 $v_i$ 而言，“下一个” $v_j$ 位于索引 $v_i$ 处，我们可以将此问题减少到循环检测。
 
 **算法：**
首先，我们可以很容易地证明问题的约束意味着必须存在一个循环。因为 `nums` 中的每个数字都在 $1$ 和 $n$ 之间，所以它必须指向存在的索引。此外，由于 $0$ 不能作为 `nums` 中的值出现，nums[0] 不能作为循环的一部分。

要查看正在运行的算法，请查看下面的动画： 

<![在这里插入图片描述](https://pic.leetcode-cn.com/Figures/287/Slide1.PNG),![在这里插入图片描述](https://pic.leetcode-cn.com/Figures/287/Slide2.PNG),![在这里插入图片描述](https://pic.leetcode-cn.com/Figures/287/Slide3.PNG),![在这里插入图片描述](https://pic.leetcode-cn.com/Figures/287/Slide4.PNG),![在这里插入图片描述](https://pic.leetcode-cn.com/Figures/287/Slide5.PNG),![在这里插入图片描述](https://pic.leetcode-cn.com/Figures/287/Slide6.PNG),![在这里插入图片描述](https://pic.leetcode-cn.com/Figures/287/Slide7.PNG),![在这里插入图片描述](https://pic.leetcode-cn.com/Figures/287/Slide8.PNG),![在这里插入图片描述](https://pic.leetcode-cn.com/Figures/287/Slide9.PNG),![在这里插入图片描述](https://pic.leetcode-cn.com/Figures/287/Slide10.PNG),![在这里插入图片描述](https://pic.leetcode-cn.com/Figures/287/Slide11.PNG),![在这里插入图片描述](https://pic.leetcode-cn.com/Figures/287/Slide12.PNG),![在这里插入图片描述](https://pic.leetcode-cn.com/Figures/287/Slide13.PNG),![在这里插入图片描述](https://pic.leetcode-cn.com/Figures/287/Slide14.PNG),![在这里插入图片描述](https://pic.leetcode-cn.com/Figures/287/Slide15.PNG),![在这里插入图片描述](https://pic.leetcode-cn.com/Figures/287/Slide16.PNG),![在这里插入图片描述](https://pic.leetcode-cn.com/Figures/287/Slide17.PNG),![在这里插入图片描述](https://pic.leetcode-cn.com/Figures/287/Slide18.PNG),![在这里插入图片描述](https://pic.leetcode-cn.com/Figures/287/Slide19.PNG),![在这里插入图片描述](https://pic.leetcode-cn.com/Figures/287/Slide20.PNG),![在这里插入图片描述](https://pic.leetcode-cn.com/Figures/287/Slide21.PNG),![在这里插入图片描述](https://pic.leetcode-cn.com/Figures/287/Slide22.PNG),![在这里插入图片描述](https://pic.leetcode-cn.com/Figures/287/Slide23.PNG),![在这里插入图片描述](https://pic.leetcode-cn.com/Figures/287/Slide24.PNG),![在这里插入图片描述](https://pic.leetcode-cn.com/Figures/287/Slide25.PNG)>

```Java [ ]
class Solution {
    public int findDuplicate(int[] nums) {
        // Find the intersection point of the two runners.
        int tortoise = nums[0];
        int hare = nums[0];
        do {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (tortoise != hare);

        // Find the "entrance" to the cycle.
        int ptr1 = nums[0];
        int ptr2 = tortoise;
        while (ptr1 != ptr2) {
            ptr1 = nums[ptr1];
            ptr2 = nums[ptr2];
        }

        return ptr1;
    }
}
```

```Python [ ]
class Solution:
    def findDuplicate(self, nums):
        # Find the intersection point of the two runners.
        tortoise = nums[0]
        hare = nums[0]
        while True:
            tortoise = nums[tortoise]
            hare = nums[nums[hare]]
            if tortoise == hare:
                break
        
        # Find the "entrance" to the cycle.
        ptr1 = nums[0]
        ptr2 = tortoise
        while ptr1 != ptr2:
            ptr1 = nums[ptr1]
            ptr2 = nums[ptr2]
        
        return ptr1
```

**复杂度分析**

* 时间复杂度：$O(n)$。
* 空间复杂度：$O(1)$