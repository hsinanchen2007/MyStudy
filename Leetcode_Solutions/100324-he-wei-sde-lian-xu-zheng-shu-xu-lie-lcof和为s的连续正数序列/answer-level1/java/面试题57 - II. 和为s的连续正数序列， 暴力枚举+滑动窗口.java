### 解题思路
N为枚举的边界，因为最少`2`个连续整数的和为`target`，所以N最大为$\frac{target}{2} + 1$，
最大枚举区间为 $[\frac{target}{2}, \frac{target}{2}+1]$

优化：
1、以 i 为起点的连续区间最多只有一个满足 $\sum_{k=i}^j k = target$

#### 进步一优化暴力算法：滑动窗口

滑动窗口的重要性质是：窗口的**左边界和右边界永远只能向右移动，而不能向左移动**。这是为了保证滑动窗口的时间复杂度是 $O(n)$。如果左右边界向左移动的话，这叫做“回溯”，算法的时间复杂度就可能不止 $O(n)$。

在这道题中，我们关注的是**滑动窗口中所有数的和**。
* 当滑动窗口的**右边界**向右移动时，也就是 `j = j + 1`，窗口中多了一个数字 `j`，窗口的和也就要加上 `j`。
* 当滑动窗口的**左边界**向右移动时，也就是 `i = i + 1`，窗口中少了一个数字 `i`，窗口的和也就要减去 `i`。

滑动窗口只有右边界向右移动（扩大窗口） 和 左边界向右移动（缩小窗口） 两个操作，所以实际上非常简单。

>作者：nettee
>链接：https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/solution/shi-yao-shi-hua-dong-chuang-kou-yi-ji-ru-he-yong-h/
>来源：力扣（LeetCode）
>著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


### 代码（暴力枚举）

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        int N = target/2 + 1;
        List<int[]> ans = new ArrayList<int[]>();

        for (int i = 1; i < N; ++i) {
            int sum = i;
            for (int j = i+1; j <= N; ++j) {
                sum += j;
                if (sum > target) break;
                if (sum == target) {
                    //System.out.println("new ans; [" + i + ", " + j + "]");
                    int[] curAns = new int[j-i+1];
                    for (int k = 0, val=i; val<=j; ++k, ++val) {
                        curAns[k] = val;
                    }
                    ans.add(curAns);

                    break;
                }
            }
        }
        return ans.toArray(new int[ans.size()][]);
    }
}
```

### 代码（滑动窗口）
```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        int N = target/2;
        List<int[]> ans = new ArrayList<int[]>();

        int l = 1, r = 2;
        int sum = l + r;
        while (l <= N) {
            if (sum < target) {
                sum += ++r;
            } else if (sum > target) {
                sum -= l++;
            } else {
                int[] curAns = new int[r-l+1];
                for (int k = 0, val=l; val<=r; ++k, ++val) {
                    curAns[k] = val;
                }
                ans.add(curAns);
                sum -= l++;
            }
        }
        return ans.toArray(new int[ans.size()][]);
    }
}
```