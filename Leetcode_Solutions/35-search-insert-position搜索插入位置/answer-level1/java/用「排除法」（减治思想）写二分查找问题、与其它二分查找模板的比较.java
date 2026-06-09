
首先先说一点：二分查找法不仅仅可以用在有序数组里元素的查找上。如果是一个问题，待查找的数是整数，且知道范围，大概就可以通过逐步排查，缩小问题的规模的方式找到，这种算法也是二分查找算法。

我们平常写程序，定位问题其实通常也用的是这个思路。在适当的地方做一些代码输出，逐步缩小范围，最后找到了有 bug 的那一行或几行代码。

初学写二分查找的问题是：跳步厉害，写下 `left = mid` 或者 `right = mid - 1` 等代码的时候，一定要搞清楚是什么意思，必要的时候写上注释，帮助自己思考和以后复查代码。



本题解最重要的一句话：

**把待搜索的目标值留在最后判断，在循环体内不断地把不符合题目要求的子区间排除掉，在退出循环以后，因为只剩下 1 个数没有看到，它要么是目标元素，要么不是目标元素，单独判断即可。**


以前有个段子，我记得是奇志和大兵说的：说有个人去看病，他其实只是小感冒，医生让他把所有的病症都检查一遍，什么心肝脾胃肾、连 jio 气都让你做检查。这些病你都没有得，那你不就是感冒了吗。虽然是个段子，但是这个思想是很深刻的。用在解二分法的问题上，会使得编码更加容易。


用这种思路写二分**不容易出错，需要考虑的细节最少**。熟悉之后，可以用于写所有的二分问题。而且这种思路也非常符合「二分」的名字，就是把「待搜索区间」分为「有目标元素的区间」和「不包含目标元素的区间」，排除掉「不包含目标元素的区间」的区间，剩下就是「有目标元素的区间」。

算法问题建议更多地理解思想，思考为什么这样写，而不建议背代码，背模板。即使要用代码和模板，例如并查集、线段树这种，也应该先把它们保存到自己的 github 代码仓库里，要用的时候去复制粘贴。

---

**视频 1：用“排除法”（减治思想）写二分查找问题**

（建议倍速观看）

![...除法”（减治思想）写二分查找问题.mp4](833e791f-3ea0-4acc-81ca-a7c895238f29)

视频中使用的 PPT：

