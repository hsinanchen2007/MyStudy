**分析**

假设火柴的长度分别为 `[1,1,1,1,2,2,2,2,3,3,3,3]`，它们的和为 `24`，因此对应正方形的变成为 `6`。如下图所示，我们给正方形的每一条边都放上长度为 `[1,2,3]` 的火柴，这是一种可行的方法。

![bla](https://pic.leetcode-cn.com/Figures/473/473_Matchsticks-In-Square-Diag-1.png){:width=400px;}

因此，对于给定的若干根火柴，我们需要：

- 将它们分成四组，每一根火柴恰好属于其中的一组；

- 每一组火柴的长度之和都相同，等于所有火柴长度之和的四分之一。

#### 方法一：深度优先搜索

我们可以使用深度优先搜索枚举出所有的分组情况，并对于每一种情况，判断是否满足上述的两个条件。

我们依次对每一根火柴进行搜索，当搜索到第 `i` 根火柴时，我们可以把它放到四组中的任意一种。对于每一种放置方法，我们继续对第 `i + 1` 根火柴进行递归搜索。当我们搜索完全部的 `N` 根火柴后，再判断每一组火柴的长度之和是否都相同。

```Java [sol1]
import java.util.HashMap;
import java.util.Collections;

class Solution {
    public List<Integer> nums;
    public int[] sums;
    public int possibleSquareSide;

    public Solution() {
        this.sums = new int[4];
    }

    // Depth First Search function.
    public boolean dfs(int index) {

        // If we have exhausted all our matchsticks, check if all sides of the square are of equal length
        if (index == this.nums.size()) {
            return sums[0] == sums[1] && sums[1] == sums[2] && sums[2] == sums[3];
        }

        // Get current matchstick.
        int element = this.nums.get(index);

        // Try adding it to each of the 4 sides (if possible)
        for(int i = 0; i < 4; i++) {
            if (this.sums[i] + element <= this.possibleSquareSide) {
                this.sums[i] += element;
                if (this.dfs(index + 1)) {
                    return true;
                }
                this.sums[i] -= element;
            }
        }

        return false;
    }

    public boolean makesquare(int[] nums) {
        // Empty matchsticks.
        if (nums == null || nums.length == 0) {
            return false;
        }

        // Find the perimeter of the square (if at all possible)
        int L = nums.length;
        int perimeter = 0;
        for(int i = 0; i < L; i++) {
            perimeter += nums[i];
        }

        this.possibleSquareSide =  perimeter / 4;
        if (this.possibleSquareSide * 4 != perimeter) {
            return false;
        }

        // Convert the array of primitive int to ArrayList (for sorting).
        this.nums = Arrays.stream(nums).boxed().collect(Collectors.toList());
        Collections.sort(this.nums, Collections.reverseOrder());
        return this.dfs(0);
    }
}
```

```Python [sol1]
def makesquare(self, nums):
    """
    :type nums: List[int]
    :rtype: bool
    """

    # If there are no matchsticks, then we can't form any square
    if not nums:
        return False

    # Number of matchsticks we have
    L = len(nums)

    # Perimeter of our square (if one can be formed)
    perimeter = sum(nums)

    # Possible side of our square.
    possible_side =  perimeter // 4

    # If the perimeter can be equally split into 4 parts (and hence 4 sides, then we move on).
    if possible_side * 4 != perimeter:
        return False

    # Reverse sort the matchsticks because we want to consider the biggest one first.
    nums.sort(reverse=True)

    # This array represents the 4 sides and their current lengths
    sums = [0 for _ in range(4)]

    # Our recursive dfs function.
    def dfs(index):

        # If we reach the end of matchsticks array, we check if the square was formed or not
        if index == L:
            # If 3 equal sides were formed, 4th will be the same as these three and answer should be True in that case.
            return sums[0] == sums[1] == sums[2] == possible_side

        # The current matchstick can belong to any of the 4 sides (provided their remaining lenghts are >= the size of the current matchstick)
        for i in range(4):
            # If this matchstick can fir in the space left for the current side
            if sums[i] + nums[index] <= possible_side:
                # Recurse
                sums[i] += nums[index]
                if dfs(index + 1):
                    return True
                # Revert the effects of recursion because we no longer need them for other recursions.
                sums[i] -= nums[index]
        return False        
    return dfs(0)
```

**复杂度分析**

* 时间复杂度：$O(4^N)$，其中 $N$ 是火柴的数量。在进行搜索之前，我们可以将火柴的长度从大到小进行排序，方便我们先搜索较长的火柴。这样做的目的是对搜索进行剪枝，例如当火柴的长度为 `[4,4,4,8]` 时，每条边的长度为 `5`，如果我们先搜索长度为 `8` 的火柴，就可以发现它无法被放在任意一组中，因此直接退出搜索返回 `False`。

* 空间复杂度：$O(N)$。

#### 方法二：动态规划 + 状态压缩

假设已经有长度分别为 `[3,3,4,4,5,5]` 的火柴被放入了某些组中，并且每条边的长度为 `8`。这些火柴的放置情况可能有很多种，下面给出了几个例子：

```
(4, 4), (3, 5), (3, 5) -----------> 已经有 3 个组被放满
(3, 4), (3, 5), (4), (5) ---------> 没有组被放满
(3, 3), (4, 4), (5), (5) ---------> 已经有 1 个组被放满
```

这些例子说明，如果我们只知道当前有哪些火柴被放入了组中，我们是无法还原出每根火柴具体被放入哪个组的，因此我们对火柴的分组作出规定：我们规定这些火柴必须装满尽量多的组，并且不满的组最多只有一个。例如 `[3,3,4,4,5,5]` 此时就会代表 “装满了 `3` 个组，并且没有不满的组” 这个状态。

![bla](https://pic.leetcode-cn.com/Figures/473/473_Matchsticks-In-Square-Diag-2.png){:width=350px;}

这样的规定看上去很不合理，并且可能会漏掉一些情况。但仔细想想，假设 `N` 根火柴可以组成一个正方形，这些火柴从第一条边到第四条边，从左到右依次编号为 `a1, a2, ..., aN`，那么我们可以从 `[a1]` 的情况推导到 `[a1, a2]` 的情况，从 `[a1, a2]` 的情况推导到 `[a1, a2, a3]` 的情况，也就是说，对于满足条件的分组方法，我们一定可以在动态规划中，通过子问题得到正确的解。

下面给出了动态规划的伪代码：

```
let square_side = sum(matchsticks) / 4
func recurse(matchsticks_used, sides_formed) {
    if sides_formed == 4, then {
        Square Formed!!
    }
    for match in matchsticks available, do {
          add match to matchsticks_used
          let result = recurse(matchsticks_used, sides_formed)
          if result == True, then {
              return True
          }
          remove match from matchsticks_used
    }
    return False
}
```

我们可以使用长度为 `N` 的二进制来表示动态规划中的每一个状态，如果二进制的第 `k` 位为 `1`，那么当前状态包含第 `k` 根火柴，否则不包含第 `k` 根火柴。


```Java [sol2]
import java.util.HashMap;
import javafx.util.Pair;

class Solution {

    // The memoization cache to be used during recursion.
    public HashMap<Pair<Integer, Integer>, Boolean> memo;

    // Array containing our matchsticks.
    public int[] nums;

    // Possible side of our square depending on the total sum of all the matchsticks. 
    public int possibleSquareSide;

    // Default constructor to initialise our memo cache.
    public Solution() {
        this.memo = new HashMap<Pair<Integer, Integer>, Boolean>();
    }

    // Main DP function.
    public boolean recurse(Integer mask, Integer sidesDone) {
        int total = 0;
        int L = this.nums.length;

        // The memo key for this recursion
        Pair<Integer, Integer> memoKey = new Pair(mask, sidesDone);

        // Find out the sum of matchsticks used till now.
        for(int i = L - 1; i >= 0; i--) {
            if ((mask&(1 << i)) == 0) {
                total += this.nums[L - 1 - i];
            }
        }

        // If the sum if divisible by our square's side, then we increment our number of complete sides formed variable.
        if (total > 0 && total % this.possibleSquareSide == 0) {
            sidesDone++;
        }

        // Base case.
        if (sidesDone == 3) {
            return true;
        }


        // Return precomputed results
        if (this.memo.containsKey(memoKey)) {
            return this.memo.get(memoKey);
        }

        boolean ans = false;
        int c = total / this.possibleSquareSide;

        // Remaining vlength in the current partially formed side.
        int rem = this.possibleSquareSide * (c + 1) - total;

        // Try out all remaining options (that are valid)
        for(int i = L - 1; i >= 0; i--) {
            if (this.nums[L - 1 - i] <= rem && (mask&(1 << i)) > 0) {
                if (this.recurse(mask ^ (1 << i), sidesDone)) {
                    ans = true;
                    break;
                }
            }
        }

        // Cache the computed results.
        this.memo.put(memoKey, ans);
        return ans;
    }

    public boolean makesquare(int[] nums) {

        // Empty matchsticks.
        if (nums == null || nums.length == 0) {
            return false;
        }

        // Find the perimeter of the square (if at all possible)
        int L = nums.length;
        int perimeter = 0;
        for(int i = 0; i < L; i++) {
            perimeter += nums[i];
        }

        int possibleSquareSide =  perimeter / 4;
        if (possibleSquareSide * 4 != perimeter) {
            return false;
        }

        this.nums = nums;
        this.possibleSquareSide = possibleSquareSide;
        return this.recurse((1 << L) - 1, 0);
    }
}
```

```Python [sol2]
def makesquare(self, nums):
    """
    :type nums: List[int]
    :rtype: bool
    """

    # If there are no matchsticks, then we can't form any square.
    if not nums:
        return False

    # Number of matchsticks
    L = len(nums)

    # Possible perimeter of our square
    perimeter = sum(nums)

    # Possible side of our square from the given matchsticks
    possible_side =  perimeter // 4

    # If the perimeter isn't equally divisible among 4 sides, return False.
    if possible_side * 4 != perimeter:
        return False

    # Memoization cache for the dynamic programming solution.
    memo = {}

    # mask and the sides_done define the state of our recursion.
    def recurse(mask, sides_done):

        # This will calculate the total sum of matchsticks used till now using the bits of the mask.
        total = 0
        for i in range(L - 1, -1, -1):
            if not (mask & (1 << i)):
                total += nums[L - 1 - i]

        # If some of the matchsticks have been used and the sum is divisible by our square's side, then we increment the number of sides completed.
        if total > 0 and total % possible_side == 0:
            sides_done += 1

        # If we were successfully able to form 3 sides, return True
        if sides_done == 3:
            return True

        # If this recursion state has already been calculated, just return the stored value.
        if (mask, sides_done) in memo:
            return memo[(mask, sides_done)]

        # Common variable to store answer from all possible further recursions from this step.
        ans = False

        # rem stores available space in the current side (incomplete).
        c = int(total / possible_side)
        rem = possible_side * (c + 1) - total

        # Iterate over all the matchsticks
        for i in range(L - 1, -1, -1):

            # If the current one can fit in the remaining space of the side and it hasn't already been taken, then try it out
            if nums[L - 1 - i] <= rem and mask&(1 << i):

                # If the recursion after considering this matchstick gives a True result, just break. No need to look any further.
                # mask ^ (1 << i) makes the i^th from the right, 0 making it unavailable in future recursions.
                if recurse(mask ^ (1 << i), sides_done):
                    ans = True
                    break
        # cache the result for the current recursion state.            
        memo[(mask, sides_done)] = ans
        return ans

    # recurse with the initial mask with all matchsticks available.
    return recurse((1 << L) - 1, 0)
```

**复杂度分析**

* 时间复杂度：$O(N * 2^N)$，其中 $N$ 是火柴的数量。

* 空间复杂度：$O(N + 2^N)$。