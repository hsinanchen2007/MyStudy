### 解题思路
本题通过直接判断两个哈希表是不是相等来判断是不是找到了符合要求的字符串。
判断两个哈希表是不是相等的时候要注意：数据对的第二个值itr->second为0并不意味着不存在；
所以本题中在对哈希表act录入值的时候有一个前提：这个key值存在于哈希表ref中。这样做保证了连个表的size相同。
### 头文件
```
#include <vector>
#include <string>
#include <map>
```


### 代码

```cpp
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int len1 = s.size();
        int len2 = p.size();
        if (len1 < len2)
            return {};
        vector<int> ans;
        int left=0, right=0;
        map<char,int> ref,act;
        //将p映射到哈希表ref中
        for (char c:p) 
            ref[c]++;     
        //因为本题中滑动窗口的大小是固定的，所以一开始让right先走窗口大小的长度。
        while (right < len2) { 
            if (ref.count(s[right])) 
                act[s[right]]++;
            right++;
        }
        if (act == ref) 
            ans.push_back(0);
        //实现窗口滑动,找到符合要求的字符串起始位置。
        while (right < len1) {          
            if (ref.count(s[right])) 
                act[s[right]]++;
            if (ref.count(s[left])) 
                act[s[left]]--;  
            right++;
            left++;
            if (act == ref)
                ans.push_back(left);
        }
        return ans;
    }
};
```