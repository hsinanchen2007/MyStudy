### 解题思路
1. 使用两个map，mp1和mp2。一个存目标字符串s1的计数，另一个存窗口中字符串的计数。
2. 这里使用一个变量match来判断mp2中目标对字符串的计数和mp1是否相同
3. 首先初始化mp2，之后滑动窗口，当窗口滑动到某个位置时，mp2对该窗口字符的计数会和mp1对目标字符串的计数相同(此时match的值刚好和mp1的大小相等)
4. 如果存在使3.成立的窗口，则返回true，否则返回false
5. **代码易懂，有解释**

### 代码

```cpp
class Solution {
public:
    // 将s1每个字符的计数存进mp1
    unordered_map<char, int> mp1;
    // 当前窗口每个字符的计数存进mp2
    unordered_map<char, int> mp2;

    bool checkInclusion(string s1, string s2) {
        // match的值和mp1的size相同时则找到该子串，返回true
        int match = 0;

        //初始化mp1
        for(int i=0;i<s1.size();i++){
            char c = s1[i];
            mp1[c] ++;
        }

        //固定left和right大小，right-left 为s1的长度，即窗口长度为s1的长度
        int len = s1.size();
        int left = 0, right = left+len-1;
        
        //初始化mp2
        while(left < s2.size() && mp1.find(s2[left]) == mp1.end()){
            left ++;
            right ++;
        }
        if(right >= s2.size()) return false;
        for(int i=left;i<=right;i++){
            mp2[s2[i]]++;
            if(mp1.find(s2[i]) != mp1.end()){
                if(mp1[s2[i]] == mp2[s2[i]]) match++;
            }
        }
        if(match == mp1.size()) return true;

        //滑动窗口
        while(right+1 < s2.size()){
            //将left右移，删除窗口第一个值
            char c1 = s2[left++];
            mp2[c1] --;
            if(mp1.find(c1) != mp1.end()){
                // 这里要特别小心，因为有可能之前就是 mp2[c1] < mp1[c1]
                // 如果写成 if(mp2[c1] < mp1[c1]) match --;就是错的
                if( mp2[c1]+1 == mp1[c1] && mp2[c1] < mp1[c1]) match --;
            }
            //将right右移，将值加入到窗口
            char c2 = s2[++right];
            mp2[c2] ++;
            if(mp1.find(c2) != mp1.end()){
                if(mp2[c2] == mp1[c2]) match ++;
            }
            if(match == mp1.size()) return true;
        }
        return false;
    }
};
```