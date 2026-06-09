### 代码

```cpp
// 暴力法，借助集合实现，空间复杂度O(n)，时间复杂度O(n^2)
// 笔记：string s; 是可以直接通过s[i]访问字符串的第i个字符的
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0)
            return 0;
        else if(s.length() == 1)
            return 1;
        
        int maxLength = 0;
        int startPos = 0;
        unordered_map<char, int> hashMap;
        while(startPos < s.length()) {
            for(int j=startPos; j<s.length(); j++) {
                if(hashMap.find(s[j]) != hashMap.end()) {
                    maxLength = maxLength >= hashMap.size() ? maxLength : hashMap.size();
                    startPos = hashMap[s[j]] + 1;
                    hashMap.clear();
                    break;
                }
                else {
                    hashMap[s[j]] = j;
                }
            }
        }

        return maxLength;
    }
};

// 解法：滑动窗口 + 哈希表
// 时间复杂度O(n)、空间复杂度O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0)
            return 0;
        else if(s.length() == 1)
            return 1;
        
        int maxLength = 0;
        unordered_map<char, int> hashMap;
        for(int i=0, j=0; j<s.length(); j++)
        {
            // s[j]在哈希表中，改滑动窗口的起点
            if(hashMap.find(s[j]) != hashMap.end() && hashMap[s[j]] >= i) {
                i = hashMap[s[j]] + 1;
            }
            hashMap[s[j]] = j;
            maxLength = maxLength >= (j - i + 1) ? maxLength : (j - i + 1);
        }
        return maxLength;
    }
};
```