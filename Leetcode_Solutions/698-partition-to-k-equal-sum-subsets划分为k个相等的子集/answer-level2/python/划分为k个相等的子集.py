####  方法一：通过构造子集和进行搜索 
一种方法是模拟构造 `k` 个子集（nums 的不相交子集）。对于 `nums` 中的每个数字，我们将其放入第 `i` 子集检查是否解决了问题。我们可以通过递归搜索来检查是否存在可能性。 

**算法：**
- 首先，我们知道 `k` 个子集的每一个和必须等于 `target = sum(nums) / k`（如果 `target` 不是整数，那么是不符合题目要求的）。 
- 对于 `nums` 中的每个数字，我们可以将其添加到 `k` 个子集中的一个，只要该子集的和不会超过目标值。对于每一个选择，我们都递归地用一个更小的数字进行搜索，以便在nums中考虑。如果我们成功地放置了每个数字，那么我们的搜索就成功了。 
- 一个重要的细节是，通过判断 `if (groups[i] == 0) break;`，我们可以确保每个 `group` 的所有 0 值都出现在数组 `groups` 的末尾。这大大减少了重复的工作——例如，在第一次运行搜索时，我们只进行一次递归调用，而不是 `k` 次。还可以通过跳过 `group[i]` 的重复值来加快速度，但这是不必要的。
- 另一个细节是我们可以对数组 `num` 进行排序，以便我们尝试先放置较大的元素。这种放置元素的方法将更快组合出较小大小的子集。我们还可以适当处理 `nums[i] >= target` 的情况。这些技巧不是解决问题所必需的，但它们在下面的解决方案中给出。

```Python [ ]
class Solution(object):
    def canPartitionKSubsets(self, nums, k):
        target, rem = divmod(sum(nums), k)
        if rem: return False

        def search(groups):
            if not nums: return True
            v = nums.pop()
            for i, group in enumerate(groups):
                if group + v <= target:
                    groups[i] += v
                    if search(groups): return True
                    groups[i] -= v
                if not group: break
            nums.append(v)
            return False

        nums.sort()
        if nums[-1] > target: return False
        while nums and nums[-1] == target:
            nums.pop()
            k -= 1

        return search([0] * k)
```

```Java [ ]
class Solution {
    public boolean search(int[] groups, int row, int[] nums, int target) {
        if (row < 0) return true;
        int v = nums[row--];
        for (int i = 0; i < groups.length; i++) {
            if (groups[i] + v <= target) {
                groups[i] += v;
                if (search(groups, row, nums, target)) return true;
                groups[i] -= v;
            }
            if (groups[i] == 0) break;
        }
        return false;
    }

    public boolean canPartitionKSubsets(int[] nums, int k) {
        int sum = Arrays.stream(nums).sum();
        if (sum % k > 0) return false;
        int target = sum / k;

        Arrays.sort(nums);
        int row = nums.length - 1;
        if (nums[row] > target) return false;
        while (row >= 0 && nums[row] == target) {
            row--;
            k--;
        }
        return search(new int[k], row, nums, target);
    }
}
```


**复杂度分析**

* 时间复杂度：$O(k^{N-k} k!)$。其中 $N$ 指的是 `nums` 的长度。
* 空间复杂度：$O(N)$，递归调用 `search` 所使用的堆栈空间。


####  方法二：动态规划
**算法：**
- 在方法 1 中我们使用了穷举搜索的方法找到答案。
- 若 `nums[i]` 已经被使用了，则将 `used` 设置到第 `i` 位。我们希望是以某种顺序使用 `nums` 中的元素，使得按该顺序分组是有效的。我们通过函数 `search(used, ...)` 知道：我们是否可以适当地划分 `nums[i]` 中未使用的元素？
- 这将取决于未使用元素的总和 `todo`。在组合剩余元素时，`todo` 不能穿越目标的倍数值。例如，如果 `target` 是 `10`，而我们要待组合的元素是 `[6，5，5，4]`，若组合 `6 + 5 = 11` 大于 `10`，那么这种组合是无效的。
- 如果我们可以选择组合的顺序，那么在放置 `5` 之后，我们未使用的元素是 `[4，5，6]`。使用 `6` 将使 `todo` 从 `15` 变为 `9`，这会穿过 `10` 而变成我们不想要的值。但是，我们可以使用 `5`，则 `todo` 从 `15` 变为`10`；而 `10` 是我们的目标值，然后组合 `4` 和 `6`。
- `targ = (todo - 1) % target + 1` 选择了可以使用的最大值，以便不穿越目标的倍数值。            
- `todo` 的状态仅取决于 `used` 的状态，所以想要 `search` 记忆化，我们只需要通过 `used` 进行查找。
- 在下面的代码中，我们提供了自顶向下的动态规划和自下而上的动态规划。

