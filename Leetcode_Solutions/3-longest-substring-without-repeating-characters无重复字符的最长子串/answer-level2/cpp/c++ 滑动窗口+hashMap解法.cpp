
滑动窗口是一个对连续序列作用的抽象概念，可以用两个数组下标值 left, i 划分出左右区间。
滑动窗口区间内的值不能有重复，可以用hash map来存储（但如果字符有限制条件--如计算机的asiic字符只有256个，可以用固定长度的数组等来表示）。键为字符本身，值为字符所在下标位置。
left, i 初值为0，滑动窗口从左往右滑动，i递增.
left更新条件：i 在滑动窗口(hash map)中出现过，则left往右移，更新到该字符出现过的前一位置，由于left不可以再往左滑动，所以left = max(left, map[i])。

```C++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        unordered_map<char, int> maps;
        int longest = 0;
        int left = 0;
        for(int i = 0; i < len; i++){
            auto it = maps.find(s[i]);
            if( it != maps.end()){ // map里有该键值
                left = max(left, it->second);
            }
            longest = max(longest, i + 1 - left);
            maps.insert_or_assign(s[i], i + 1);
        }
        return longest;
    }
};
```