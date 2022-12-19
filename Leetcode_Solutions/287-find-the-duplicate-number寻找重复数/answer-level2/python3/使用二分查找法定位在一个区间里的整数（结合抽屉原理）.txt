抽屉原理：桌上有十个苹果，要把这十个苹果放到九个抽屉里，无论怎样放，我们会发现至少会有一个抽屉里面放不少于两个苹果。

**思路**：如果题目不限制：

1. 不能更改原数组（假设数组是只读的）；  
2. 只能使用额外的 `O(1)` 的空间。

容易想到的方法有：

1. 使用哈希表判重，这违反了限制 2；  
2. 将原始数组排序，排序以后，重复的数相邻，即找到了重复数，这违反了限制 1；  
3. 使用类似「力扣」第 41 题：[“缺失的第一个正数”](https://leetcode-cn.com/problems/first-missing-positive) 的思路，当两个数发现要放在同一个地方的时候，就发现了这个重复的元素，这违反了限制 1；  
4. 既然要定位数，这个数恰好是一个整数，可以在“整数的有效范围内”做二分查找，但是比较恶心的一点是得反复看整个数组好几次，本文就介绍通过二分法定位数；  
5. 还可以使用“快慢指针”来完成，不过这种做法太有技巧性了，不是通用的做法，官方的题解就提供了这种做法。

### 方法：二分查找

**思路**：这道题要求我们查找的数是一个整数，并且给出了这个整数的范围（在 $1$ 和 $n$ 之间，包括 `1` 和 `n`），并且给出了一些限制，于是可以使用二分查找法定位在一个区间里的整数。

这个问题应用二分法与绝大多数其它问题应用二分法的不同点是：正着思考是容易的，即思考哪边区间存在重复数是容易的，因为依然是有抽屉原理做保证。我们依然通过一个具体的例子来分析应该如何编写代码。

以 `[1, 2, 2, 3, 4, 5, 6, 7]` 为例，一共 `8` 个数，`n + 1 = 8`，`n = 7`，根据题目意思，每个数都在 `1` 和 `7` 之间。

例如：区间 `[1, 7]` 的中位数是 `4`，遍历整个数组，统计小于等于 `4` 的整数的个数，至多应该为 `4` 个。换句话说，整个数组里小于等于 `4` 的整数的个数如果严格大于 `4` 个，就说明重复的数存在于区间 `[1, 4]`，它的反面是：重复的数存在于区间 `[5, 7]`。

于是，二分法的思路是先猜一个数（有效范围 `[left, right]`里的中间数 `mid`），然后统计原始数组中**小于等于**这个中间数的元素的个数 `cnt`，如果 `cnt` **严格大于** `mid`，（注意我加了着重号的部分“小于等于”、“严格大于”）依然根据抽屉原理，重复元素就应该在区间 `[left, mid]` 里。


说明：下面的算法运行时间肯定不会高，因为这个算法是空间敏感的，「用时间换空间」是反常规做法，大家了解一下即可。

平常大家写算法，一般情况下都是「空间换时间」。


**参考代码 1**：

```Java []
public class Solution {

    public int findDuplicate(int[] nums) {
        int len = nums.length;
        int left = 1;
        int right = len - 1;
        while (left < right) {
            // 在 Java 里可以这么用，当 left + right 溢出的时候，无符号右移保证结果依然正确
            int mid = (left + right) >>> 1;
            
            int cnt = 0;
            for (int num : nums) {
                if (num <= mid) {
                    cnt += 1;
                }
            }

            // 根据抽屉原理，小于等于 4 的个数如果严格大于 4 个
            // 此时重复元素一定出现在 [1, 4] 区间里

            if (cnt > mid) {
                // 重复元素位于区间 [left, mid]
                right = mid;
            } else {
                // if 分析正确了以后，else 搜索的区间就是 if 的反面
                // [mid + 1, right]
                left = mid + 1;
            }
        }
        return left;
    }
}
```
```Python []
from typing import List


class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        size = len(nums)
        left = 1
        right = size - 1

        while left < right:
            mid = left + (right - left) // 2

            cnt = 0
            for num in nums:
                if num <= mid:
                    cnt += 1
            # 根据抽屉原理，小于等于 4 的数的个数如果严格大于 4 个，
            # 此时重复元素一定出现在 [1, 4] 区间里

            if cnt > mid:
                # 重复的元素一定出现在 [left, mid] 区间里
                right = mid
            else:
                # if 分析正确了以后，else 搜索的区间就是 if 的反面
                # [mid + 1, right]
                left = mid + 1
        return left
```
```C++ []
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        int len = nums.size();
        int left = 1;
        int right = len - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            int cnt = 0;
            for (int num:nums) {
                if (num <= mid) {
                    cnt++;
                }
            }

            // 根据抽屉原理，小于等于 4 的数的个数如果严格大于 4 个，
            // 此时重复元素一定出现在 [1, 4] 区间里

            if (cnt > mid) {
                // 重复的元素一定出现在 [left, mid] 区间里
                right = mid;
            } else {
                // if 分析正确了以后，else 搜索的区间就是 if 的反面
                // [mid + 1, right]
                // 注意：此时需要调整中位数的取法为上取整
                left = mid + 1;
            }
        }
        return left;
    }
};
```

**复杂度分析：**

+ 时间复杂度：$O(N \log N)$，二分法的时间复杂度为 $O(\log N)$，在二分法的内部，执行了一次 `for` 循环，时间复杂度为 $O(N)$，故时间复杂度为 $O(N \log N)$。
+ 空间复杂度：$O(1)$，使用了一个 `cnt` 变量，因此空间复杂度为 $O(1)$。

下面这一版写法有一点点小的不同。本质上与参考代码 1 没有区别，只是在一些边界的地方，供大家参考。

思路 2：（如果觉得下面的描述很拗口的话，举几个具体的例子，就很清楚了。）

先猜一个数（有效范围 `[left, right]`里的中间数 `mid`），然后统计原始数组中**严格小于**这个中间数的元素的个数 `cnt`，如果 `cnt` **大于等于** `mid`，（注意我加了着重号的部分“严格小于”、“大于等于”）依然根据抽屉原理，重复元素就应该在区间 `[left, mid - 1]` 里。


**参考代码 2**：

```Java []
public class Solution {

    public int findDuplicate(int[] nums) {
        int len = nums.length;
        int left = 1;
        int right = len - 1;
        while (left < right) {
            // 在 Java 里可以这么用，当 left + right 溢出的时候，无符号右移保证结果依然正确
            int mid = (left + right + 1) >>> 1;

            int cnt = 0;
            for (int num : nums) {
                if (num < mid) {
                    cnt += 1;
                }
            }

            // 根据抽屉原理，严格小于 4 的数的个数如果大于等于 4 个，
            // 此时重复元素一定出现在 [1, 3] 区间里

            if (cnt >= mid) {
                // 重复的元素一定出现在 [left, mid - 1] 区间里
                right = mid - 1;
            } else {
                // if 分析正确了以后，else 搜索的区间就是 if 的反面
                // [mid, right]
                // 注意：此时需要调整中位数的取法为上取整
                left = mid;
            }
        }
        return left;
    }
}
```
```Python []
from typing import List


class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        size = len(nums)
        left = 1
        right = size - 1

        while left < right:
            mid = left + (right - left + 1) // 2

            cnt = 0
            for num in nums:
                if num < mid:
                    cnt += 1
            # 根据抽屉原理，严格小于 4 的数的个数如果大于等于 4 个，
            # 此时重复元素一定出现在 [1, 3] 区间里

            if cnt >= mid:
                # 重复的元素一定出现在 [left, mid - 1] 区间里
                # 那么重复的数一定位于 1、2、3
                right = mid - 1
            else:
                # if 分析正确了以后，else 搜索的区间就是 if 的反面
                # [mid, right]
                # 注意：此时需要调整中位数的取法为上取整
                left = mid
        return left
```
```C++ []
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        int len = nums.size();
        int left = 1;
        int right = len - 1;

        while (left < right) {
            int mid = left + (right - left + 1) / 2;

            int cnt = 0;
            for (int num:nums) {
                if (num < mid) {
                    cnt++;
                }
            }

            // 根据抽屉原理，严格小于 4 的数的个数如果大于等于 4 个，
            // 此时重复元素一定出现在 [1, 3] 区间里

            if (cnt >= mid) {
                // 重复的元素一定出现在 [left, mid - 1] 区间里
                right = mid - 1;
            } else {
                // if 分析正确了以后，else 搜索的区间就是 if 的反面
                // [mid, right]
                // 注意：此时需要调整中位数的取法为上取整
                left = mid;
            }
        }
        return left;
    }
};
```

**复杂度分析**：（同上）