```Python [ ]
class Solution(object):
    def canPartitionKSubsets(self, nums, k):
        target, rem = divmod(sum(nums), k)
        if rem or max(nums) > target: return False

        memo = [None] * (1 << len(nums))
        memo[-1] = True
        def search(used, todo):
            if memo[used] is None:
                targ = (todo - 1) % target + 1
                memo[used] = any(search(used | (1<<i), todo - num)
                                 for i, num in enumerate(nums)
                                 if (used >> i) & 1 == 0 and num <= targ)
            return memo[used]

        return search(0, target * k)
```

```Java [ ]
enum Result { TRUE, FALSE }

class Solution {
    boolean search(int used, int todo, Result[] memo, int[] nums, int target) {
        if (memo[used] == null) {
            memo[used] = Result.FALSE;
            int targ = (todo - 1) % target + 1;
            for (int i = 0; i < nums.length; i++) {
                if ((((used >> i) & 1) == 0) && nums[i] <= targ) {
                    if (search(used | (1<<i), todo - nums[i], memo, nums, target)) {
                        memo[used] = Result.TRUE;
                        break;
                    }
                }
            }
        }
        return memo[used] == Result.TRUE;
    }
    public boolean canPartitionKSubsets(int[] nums, int k) {
        int sum = Arrays.stream(nums).sum();
        if (sum % k > 0) return false;

        Result[] memo = new Result[1 << nums.length];
        memo[(1 << nums.length) - 1] = Result.TRUE;
        return search(0, sum, memo, nums, sum / k);
    }
}
```

```Python [ ]
class Solution(object):
    def canPartitionKSubsets(self, nums, k):
        nums.sort()
        target, rem = divmod(sum(nums), k)
        if rem or nums[-1] > target: return False

        dp = [False] * (1 << len(nums))
        dp[0] = True
        total = [0] * (1 << len(nums))

        for state in xrange(1 << len(nums)):
            if not dp[state]: continue
            for i, num in enumerate(nums):
                future = state | (1 << i)
                if state != future and not dp[future]:
                    if (num <= target - (total[state] % target)):
                        dp[future] = True
                        total[future] = total[state] + num
                    else:
                        break
        return dp[-1]
```

```Java [ ]
class Solution {
    public boolean canPartitionKSubsets(int[] nums, int k) {
        int N = nums.length;
        Arrays.sort(nums);
        int sum = Arrays.stream(nums).sum();
        int target = sum / k;
        if (sum % k > 0 || nums[N - 1] > target) return false;

        boolean[] dp = new boolean[1 << N];
        dp[0] = true;
        int[] total = new int[1 << N];

        for (int state = 0; state < (1 << N); state++) {
            if (!dp[state]) continue;
            for (int i = 0; i < N; i++) {
                int future = state | (1 << i);
                if (state != future && !dp[future]) {
                    if (nums[i] <= target - (total[state] % target)) {
                        dp[future] = true;
                        total[future] = total[state] + nums[i];
                    } else {
                        break;
                    }
                }
            }
        }
        return dp[(1 << N) - 1];
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N * 2^N)$。其中 $N$ 是 `nums` 的长度。`used` 有 $2^N$ 个状态（或自下而上的动态规划中的 `state`），每个状态对 `nums` 执行 `O(N)` 的搜索。
* 空间复杂度：$O(2^N)$，`memo` 使用的空间（或是在自下而上的动态规划中使用的 `dp`，`total` ）。