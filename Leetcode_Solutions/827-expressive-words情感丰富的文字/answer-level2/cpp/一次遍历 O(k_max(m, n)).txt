```
class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int res = 0;
        for(string& w: words) if(match(S, w)) res++;
        return res;
    }
    bool match(string& a, string& b) {
        int m = a.size(), n = b.size();
        int i=0, j=0;
        for(;i<m && j<n;) {
            if(a[i] != b[j]) return false;
            // 分别统计a和b中有多少个连续相同字符
            int x = 0;
            while(i+x < m && a[i+x]==a[i]) x++;
            i += x; // 更新下标
            int y = 0;
            while(j+y < n && b[j+y]==b[j]) y++;
            j += y;
            // 有相同个数的相同字符，无需扩展
            // b中相同字符小于a时，需满足a中字符数大于等于3才能扩展
            if(x==y || (x>y && x>=3)) continue;
            return false;
        }
        return i==m && j==n;
    }
};
```
