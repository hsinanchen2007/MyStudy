对于斐波拉契数列，确定了最开始的两个数，就可以确定整个数列。

由于题目中要求数组长度需大于3，所以前两个数的长度均不大于ceil(n/3)。

确定前两个数之后，计算出下一个数，并判断字符串是否存在即可。

```
class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        int n = S.size();
        vector<int> res;
        for(int i=1;i<=n/3+1;i++) {
            for(int j=i+1;j<=n*2/3+1;j++) {
                // 枚举
                string a=S.substr(0, i), b=S.substr(i, j-i);
                // 前置0判断
                if(a[0]=='0' && a.size()>1) continue;
                if(b[0]=='0' && b.size()>1) continue;
                // cout<<a<<" "<<b<<endl;
                res = find(S, atoi(a.c_str()), atoi(b.c_str()), j);
                if(!res.empty()) return res;
            }
        }
        return res;
    }
    vector<int> find(string S, int a, int b, int start) {
        vector<int> res;
        int n = S.size();
        // cout<<start<<" "<<n<<endl;
        if(start>=n) return res;
        res.push_back(a);
        res.push_back(b);
        while(start<n) {
            long ans = long(a)+b;
            // 越界判断
            if(ans>INT_MAX) {
                res.clear();
                return res;
            }
            string tmp = to_string(ans);
            // cout<<ans<<" "<<S.substr(start, tmp.size())<<endl;
            // 存在性判断
            if(S.substr(start, tmp.size())!=tmp) {
                res.clear();
                return res;
            }
            res.push_back(ans);
            // 数据更新
            start += tmp.size();
            a = b;
            b = ans;
        }
        if(start>n) res.clear();
        return res;
    }
};
```
