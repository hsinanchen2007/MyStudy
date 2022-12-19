### 算法简介
首先用动态规划求解所有从位置$i$开始，长度为`words[0].size()`的子串的哈希值。
然后再求出所有`words`的哈希值，使用`unordered_map<ULL,int>`存储起来。
最后采用滑动窗口在每一个位置进行匹配，进入窗口的部分将对应的hash值减少1，出窗口的部分将对应的hash值加1，如果hash表为空代表滑动窗口内的值可以用`words`的组合进行表示。
每一个位置只会匹配一次，所以时间复杂度是$O(n+m)$的，其中n为源串长度，m为`words`总长度。

### tips
写的时候遇到一个小坑，判断左端指针是否到达字符串结尾的时候写了`j+w-1<s.size()`，然而左端有可能是负数，右端是无符号数，有符号和无符号进行比较的时候会出大问题，所以后面加上了类型转换，成功过掉。

### 代码
```
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(words.empty()) return vector<int>();
        
        int w = words[0].size();
        
        typedef unsigned long long ULL;
        
        static ULL f[100010];
        
        const int P = 131;
        ULL base = 1;
        f[0] = 0;
        for(int i = 0 ; i < w ; i++) {
            base *= P;
            f[0] *= P;
            f[0] += s[i];
        }

        for(int i = 1 ; i+w-1 < s.size() ; i++)
            f[i] = f[i-1]*P-s[i-1]*base+s[i+w-1];

        unordered_map<ULL,int> h;
        
        for(auto x:words) {
            ULL t = 0;
            for(auto y:x) {
                t *= P;
                t += y;
            }
            h[t] ++;
        }
        
        vector<int> ans;
        for(int k = 0 ; k < w ; k++) {
            for(int i = k, j = i-(int)(words.size()*w) ; j+w-1<(int)s.size() ; i+=w,j+=w){
                if(i+w-1<s.size() && --h[f[i]]==0) h.erase(f[i]);
                if(j>=0 && ++h[f[j]]==0) h.erase(f[j]);
                if(h.empty()) ans.push_back(j+w);
            }
        }
        return ans;
    }
};
```