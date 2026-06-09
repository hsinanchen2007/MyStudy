
用双指针实现滑动窗口，维护哈希表记录窗口中的字符和出现次数，持续更新保证窗口中不同字符数量不超过k。

虽然双重循环但是时间复杂度O(n)，每个字符最多被放进窗口一次和从窗口中拿出一次。    
<br>


```cpp
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {        
        int ans = 0;
        
        unordered_map<char, int> map;     // 存每个字符和在窗口中出现的次数
        int length = s.length();
        int i = 0, j = 0;
        
        for(int j = 0; j < length; j++){
            map[s[j]]++;
            if(map.size() > k){           // 当不同字符超出k时       
                while(map.size() > k){    // i持续跟进，直到窗口中不同字符数量回到k为止
                    char c = s[i];
                    map[c]--;
                    if(map[c] == 0)
                        map.erase(c);
                    i++;
                }
            }
            ans = max(ans, j - i + 1);    // 更新答案
        }
        return ans;
    }
};
```