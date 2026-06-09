### 解题思路
用时 16 ms   内存 11MB
这个题目里面字符串p的长度是固定的，所以滑动窗口的长度是固定的；
题目已经限定了全是小写字母，可以开两个数组，分别记录p字符串中出现的各字母数量和当前滑动窗口中出现的各字母数量；


### 代码

```cpp
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int len = p.size(),last = s.size();// len 为p字符串的长度
        if (last < len) {
            return ans;
        }

        vector<int> needs(26,0);
        vector<int> window(26,0);
        for (char c : p) needs[c-'a']++;

        int r = 0;//滑动窗口的右端


        while(r < last){
            if (r < len ){//一开始滑动窗口还没覆盖到p字符串的长度
                window[s[r]-'a']++;
                if (r == len-1 && needs == window){
                    ans.push_back(0);
                }
            } else{
                int l = r - len;//滑动窗口的左端
                window[s[r]-'a']++;
                window[s[l]-'a']--;
                if (needs == window) {
                    ans.push_back(l + 1);
                }
            }
            r++;
        }
        return ans;
    }
};
```