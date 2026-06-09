#### 绪章

一般来说，对于一个问题我通常会给出两种以上的解法，但是对于洗牌问题，Fisher-Yates 洗牌算法即是通俗解法，同时也是渐进最优的解法。

在我们开始之前需要了解一些关于随机化的知识 - 下面介绍的两个方法都假设编程语言中提供的伪随机数生成器是足够随机的。我们给出的示例代码也都采用了最简单的方法来得到伪随机数，但为了让数组的每个排列出现的可能性尽可能相等，还是有一些其他东西需要注意的。例如，一个长度为 $n$ 的数组有 $n!$ 个不同的排列组合。因此，为了能将所有的排列在整数空间编码，我们需要 $\lceil lg(n!)\rceil$ 比特，这是默认的伪随机数不能保证的。

#### 方法一： 暴力 【通过】

**思路**

假设我们把每个数都放在一个 ”帽子“ 里面，然后我们从帽子里面把它们一个个摸出来，摸出来的数按顺序放入数组，这个数组正好就是我们要的洗牌后的数组。

**算法**

暴力算法简单的来说就是把每个数放在一个 ”帽子“ 里面，每次从 ”帽子“ 里面随机摸一个数出来，直到 “帽子” 为空。下面是具体操作，首先我们把数组 `array` 复制一份给数组 `aux`，之后每次随机从 `aux` 中取一个数，为了防止数被重复取出，每次取完就把这个数从 `aux` 中移除。`重置` 的实现方式很简单，只需把 `array` 恢复称最开始的状态就可以了。 

这个算法的正确性在于，每次 `for` 循环中，任何一个元素都会以等可能的概率被选中。为了证明这一点，我们可以算出来，一个特定的元素 $e$ 在第 $k$ 轮被选中的概率为 $P$($e$ 在第 $k$ 轮被选中) $\cdot$ $P$($e$ 在前 $k$ 轮不被选中)。假设洗牌的数组有 $n$ 个元素，这个概率公式如下所示：

$$
   \frac{1}{n-k} \cdot \prod_{i=1}^{k} \frac{n-i}{n-i+1}
$$

把这个式子展开一下是这样的：

$$
   (\frac{n-1}{n}
   \cdot \frac{n-2}{n-1}
   \cdot (\ldots)
   \cdot \frac{n-k+1}{n-k+2}
   \cdot \frac{n-k}{n-k+1})
   \cdot \frac{1}{n-k}
$$

在 $k = 0$ 的情况下，很显然 $\frac{1}{n-k} = \frac{1}{n}$。 对于 $k > 0$ 的情况，前一个式子的分子正好能把下一个式子的分母约去，到最后也只有第一个式子分母还在。因此，不管是哪一轮摸到了哪一个数，概率都是 $\frac{1}{n}$，所以这个数组的每个排列组合都是等概率的。

```Java []
class Solution {
    private int[] array;
    private int[] original;

    private Random rand = new Random();

    private List<Integer> getArrayCopy() {
        List<Integer> asList = new ArrayList<Integer>();
        for (int i = 0; i < array.length; i++) {
            asList.add(array[i]);
        }
        return asList;
    }

    public Solution(int[] nums) {
        array = nums;
        original = nums.clone();
    }
    
    public int[] reset() {
        array = original;
        original = original.clone();
        return array;
    }
    
    public int[] shuffle() {
        List<Integer> aux = getArrayCopy();

        for (int i = 0; i < array.length; i++) {
            int removeIdx = rand.nextInt(aux.size());
            array[i] = aux.get(removeIdx);
            aux.remove(removeIdx);
        }

        return array;
    }
}
```

```Python []
class Solution:
    def __init__(self, nums):
        self.array = nums
        self.original = list(nums)

    def reset(self):
        self.array = self.original
        self.original = list(self.original)
        return self.array

    def shuffle(self):
        aux = list(self.array)

        for idx in range(len(self.array)):
            remove_idx = random.randrange(len(aux))
            self.array[idx] = aux.pop(remove_idx)

        return self.array
```

**复杂度分析**

* 时间复杂度： $O(n^2)$
乘方时间复杂度来自于 `list.remove`（`list.pop`）。每次操作都是线性时间的，总共发生 $n$ 次。

