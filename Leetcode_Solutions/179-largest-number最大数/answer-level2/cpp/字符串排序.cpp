关键点是如何写字符串的比较函数。
先将整数列表转成字符串，将字符串按某种排序方式排列，然后合并到一起得到结果。
字符串比较函数规则如下：
1. 对两个字符串公有长度，直接比较。
2. 其中一个字符串为空，肯定不大于另一个字符串。
3. 其中一个字符串长度大于另一个字符串，如果在公有长度内无法比较出大小，再对超出的部分与另一个字符串比较。

```
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> ans;
        for(int num: nums) ans.push_back(to_string(num));
        sort(ans.begin(), ans.end(), [&](string& a, string &b) {
            return compare(a, b);
        });
        // 合并结果
        string res;
        for(auto a: ans) res+=a;
        // 去掉前缀0
        while(res.size()>1 && res[0]=='0') res = res.substr(1, res.size()-1);
        return res;
    }
    
    bool compare(string a, string b) {
        // 长度相等时直接字符串比较
        if(a.size()==b.size()) {
            return a > b;
        }
        if(a.size()==0) return false;
        if(b.size()==0) return true;
        // 两个字符串公有长度内字符串比较
        int n = min(int(a.size()), int(b.size()));
        for(int i=0;i<n;i++) {
            if(a[i]!=b[i]) return a[i]>b[i];
        }
        // 其中一个字符串多余的长度与另一个字符串比较
        if(n<a.size()) {
            return compare(a.substr(n, a.size()-n), b);
        } else {
            return compare(a, b.substr(n, b.size()-n));
        }
    }
};
```