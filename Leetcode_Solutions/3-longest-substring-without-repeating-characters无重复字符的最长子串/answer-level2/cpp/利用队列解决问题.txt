### 解题思路
此处撰写解题思路
将字符串按顺序压入队列，并检查是否有重复字符，有责删除其及其前面所有字符，期间并统计最大长度
### 代码

```cpp
#include <iostream>
#include <set>
#include <string>
using namespace std;


class Solution {
public:
    static int lengthOfLongestSubstring(const string& s) {
        deque<char> abc_deque;                        //队列
        int max_len = 0;
        for (int i = 0; i < s.size(); i++) {
            int j = 0;
            for (; j < abc_deque.size(); j++) {       //碰到重复字符，删除其及其前面所有字符，然后结束循环
                if (abc_deque.at(j) == s.at(i)) {
                    while (j-- >= 0) {
                        abc_deque.pop_front();
                    }
                    break;
                }
            }
            abc_deque.push_back(s.at(i));
            max_len = max(max_len, static_cast<int>(abc_deque.size()));       //统计最大数
        }
        return max_len;
    }
};
```