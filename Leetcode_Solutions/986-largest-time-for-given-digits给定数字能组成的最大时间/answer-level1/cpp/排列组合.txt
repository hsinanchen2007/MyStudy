想到的是排列组合，使用递归进行排列组合是非常简单的，然后简单的加上限制条件就好了（包括一个字符串大小比较，字符串只含有数字的时候，大小比较的结果和数字的比较结果是一样的），最后判断结果是否为空，如果为空，就直接返回，如果不为空，需要手动插入':'符号。

```
class Solution {
private:
    string res;
public:
    void dfs(string &A, int i) {
        if (i == A.size()) {
            if ((A[0] - '0') * 10 + A[1] - '0' < 24 && (A[2] - '0') * 10 + A[3] - '0' < 60) {
                if (res.empty() || res < A) res = A;
            }
        }
        for (int j = i; j < A.size(); ++j) {
            swap(A[i], A[j]);
            dfs(A, i + 1);
            swap(A[i], A[j]);
        }
        return;
    }
    string largestTimeFromDigits(vector<int>& A) {
        string tmp; tmp.clear();
        for (int i : A) tmp.push_back(char(i + '0'));
        dfs(tmp, 0);
        if (!res.empty()) res.insert(res.begin() + 2, ':');
        return res;
    }
};
```
