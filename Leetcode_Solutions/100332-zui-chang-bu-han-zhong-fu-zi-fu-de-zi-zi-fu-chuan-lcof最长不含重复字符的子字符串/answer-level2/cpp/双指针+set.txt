### 解题思路
解题思路： 双指针
双指针之间存放的是最长无重复子串，
指针：left right， right依次像右遍历， 无重复子串保留在set中，
当发现s[right]在set中出现， 则移动left，直到将s[]right]剔除


### 代码
```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size =s.size();
        if (size <= 1) return size;
        int left = 0, right = 0;
        unordered_set<char> set;
        int result =0;
        for(auto i = 0; i < size; i++) {
            if (set.find(s[i]) != set.end()) {
                set.erase(s[left]);
                left ++;
                i--; // 一直 删除left 直到s[right] 不在set出现
            } else {
                set.insert(s[i]);
                right ++;
                result = max(result, right -left);
            }
        } 
        return result;
    }
};
```