```
//执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
//内存消耗 :8.3 MB, 在所有 C++ 提交中击败了85.71%的用户
class Solution {
public:
    map<long long,long long> rec;//记录每个下标对应的长度
    long long len,cnt;
    string res;//记录走过的路径
    string decodeAtIndex(string s, int k) {
        for(int i=0;i<s.length();i++) {
            if(isalpha(s[i])) {
                res.push_back(s[i]);
                len++;//len表示当前长度
                rec[i] = len;
                if(len==k) return string(1,s[i]);//如果长度正好为k直接返回字母
            }else {
                cnt = len * (s[i]-'0');//翻s[i]倍后的长度
                if(cnt<k) {//翻s[i]倍后的当前长度没有到达k
                    res.push_back(s[i]);
                    rec[i] = len = cnt;
                }else {//翻s[i]倍后的当前长度大于等于k时即可回溯查找
                    cnt = k%len;
                    if(!cnt) cnt = len;
                    i--;
                    while(i>=0&&rec[i]!=cnt) {
                        if(isdigit(res[i])) {
                           cnt %= rec[i-1];
                           if(!cnt) cnt = rec[i-1];
                        }
                        i--;
                    }
                    while(i>=0&&isdigit(res[i])) i--;
                    return string(1,res[i]);
                }
            }
        }
        return "";
    }
};
```
