### 解题思路
因为题目要求至少序列中至少含有两个数，那么在最外面的for loop里面，终点可以设置为中点，因为两个最中间的值相加，会等于`target`这个值。

然后在外面的循环里面，再加一个循环，不设置terminate state，而是在循环内部通过检测序列里面的值的总和来决定是否要break这个循环，或者把该序列添加到要返回的`list`中，然后再break。

还有要注意的一点，因为我们不知道有多少个序列，也不知道每个序列的大小，所以一开始用`List`来存连续的正数的序列，在需要的时候，再调用`.ToArray()`，来得到一个正数序列`int[]`和正数序列的序列`int[][]`。

执行用时: 1876 ms, 在所有 C# 提交中击败了 11.11% 的用户
内存消耗: 28.4 MB, 在所有 C# 提交中击败了 100.00% 的用户

### 代码

```csharp
public class Solution {
    public int[][] FindContinuousSequence(int target) {
        List<int[]> consecutiveIntList = new List<int[]>();

        int halfOfTarget = target % 2 == 0 ? target / 2 : (target / 2) + 1;
        for (int i = 1; i <= halfOfTarget; i++) {
            List<int> consecutiveInts = new List<int>();
            for (int j = i; true; j++) {
                consecutiveInts.Add(j);
                int currentSum = consecutiveInts.Sum();
                if (currentSum == target && consecutiveInts.Count >= 2) {
                    consecutiveIntList.Add(consecutiveInts.ToArray());
                    break;
                } else if (currentSum > target) {
                    break;
                }
            }
        }

        return consecutiveIntList.ToArray();
    }
}
```