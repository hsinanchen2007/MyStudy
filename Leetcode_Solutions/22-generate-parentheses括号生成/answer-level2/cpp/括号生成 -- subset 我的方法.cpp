### 解题思路
回溯算法的模板：

    subhelp(string& nums, string& subset, vector<string>& result, int& pos) {
        result.push_back(subset);
        for(int i = pos; i < nums.size(); i++) {
            subset.push_back(num[i]);
            subhelp(nums, subset, result, pos + 1);
            subset.pop_back();
        }
    }
（1）什么时候跳过；
（2）什么时候输出：

本题：
模仿带重复数字的全排列做的，增加一个判断，括号是否符合要求的判断

### 代码

```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::string nums;
        for (int i = 0; i < n; i++) {
            nums.push_back('(');
        }
        for (int i = 0; i < n; i++) {
            nums.push_back(')');
        }
        vector<std::string> result;
        std::string subset;
        vector<bool> used(2 * n, false);
        subhelp(nums, result, subset, used);
        return result;
    }

    void subhelp(std::string& nums, vector<std::string>& result, std::string& subset, vector<bool>& used)
    {
        if (subset.size() == nums.size() && isright(subset)) {
            result.push_back(subset);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                    continue;
                }
                used[i] = true;
                subset.push_back(nums[i]);
                subhelp(nums, result, subset, used);
                subset.pop_back();
                used[i] = false;
            }
        }
        return;
    }

    bool isright(std::string str) {
        if (str.size() == 0) return false;
        stack<char> stack;
        for (auto c : str) {
            if (c == '(') {
                stack.push(c);
            } else {
                if (stack.empty()) {
                    return false;
                } else {
                    if (stack.top() == '(') {
                        stack.pop();
                    } else {
                        return false;
                    }
                }
            }
        }
        if (stack.empty()) {
            return true;
        } else {
            return false;
        }
    }
};
```