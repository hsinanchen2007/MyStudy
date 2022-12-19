### 解题思路
优化后的滑动窗口

### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size(),l=0,m=0;
        if(!n)return 0;
        map<char,int> last_p;
        for(int r=0;r<n;r++){
            if(!last_p.count(s[r])||last_p[s[r]]<l){
                if(m<r-l+1)m=r-l+1;
            }
            else l=last_p[s[r]]+1;
            last_p[s[r]]=r;
        }
        return m;
    }
};
```