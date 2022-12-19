用一个 cur 变量记录前缀和，当大于8时，cur++, 小于8时，cur--。
由于从前向后遍历，当 cur > 0时，说明从开始到现在满足条件，时间必然是最长的，直接更新 res = i + 1。
当 cur <= 0时呢？关键来了
这里用一个 字典记录所有 cur <= 0的最小下标，所谓最小，就是后面如果再碰到了同样的 cur，不需要更新，如果没有碰到过，则把这个下标记录下来。
然后用 cur - 1 去字典里找，如果找到了下标j，那么就说明从0到 j 的前缀和是 cur-1，而从0到 i 的前缀和是 cur，那么显然从 j 到 i的和是（cur - (cur - 1)） = 1 > 0，也就是说从 j+1到 i 的表现肯定是满足的，并且由于 j 是 cur-1中最小的，所以 i-j 是最大的。
此时再跟 res 比较看是否需要更新。

上面为什么只需要查找 cur-1？因为满足条件的前缀和只能是小于等于cur-1的，也就是说其实也可以查找 cur-2,cur-3...，但是，cur-2的下标一定不可能在 cur-1的下标左边。使用反证法，前提是cur-1代表的是最小下标，那么如果 cur-2在 cur-1左边，而cur-2的左边一定还会有 cur-1出现（cur值是从0开始的），这就和最小下标的前提矛盾了。
那么问题又来了，如果 cur-1不存在，是否要查找 cur-2,cur-3...呢？
也不需要，思路跟上面是一样的，如果 cur-1不存在，cur-2,cur-3...一定也不存在。举个例子，不可能从0跳到-2，-3，而中间没有-1。

通过上面有理有据的分析，下面的代码就很简单了。

```c++
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();

        unordered_map<int, int> count;
        int cur = 0;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (hours[i] > 8) {
                cur++;
            } else {
                cur--;
            }
            if (cur > 0) res = i + 1;
            else {
                if (count.count(cur-1) > 0) res = max(res, i - count[cur-1]);
                if (count.count(cur) < 1) count[cur] = i;
            }
        }
        return res;

    }
};
```