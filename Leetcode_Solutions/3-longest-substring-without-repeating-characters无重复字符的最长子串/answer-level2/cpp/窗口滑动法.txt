### 解题思路
定位两个指针start和end至初始位置
end向右移动一个单位，判断s[end]是否存在于s[start]至s[end]中，若不存在，则end++ length++
若存在，将start更新至该重复字符的后一位(start = index + 1)，长度为(end-start)+1

#### 复杂度
时间复杂度 O(n^2)

### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start(0), end(0), length(0), result(0);
        int sSize = s.length();
        while (end<sSize) {
            char tempChar = s[end];
            for (int index=start;index<end;index++) {
                if (tempChar == s[index]) {
                    start = index + 1;
                    length = end - start;
                    break;
                }
            }
            end++;
            length++;
            result = max (result,length);
        }
        return result;
    }
};
```