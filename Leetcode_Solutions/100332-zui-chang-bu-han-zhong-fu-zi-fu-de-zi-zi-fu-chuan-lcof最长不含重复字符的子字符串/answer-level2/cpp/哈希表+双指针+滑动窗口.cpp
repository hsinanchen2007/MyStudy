### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0)return 0;
        //哈希表+双指针+滑动窗口
        unordered_map<char, int> countMap;  //用于存储当前子串每个字符出现的次数
        //定义双指针
        int head, tail;
        head = tail = 0;  //head和tail初始都指向下标0
        int len = 1;  //最小子串长度必为1
        while(tail < s.size())
        {
            countMap[s[tail]]++;
            if(countMap[s[tail]] == 1)  //tail指针指向的字符在当前子串只出现一次
            {
                if(tail - head + 1 > len)
                    len = tail - head + 1;  //记录当前不重复子串的最大长度
            }  
            else
            {
                //tail指针指向的字符在当前子串不止出现了一次，即head指针指向的正是重复的字符
                //移动head指针，直到tail指针指向的字符出现一次
                while(countMap[s[tail]] > 1)
                {
                    countMap[s[head]]--;
                    ++head;  //这两步是将head指针后移，同时将head指向的字符的出现次数减一
                }
            }
            ++tail;
        }
        return len;
    }
};
```