
当$K >= 2$的时候,我们总是能取前$K$个中第一个违反当前前$K$个非递减字母序的字母放在最后面。也就是说经过若干次操作后。整个字母序列单调非递减。所以答案就是对$S$进行排序。

当$K = 1$的时候。将这个字符串序列想象成一个环序列，将一个字母放到最后若干次等价于将这个字符串环中取一个起点作为新字符串的起点。这样的字符串有$|S|个，$所以此时答案就是这$|S|$个字符串中字典序最小的那一个。
时间复杂度$O(|S|^2)$
```c++
#define dbg(x) cout << #x"=" << x << endl;
class Solution {
public:
    string orderlyQueue(string S, int K) {
        string ans = S;
        if(K > 1) sort(ans.begin(), ans.end());
        else {
            int sz = S.size();
            for(int i = 1; i < sz; ++i){
                string s = "";
                for(int j = 0; j < sz; ++j){
                    s += S[(i+j)%sz];
                }
                ans = min(ans, s);
            }
        }
        return ans;
    }
};
```