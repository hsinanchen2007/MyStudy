### 解题思路
和今天的打卡题【面试题57 - II. 和为s的连续正数序列】如出一辙
不同的是多了两个统计项：hashmap和count
使用unordered_map<char, int> filter来统计当前窗口内每个元素的个数
使用count统计窗口数目大于1的字符个数
right向右滑动，如果count==0，计算窗口大小，如果大于当前result，则替换result
如果fliter[s[right]]++ 后大于1 则count+1
如果count > 0时，left向右滑动，如果filter[s[left]]--后等于1（必须是等于1，不是小于等于1）， 则count--
count减小到0时，也要计算窗口大小，对比result。

### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, count = 0, result = 0;
        unordered_map<char, int> filter;
        while (right < s.size()) {
            if (++filter[s[right]] > 1) count ++;
            if (!count) result = max(result, right-left+1);
            while (count) {
                if (--filter[s[left]] == 1) count --;
                left ++; // left++ 必须处于这个位置，上一句需要更新前的left，下一句需要更新后的left
                if (!count) result = max(result, right-left+1);
            }
            right ++;
        }
        return result;
    }
};
```