* 空间复杂度： $O(n)$
因为需要实现 `重置` 方法，需要额外的空间把原始数组另存一份，在重置的时候用来恢复原始状态。

#### 方法二： Fisher-Yates 洗牌算法 【通过】

**思路**

我们可以用一个简单的技巧来降低之前算法的时间复杂度和空间复杂度，那就是让数组中的元素互相交换，这样就可以避免掉每次迭代中用于修改列表的时间了。

**算法**

Fisher-Yates 洗牌算法跟暴力算法很像。在每次迭代中，生成一个范围在当前下标到数组末尾元素下标之间的随机整数。接下来，将当前元素和随机选出的下标所指的元素互相交换 - 这一步模拟了每次从 “帽子” 里面摸一个元素的过程，其中选取下标范围的依据在于每个被摸出的元素都不可能再被摸出来了。此外还有一个需要注意的细节，当前元素是可以和它本身互相交换的 - 否则生成最后的排列组合的概率就不对了。为了更清楚地理解这一过程，可以看下面这些动画：

<![1000](https://pic.leetcode-cn.com/Figures/384/384_fisher_yates1.png),![1000](https://pic.leetcode-cn.com/Figures/384/384_fisher_yates2.png),![1000](https://pic.leetcode-cn.com/Figures/384/384_fisher_yates3.png),![1000](https://pic.leetcode-cn.com/Figures/384/384_fisher_yates4.png),![1000](https://pic.leetcode-cn.com/Figures/384/384_fisher_yates5.png),![1000](https://pic.leetcode-cn.com/Figures/384/384_fisher_yates6.png),![1000](https://pic.leetcode-cn.com/Figures/384/384_fisher_yates7.png),![1000](https://pic.leetcode-cn.com/Figures/384/384_fisher_yates8.png),![1000](https://pic.leetcode-cn.com/Figures/384/384_fisher_yates9.png),![1000](https://pic.leetcode-cn.com/Figures/384/384_fisher_yates10.png),![1000](https://pic.leetcode-cn.com/Figures/384/384_fisher_yates11.png),![1000](https://pic.leetcode-cn.com/Figures/384/384_fisher_yates12.png),![1000](https://pic.leetcode-cn.com/Figures/384/384_fisher_yates13.png),![1000](https://pic.leetcode-cn.com/Figures/384/384_fisher_yates14.png),![1000](https://pic.leetcode-cn.com/Figures/384/384_fisher_yates15.png),![1000](https://pic.leetcode-cn.com/Figures/384/384_fisher_yates16.png),![1000](https://pic.leetcode-cn.com/Figures/384/384_fisher_yates17.png),![1000](https://pic.leetcode-cn.com/Figures/384/384_fisher_yates18.png)>

```Java []
class Solution {
    private int[] array;
    private int[] original;

    Random rand = new Random();

    private int randRange(int min, int max) {
        return rand.nextInt(max - min) + min;
    }

    private void swapAt(int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    public Solution(int[] nums) {
        array = nums;
        original = nums.clone();
    }
    
    public int[] reset() {
        array = original;
        original = original.clone();
        return original;
    }
    
    public int[] shuffle() {
        for (int i = 0; i < array.length; i++) {
            swapAt(i, randRange(i, array.length));
        }
        return array;
    }
}
```

```Python []
class Solution:
    def __init__(self, nums):
        self.array = nums
        self.original = list(nums)

    def reset(self):
        self.array = self.original
        self.original = list(self.original)
        return self.array

    def shuffle(self):
        for i in range(len(self.array)):
            swap_idx = random.randrange(i, len(self.array))
            self.array[i], self.array[swap_idx] = self.array[swap_idx], self.array[i]
        return self.array
```

**复杂度分析**

* 时间复杂度 ： $O(n)$
Fisher-Yates 洗牌算法时间复杂度是线性的，因为算法中生成随机序列，交换两个元素这两种操作都是常数时间复杂度的。

* 空间复杂度： $O(n)$
因为要实现 `重置` 功能，原始数组必须得保存一份，因此空间复杂度并没有优化。