<![0035-1.png](https://pic.leetcode-cn.com/0df40afc465b55722b97d352fb8572ff4575807f8a50e2ef427c78299dcbf86d-0035-1.png),![0035-2.png](https://pic.leetcode-cn.com/d0f1175452c050bd7b56cc66188c344482878292d0c812a4fcbead45c71afb6f-0035-2.png),![0035-3.png](https://pic.leetcode-cn.com/a613c4cd4a24456a6f0ce9c36b003392e00e28e0228707c08b3e555b1c68cfc3-0035-3.png),![0035-4.png](https://pic.leetcode-cn.com/4708d1b502a8410931d288e525b72b1e80973067404741238ec40814f750226d-0035-4.png),![0035-5.png](https://pic.leetcode-cn.com/937bfc80f71eb782a2ad2aefd1ca449c2d5ccc100ee5317ee9e1556c1b01d022-0035-5.png),![0035-6.png](https://pic.leetcode-cn.com/bb5c606d21382ab119db271f15ec2c8a4183925db67843ab776400e17ca6ab7e-0035-6.png)>

**视频 2：「力扣」第 35 题：“搜索插入位置”讲解**

（建议倍速观看）

![...de 第 35 题：搜索插入位置.mp4](8857525f-5273-4ed8-9ae7-3e2239b2c4e4)

---


本文先介绍本题的写法。然后介绍编写二分查找算法的思路：排除法（减治法），最后对比了二分查找常见的三种写法。并且给出了使用二分法解决的常见的问题。

### 本题题解

思路：（如果二分查找一开始写不出来，可以尝试先写暴力法，分析清楚细节）在有序数组中查找插入元素的位置，显然可以使用二分查找。这篇题解提供的思路是“排除法”，即在循环的过程中，不断排除不需要的解，最后剩下的那个元素就一定是我们想要的。

+ 首先，插入位置有可能在数组的末尾（题目中的示例 3），需要单独判断；
+ 其次，如果待插入元素比最后一个元素严格小，并且在这个数组中有和插入元素一样的元素，返回任意一个位置即可；
+ 否则，插入的位置应该是严格大于 `target` 的第 1 个元素的位置。

因此，**严格小于 `target` 的元素一定不是解**，根据这个思路，可以写出如下代码。

**参考代码 1**：

```Java []
public class Solution {

    public int searchInsert(int[] nums, int target) {
        int len = nums.length;
        if (len == 0) {
            return 0;
        }

        // 特判
        if (nums[len - 1] < target) {
            return len;
        }
        int left = 0;
        int right = len - 1;
        while (left < right) {
            int mid = (left + right) >>> 1;
            // 严格小于 target 的元素一定不是解
            if (nums[mid] < target) {
                // 下一轮搜索区间是 [mid + 1, right]
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
}
```
```Python []
from typing import List


class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        size = len(nums)
        if size == 0:
            return 0

        # 特判
        if nums[size - 1] < target:
            return size

        left = 0
        right = size - 1

        while left < right:
            mid = left + (right - left) // 2
            # 严格小于 target 的元素一定不是解
            if nums[mid] < target:
                # 下一轮搜索区间是 [mid + 1, right]
                left = mid + 1
            else:
                right = mid
        return left
```
```C++ []
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int size = nums.size();
        if (size == 0) {
            return 0;
        }

        // 特判
        if (nums[size - 1] < target) {
            return size;
        }
        int left = 0;
        int right = size - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            // 严格小于 target 的元素一定不是解
            if (nums[mid] < target) {
                // 下一轮搜索区间是 [mid + 1, right]
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
```

**复杂度分析**：

+ 时间复杂度：$O(\log N)$，这里 $N$ 是数组的长度，每一次都将问题的规模缩减为原来的一半，因此时间复杂度是对数级别的；
+ 空间复杂度：$O(1)$。

### 用“排除法”写的二分查找算法

+ **通常写二分法是奔着目标元素写的**

通常教课书上给出的二分查找代码，循环部分给出的条件是 `while (left <= right)` ，表示当 `left == right` 成立的时候，还有一个元素，即索引 `left`（`right`）位置的元素还没有看到，需要继续查看这个元素的值，看看是不是我们想要的。

这个思路把待查找数组分为了 3 个部分：`mid` 所在位置，`mid` 的左边，`mid` 的右边，根据 `mid` 元素与目标元素的值的大小关系，如果 `nums[mid]` 恰好等于 `target` 直接返回就好了，否则根据不等关系，确定下一轮搜索的区间在哪里。

「力扣」上有些二分题用这种思路做，**有的时候往往会顺带思考很多问题，增加了出错率**：例如

（1）返回 `left` 还是 `right`；
（2）明明已经看到了等于 `target` 的元素，但是题目要求返回小于等于 `target` 的第 1 个元素的位置，或则要求返回大于等于 `target` 的最后 1 个元素的位置的时候，一不小心会把代码写成线性查找。

这两个问题有时会增加思考问题的负担，一不小心还有可能出错。这一类问题的共同特点是：目标值往往在待查找数组中存在多个，但是题目要求我们返回的是一个边界值。

+ **不妨从哪些元素一定不是目标元素考虑**

做对这一类问题的思路是“排除法”，在本题解最开始其实已经介绍了，我们的思路是做排除法：具体是根据看到的 `mid` 位置的元素，排除掉不可能存在目标元素的区间，而下一轮在可能存在目标的子区间里查找。

具体做法是：

1、先把循环可以继续的条件写成 `while (left < right)`。

在循环的过程中 `left` 不断右移，`right` 不断左移。从形式上看，退出循环的时候一定有 `left == right` 成立。此时要注意：**`left` （`right`） 这个位置的值可能程序还没有读取到，因此“有可能”需要再对 `left`（`right`） 这个位置的值是否是目标元素的值做一次判断**。

2、写 `if` 和 `else` 语句的时候，思考当 `nums[mid]` 满足什么性质的时候，`mid` 不是解，进而接着判断 `mid` 的左边有没有可能是解，`mid` 的右边有没有可能是解。

说明：（1）做题的经验告诉我，“思考什么时候不是解”比较好想。生活中其实也是这样，我往往说不大清楚我想要什么，但是我很确定我不想要什么；

> 之所以先考虑「什么时候不是解」，是因为做了很多题以后发现，**这样考虑不容易出错**。在 `if` 语句写对的情况下（建议把下一轮搜索的区间写下来，写在注释里，这样边界怎么设置就很清楚了，不容易乱）。`else` 的情况就不用思考了，肯定是 `if` 的反面。 然后我们注意一下 `mid` 是否需要上取整的问题，最后看看是否需要打个补丁判断一下 `left` 这个位置是不是我们要找的。这个算法就写完了。

（2）此时 `mid` 作为待查找数组的分界，就把它分为两个区间：一个部分可能存在目标元素，一个部分一定不存在目标元素。

**根据 `mid` 被分到左边区间还是右边区间，代码写出来只有以下 2 种（重难点）**：

**边界收缩行为 1**： `mid` 被分到左边。即区间被分成 `[left, mid]` 与 `[mid + 1, right]`，这里用“闭区间”表示区间端点可以取到，下同；

代码写出来是这样的：
```Java []
if (check(mid)) {
    // 下一轮搜索区间是 [mid + 1, right]，因此把左边界设置到 mid + 1 位置
    left = mid + 1;
} else {
    // 上面对了以后，不加思考，剩下的区间一定是 [left, mid]，因此左边界向右收缩到 mid 位置
    right = mid;
}
```

说明：这里的 `check(mid)` 函数通常是一个表达式（例如上面的“参考代码 1”），在一些情况下有可能逻辑比较复杂，建议专门抽取成一个私有方法，以突显主干逻辑。

**边界收缩行为 2**： `mid` 被分到右边。即区间被分成 `[left, mid - 1]` 与 `[mid, right]`；

同上，代码写出来是这样的（由于注释是对称的，这里省略，留给读者填充）：

```Java []
if (check(mid)) {
    right = mid - 1;
} else {
    left = mid;
}
```

3、**根据“边界收缩行为”修改取中间数的行为（重难点）**。

先说一下中间数的取法。一般是这样的：

```Java []
int mid = (left + right) / 2;
```

这种写法在绝大多数情况下没问题，但是在 `left` 和 `right` 特别大的场景中，`left + right` 会发生整形溢出，得到一个负数，`mid` 的值随之也是负数。改进的写法是：

```Java []
int mid = left + (right - left) / 2;
```

这两种写法事实上没有本质的区别，在 `left` 和 `right` 都表示数组索引的时候，几乎不会越界，因为绝大多数情况下不会开那么长的数组。

这里有一个细节，`/` 是整除，它的行为是“向下取整”，造成了 **`int mid = (left + right) / 2` 这种写法 `mid` 永远取不到带搜索区间里最右边的位置**（读者可以举一个只有 `2` 个元素的子数组，理解这句话）。

面对上面的“**边界收缩行为 2**”（`mid` 被分到右边），在待搜索区间收缩到只剩下 2 个元素的时候，**就有可能**（请读者在练习的过程中体会这里我的描述为什么是“有可能”而不是“一定”）造成死循环。如下图：

![LeetCode 第 35 题：“搜索插入位置”.png](https://pic.leetcode-cn.com/eda3857e94d6ead3ed2d2f473fdaf8eaa1252a481e3220511d3a89e4d2f112ac-LeetCode%20%E7%AC%AC%2035%20%E9%A2%98%EF%BC%9A%E2%80%9C%E6%90%9C%E7%B4%A2%E6%8F%92%E5%85%A5%E4%BD%8D%E7%BD%AE%E2%80%9D.png)

> **这里的重点是：当待搜索区间只剩下 2 个元素的时候，才有可能会进入死循环。如果读者不太明白，可以暂时先不去理解这一点，直到编码过程中，出现死循环的时候，再去调试就很清楚了。**

有了上面的分析，我们把上面“边界收缩行为”对应的中间数取法补上：

**边界收缩行为 1**： `mid` 被分到左边。即区间被分成 `[left, mid]` 与 `[mid + 1, right]`，此时取中间数的时候下取整。

```Java []
int mid = left + (right - left) / 2;
if (check(mid)) {
    // 下一轮搜索区间是 [mid + 1, right]
    left = mid + 1;
} else {
    right = mid;
}
```

**边界收缩行为 2**： `mid` 被分到右边。即区间被分成 `[left, mid - 1]` 与 `[mid, right]`，此时取中间数的时候**上取整**。

```Java []
int mid = left + (right - left + 1) / 2;
if (check(mid)) {
    // 下一轮搜索区间是 [left, mid - 1]
    right = mid - 1;
} else {
    left = mid;
}
```

这里我可能没有说得很清楚。如果读者不太明白，也没有关系，读者在练习的过程中，如果遇到死循环，可以在 `while` 循环里把 `left`、`right`、`mid` 变量的值打印出来看，就看得很清楚了。

**遇到几次死循环，调试正确以后**，就能很清楚地记住：

> **在 `if` `else` 语句里面只要出现 `left = mid` 的时候，把去中间数行为改成上取整即可。**

这里有一个比较细节的地方：在 Java 中，有一种特殊的语法，叫无符号右移 `>>>`。我在使用 Java 语言答题的时候，取中间数都写成 `int mid = (left + right) >>> 1` 和  `int mid = (left + right + 1) >>> 1` ，这是因为无符号右移 `>>>` 在对操作数右移以后，不论这个数是正数还是负数，高位一律补 `0`。使用无符号右移的好处是：**即使在 `left + right` 整形溢出以后，得到的结果依然正确**。这一点是从 JDK 的源码中借鉴来的（`Arrays.binarySearch()` 方法）。

在 Python 中虽然没有无符号右移，但是也可以使用 `>>`，因为 Python 在 `left + right` 整型越界的时候，直接转为长整型，因此不会得到负数。

但是，**一般编程语言的编译器都会将 `/2`，以及除以 $2$ 的方幂的操作，在内部修改为 `>>`，因此我们编码的时候没有必要写成右移，还有可能遇到运算优先级顺序的问题，就直接写成 `/` 是没有问题的**。


其它语言我就不清楚了，读者根据自己使用语言的情况选择合适的语法即可。主要内容就是这些，下面做一个总结。

### 使用“排除法”写对二分查找问题的一般步骤

（可以右键“在新标签页中打开图片”可以查看大图）

![image.png](https://pic.leetcode-cn.com/e120bac189db2fc912dce550d9c46746a312f362ee3d6d40e799aad8db69ae6f-image.png)

1、确定搜索区间初始化时候的左右边界，有时需要关注一下边界值。在初始化时，有时把搜索区间设置大一点没有关系，但是如果恰好把边界值排除在外，再怎么搜索都得不到结果。

例如本题，如果一开始把 `len` 这个位置排除在外进行二分搜索，代码是怎么都通不过评测系统的。

2、无条件写上 `while (left < right)` ，表示退出循环的条件是 `left == right`，对于返回左右边界就不用思考了，因此此时它们的值相等；

3、先写下取整的中间数取法，然后**从如何把 `mid` 排除掉的角度思考 `if` 和 `else` 语句应该怎样写**。

（这里建议写两个注释。）

> 一般而言，我都会**把“什么时候不是目标元素”作为注释写在代码中，提醒自己要判断正确**，这一步判断非常关键，直接影响到后面的代码逻辑。
> 然后接着思考 `mid` 不是解的情况下，`mid` 的左右两边可能存在解，**把下一轮搜索的区间范围作为注释写进代码里**，进而在确定下一轮搜索区间边界的收缩行为时，不容易出错。

`if` 有把握写对的情况下，`else` 就是 `if` 的反面，可以不用思考，直接写出来。

**说明：这种思考方式，就正正好把待搜索区间从逻辑上分成两个区间，一个区间不可能存在目标元素，进而在另一个区间里继续搜索，更符合“二分”的语义。**

4、根据 `if` `else` 里面写的情况，看看是否需要修改中间数下取整的行为。

上面已经说了，只有看到 `left = mid` 的时候，才需要调整成为上取整，记住这一点即可，我因为刚开始不理解这种写法，遇到很多次死循环，现在已经牢记在心了。

5、退出循环的时候，一定有 `left == right` 成立。有些时候可以直接返回 `left` （或者 `right`，由于它们相等，后面都省略括弧）或者与 `left` 相关的数值，有些时候还须要再做一次判断，判断 `left` 与 `right` 是否是我们需要查找的元素，这一步叫“后处理”。

本题就是这样，因为插入元素的位置，一定在搜索范围里，因此退出循环的时候，不用再做一次判断。

综上所述，本题还可以有如下两种写法，请读者比较它们的不同之处。

**参考代码 2**：

```Java []
public class Solution {

    public int searchInsert(int[] nums, int target) {
        int len = nums.length;
        if (len == 0) {
            return 0;
        }
        
        int left = 0;
        // 因为有可能数组的最后一个元素的位置的下一个是我们要找的，故右边界是 len
        int right = len;
        
        while (left < right) {
            int mid = (left + right) >>> 1;
            // 小于 target 的元素一定不是解
            if (nums[mid] < target) {
                // 下一轮搜索的区间是 [mid + 1, right]
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
}
```
```Python []
from typing import List


class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        size = len(nums)
        if size == 0:
            return 0

        left = 0
        # 因为有可能数组的最后一个元素的位置的下一个是我们要找的，故右边界是 len
        right = size

        while left < right:
            mid = (left + right) >> 1
            # 严格小于 target 的元素一定不是解
            if nums[mid] < target:
                # 下一轮搜索区间是 [mid + 1, right]
                left = mid + 1
            else:
                right = mid
        return left
```
```C++ []
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int size = nums.size();
        if (size == 0) {
            return 0;
        }

        int left = 0;
        // 因为有可能数组的最后一个元素的位置的下一个是我们要找的，故右边界是 len
        int right = size;

        while (left < right) {
            int mid = left + (right - left) / 2;
            // 小于 target 的元素一定不是解
            if (nums[mid] < target) {
                // 下一轮搜索的区间是 [mid + 1, right]
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
```


**参考代码 3**：

```Java []
public class Solution {

    public int searchInsert(int[] nums, int target) {
        int len = nums.length;
        if (len == 0) {
            return 0;
        }

        int left = 0;
        int right = len;

        while (left < right) {
            int mid = (left + right) >>> 1;
            if (nums[mid] < target) {
                // 下一轮搜索区间是 [mid + 1, right]
                left = mid + 1;
            } else if (nums[mid] == target) {
                // 根据本题特殊性，看到等于 target 的元素，返回任意一个即可
                return mid;
            } else {
                right = mid;
            }
        }
        return left;
    }
}
```
```Python []
from typing import List


class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        size = len(nums)
        if size == 0:
            return 0

        left = 0
        # 因为有可能数组的最后一个元素的位置的下一个是我们要找的，故右边界是 len
        right = size

        while left < right:
            mid = (left + right) >> 1
            # 严格小于 target 的元素一定不是解
            if nums[mid] < target:
                # 下一轮搜索区间是 [mid + 1, right]
                left = mid + 1
            elif nums[mid] == target:
                # 根据本题特殊性，看到等于 target 的元素，返回任意一个即可
                return mid
            else:
                right = mid
        return left
```
```C++ []
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int size = nums.size();
        if (size == 0) {
            return 0;
        }

        int left = 0;
        int right = size;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                // 下一轮搜索区间是 [mid + 1, right]
                left = mid + 1;
            } else if (nums[mid] == target) {
                // 根据本题特殊性，看到等于 target 的元素，返回任意一个即可
                return mid;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
```

### 与其它二分查找模板的比较

它们的区别主要在于 `while` ，这是几个模板之间最主要的差别。

1、 `while (left <= right)` 事实上是把待搜索区间“三分”，`if` `else` 有三个分支，它直接面对目标元素，在目标元素在待搜索数组中有只有 1 个的时候，可能提前结束查找。但是如果目标元素没有在待搜索数组中存在，则不能节约搜索次数；

2、`while (left < right)` 是本题解推荐使用的思考方法，没有写成模板是因为不建议记模板，建议的方法是多做题，掌握“排除法”，更学术的说法是使用“减治法”编写二分查找算法的方法。

优点是：更符合二分语义，不用去思考返回 `left` 还是 `right`，在退出循环的时候，有的时候，根据语境，不正确的数都排除掉，最后剩下的那个数就一定是目标值，不需要再做一次判断。

缺点是：理解当分支逻辑出现 `left = mid` 的时候，要修改取中间数的行为，使其上取整。

3、`while (left + 1 < right)` 这种写法其实很多人都在用，如果你理解了本题解介绍的方法，理解它就很容易了。使用它在退出循环的时候，有 `left + 1 = right` 成立，即 `left` 和 `right`夹成的区间里一定有 2 个元素，此时需要分别判断 `left` 和 `right` 位置的元素是不是目标元素，有时需要注意判断的先后顺序。

优点：不用去理解和处理第 2 点说的那种上取整的行为，因为不会出现死循环。
缺点：一定需要后处理，在后处理这个问题上增加了思考的负担。另外 `while (left + 1 < right)` 这种写法我个人认为不那么自然。

## 练习

「力扣」上的二分查找问题主要有这三类题型。

#### 一、在数组中查找符合条件的元素的索引

一般而言这个数组是有序的，也可能是半有序的，但不大可能是无序的。

| 题目                                                         | 提示与题解                                                   |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [704. 二分查找](https://leetcode-cn.com/problems/binary-search/) | 二分查找的模板问题，使用本题解介绍的方法就要注意，需要“后处理”。 |
| [34. 在排序数组中查找元素的第一个和最后一个位置](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/) | 查找边界问题，[题解（有视频讲解）](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/solution/si-lu-hen-jian-dan-xi-jie-fei-mo-gui-de-er-fen-cha/)。                                               |
| [33. 搜索旋转排序数组](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/) | [题解](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/solution/er-fen-fa-python-dai-ma-java-dai-ma-by-liweiwei141/) |
| [81. 搜索旋转排序数组 II](https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/) | [题解](https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/solution/er-fen-cha-zhao-by-liweiwei1419/) |
| [153. 寻找旋转排序数组中的最小值](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/) | [题解](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/solution/er-fen-fa-fen-zhi-fa-python-dai-ma-java-dai-ma-by-/) |
| [154. 寻找旋转排序数组中的最小值 II](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/) | [题解](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/solution/er-fen-fa-fen-zhi-fa-python-dai-ma-by-liweiwei1419/) |
| [300. 最长上升子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/) | 二分查找的思路需要理解，代码很像第 35 题，[题解](https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/dong-tai-gui-hua-er-fen-cha-zhao-tan-xin-suan-fa-p/)。 |
| [275. H指数 II](https://leetcode-cn.com/problems/h-index-ii/) | [题解](https://leetcode-cn.com/problems/h-index-ii/solution/jian-er-zhi-zhi-er-fen-cha-zhao-by-liweiwei1419-2/) |
| [1095. 山脉数组中查找目标值](https://leetcode-cn.com/problems/find-in-mountain-array/) | [题解](https://leetcode-cn.com/problems/find-in-mountain-array/solution/shi-yong-chao-hao-yong-de-er-fen-fa-mo-ban-python-/) |
| [4. 寻找两个有序数组的中位数](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/) | 二分搜索中最难的问题之一，建议先弄清楚解题思路，[题解](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/he-bing-yi-hou-zhao-gui-bing-guo-cheng-zhong-zhao-/)。 |

#### 二、在一个有上下界的区间里搜索一个整数

| 题目                                                         | 提示与题解                                                   |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [69. 平方根](https://leetcode-cn.com/problems/sqrtx/)        | 在一个整数范围里查找一个整数，也是二分查找法的应用场景，[题解](https://leetcode-cn.com/problems/sqrtx/solution/er-fen-cha-zhao-niu-dun-fa-python-dai-ma-by-liweiw/)。 |
| [287. 寻找重复数](https://leetcode-cn.com/problems/find-the-duplicate-number/) | [题解](https://leetcode-cn.com/problems/find-the-duplicate-number/solution/er-fen-fa-si-lu-ji-dai-ma-python-by-liweiwei1419/)。在一个整数范围里查找一个整数。 |
| [374. 猜数字大小](https://leetcode-cn.com/problems/guess-number-higher-or-lower/) | [题解](https://leetcode-cn.com/problems/guess-number-higher-or-lower/solution/shi-fen-hao-yong-de-er-fen-cha-zhao-fa-mo-ban-pyth/) |

#### 三、判别条件是一个函数

| 题目                                                         | 提示与题解                                                   |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [278. 第一个错误的版本](https://leetcode-cn.com/problems/first-bad-version/) |                                                              |
| [410. 分割数组的最大值](https://leetcode-cn.com/problems/split-array-largest-sum/) |                                                              |
| [658. 找到 K 个最接近的元素](https://leetcode-cn.com/problems/find-k-closest-elements/) | [题解](https://leetcode-cn.com/problems/find-k-closest-elements/solution/pai-chu-fa-shuang-zhi-zhen-er-fen-fa-python-dai-ma/) |
| [875. 爱吃香蕉的珂珂](https://leetcode-cn.com/problems/koko-eating-bananas/) | [题解](https://leetcode-cn.com/problems/koko-eating-bananas/solution/er-fen-cha-zhao-ding-wei-su-du-by-liweiwei1419/) |
| [1300. 转变数组后最接近目标值的数组和](https://leetcode-cn.com/problems/sum-of-mutated-array-closest-to-target/) | [题解](https://leetcode-cn.com/problems/sum-of-mutated-array-closest-to-target/solution/er-fen-cha-zhao-by-liweiwei1419-2/) |




