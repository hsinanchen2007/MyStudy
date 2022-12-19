DFS深度搜索思路，数值>255非法，以零开头长度大于等于2非法；
不同于常规回溯思路，同层只用最多遍历3个数字，依次查看是否满足数值要求；
各段的数值状态也是分段存储的，互不干涉，使用vector<string> path来存储；
```
class Solution {
public:
    bool isValid(string ip)
{
    int val = stoi(ip);
    if (val > 255)    return false;
    if (ip.size() >= 2 && ip[0] == '0')    return false;
    return true;
}
void dfs(string& s, int pos, vector<string> &path, vector<string>& res)
{
    //首先判断剩余的位数，是不是还能满足要求，比如25525511135，若2.5.5.25511135显然不满足，这可以预判
    //4组，每组最多3位数字
    int maxLen = (4 - path.size()) * 3;
    if (s.size() - pos > maxLen)    return;
    if (path.size() == 4 && pos == s.size()) {
        string ans = "";
        for (int i = 0; i < 4; ++i) {
            ans += path[i];
            if (i != 3)    ans += ".";
        }
        res.push_back(ans);
        return;
    }
    //回溯算法的典型模式，循环递归
    for (int i = pos; i < s.size() && i <= pos + 2; ++i) {
        string ip = s.substr(pos, i - pos+1);
        if (!isValid(ip))    continue;
        path.push_back(ip);
        dfs(s, i + 1, path, res);
        path.pop_back();
    }
}
vector<string> restoreIpAddresses(string s) 
{
    //找3个.的位置,每个.之前组成的的数值必须要小于255，且以0开头的除非数字是0本身，否则也是非法
    vector<string> res;
    if (s.size() == 0 || s.size() < 4)    return res;
    vector<string> path;//存储从根开始的到叶子节点的满足条件的路径,因为最多3位数字一组，所以同一层横向循环时尝试最多3个位的长度
    dfs(s, 0, path, res);
    return res;
}
};
```
