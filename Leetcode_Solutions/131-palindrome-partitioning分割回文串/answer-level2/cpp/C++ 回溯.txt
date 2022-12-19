![捕获.PNG](https://pic.leetcode-cn.com/328286cb62189d46ccc69f85aa6cf3d138786194e55a94fdccb2c8ac35699b50-%E6%8D%95%E8%8E%B7.PNG)


```c++
class Solution {
public:
    vector<vector<string>> partition(string s) {
        backtrack(s, 0);
        return res;
    }

private:
    void backtrack(const string& s, int beg) {
        if (beg == s.size()) {
            //遍历到串尾时，中间结果放入结果集，回溯
            res.push_back(path);
            return;
        }
        //遍历所有(beg,end)子串
        for (int end = beg; end < s.size(); end++) {
            if (!IsPalindrome(s, beg, end)) continue;//子串不是回文，则继续
            //子串是回文，放到中间结果集path中，递归剩余子串
            path.push_back(s.substr(beg, end-beg+1));
            backtrack(s, end+1);
            path.pop_back();
        }
    }
    bool IsPalindrome(const string& s, int beg, int end) {
        while (beg < end) {
            if (s[beg] != s[end]) return false;
            beg++;
            end--;
        }
        return true;
    }
    vector<vector<string>> res;//结果集
    vector<string> path;//存放中检结果集
};
```
