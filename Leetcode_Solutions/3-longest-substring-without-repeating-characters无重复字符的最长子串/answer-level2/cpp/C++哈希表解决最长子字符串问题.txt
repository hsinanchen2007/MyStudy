### 解题思路
此处撰写解题思路
此题利用 “滑动窗口”的思想：
定义一个哈希表来存放不重复的字符（模拟一个队列），将字符串中的每一个字符依次加进去，当遇到和哈希表中字符重复的时候，就“滑动窗口”，将排在前面的挤掉，直到没有重复的字符。
### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int size = s.size();
        if(size == 0) return 0; //空字符串
        unordered_set<char> ch;
        int maxStr = 0; //记录最后的结果（每次更新最大值）
        int left = 0;
        for(int i = 0; i < size; i++)
        {
            while(ch.find(s[i]) != ch.end()) //滑动窗口
            {
                ch.erase(s[left]);
                left++;
            }
            ch.insert(s[i]); //加进来新的字符
            maxStr = max(maxStr, i-left+1); //比较新的字符串长度          
        }
        return maxStr;       
    }
};
```