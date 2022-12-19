### 解题思路
解题的关键点是对重复出现的字符的处理，定义数组index来保存字符上次出现时的下标， 每出现重复字符，更新一下下标位置index[i]，更新一下最长字符的长度maxLen和当前非重复字符串的长度len。
需要注意：并不是出现重复字符就要更新len,有可能重复字符对当前的len没有影响，即i - index[s[i]] > len，如"tmmzuxt" t的出现就不用更新len的值。代码如下

### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int index[128] = {0};   //记录字母上一次出现的下标
        int hashmap[128] = {0};     //记录字符出现的次数
        int maxLen = 0, len = 0;    //保存每一次循环的长度值
        for (int i = 0; i < s.length(); i++){
            hashmap[s[i]]++;
            if(hashmap[s[i]] == 1) {
                index[s[i]] = i;     //记录s[i]上一次出现的下标
                len++;
                maxLen = max(maxLen, len);
            }
            
            else if(hashmap[s[i]] == 2){
                int len1 = i - index[s[i]];     //相同字母的距离
                index[s[i]] = i;    //更新下标
                hashmap[s[i]] = 1;
                maxLen = max(maxLen, len);
                if(len1 <= len)          //字符和上一个字符的距离影响最长子串的增加 "abcabcbb" b
                    len = len1;
                else {                  //字符和上一个字符的距离不影响最长子串的增加 "tmmzuxt" t
                    len++;
                    maxLen = max(maxLen, len);
                }
            }
        }
        return maxLen;
    }
};
```