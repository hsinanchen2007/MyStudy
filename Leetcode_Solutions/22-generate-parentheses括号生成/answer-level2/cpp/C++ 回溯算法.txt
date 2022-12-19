### 解题思路
1、使用回溯算法进行遍历。
2、对于一个合法的字符串来说，左括号数量必然大于等于右括号。
3、string也可以使用push_back()及pop_back()。

### 代码

```cpp
class Solution {
public:
    vector<string> res;
    int target;

    vector<string> generateParenthesis(int n)
    {
        target = n;

        string str;
        backTrack(str, 0, 0);
        return res;
    }

    void backTrack(string &str, int left, int right)
    {
        if (left == target && right == target) {
            res.emplace_back(str);
            return;
        }

        str += '(';
        left++;
        if (valid(str, left, right)) {
            backTrack(str, left, right);
        }
        str.pop_back();
        left--;

        str += ')';
        right++;
        if (valid(str, left, right)) {
            backTrack(str, left, right);
        }
        str.pop_back();
        right--;
    }

    bool valid(string &str, int left, int right)
    {
        if (left > target || right > target) {
            return false;
        }

        int leftCnt = 0;
        int rightCnt = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '(') {
                leftCnt++;
            } else {
                rightCnt++;
            }
            if (rightCnt > leftCnt) {
                return false;
            }
        }

        return true;
    }
};
```