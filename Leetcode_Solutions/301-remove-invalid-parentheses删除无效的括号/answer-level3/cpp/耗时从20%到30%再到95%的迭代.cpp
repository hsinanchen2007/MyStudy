一共三种方案，后两种都是参考的别人的思路

# **1 方案一——深度优先递归**
第一步，类似于树，从空字符串开始，深度优先递归即可。
left_count是指左括号的数量， right_count自然就是右括号的数量。
![image.png](https://pic.leetcode-cn.com/aeb155e260ed757237225f3dc49c174d8a8bc8005febafdee5f16d9dd298e040-image.png)

第二步，有效子串也会遍历出来，加上max变量，用来剪枝

第三步，会有重复，剪枝不彻底的情况，用了一个set在结束后再过滤一遍

```
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_map<string, int> result_map;
        int max = 0;
        removeInvalidParenthesesRec(s, "", 0, 0, 0, result_map, max);
        vector<string> result;
        for (auto &result_map_iter : result_map) {
            if (result_map_iter.second == max) {
                result.push_back(result_map_iter.first);
            }
        }
        return result;
    }
    void removeInvalidParenthesesRec(const string &s, string cur_string, int cur_pos, 
        int left_count, int right_count, unordered_map<string, int> &result_map, int &max) {
        if (left_count + (s.size() - cur_pos) / 2 < max) {
            return;
        }
        if (cur_pos == s.size()) {
            if (left_count >= max and 
                left_count == right_count) {
                result_map[cur_string] = left_count;
                max = left_count;
            }
            return;
        }
        if (s[cur_pos] == '(') {
            // add left 
            removeInvalidParenthesesRec(s, cur_string + "(", cur_pos + 1, 
                left_count + 1, right_count, result_map, max);
            // not add left
            removeInvalidParenthesesRec(s, cur_string, cur_pos + 1, 
                left_count, right_count, result_map, max);
        }
        else if (s[cur_pos] == ')') {
            if (left_count > right_count) {
                removeInvalidParenthesesRec(s, cur_string + ")", cur_pos + 1, 
                    left_count, right_count + 1, result_map, max);
                removeInvalidParenthesesRec(s, cur_string, cur_pos + 1, 
                    left_count, right_count, result_map, max);   
            }
            else {
                removeInvalidParenthesesRec(s, cur_string, cur_pos + 1, 
                    left_count, right_count, result_map, max);  
            }
        }
        else {
            removeInvalidParenthesesRec(s, cur_string + s[cur_pos], cur_pos + 1, 
                    left_count, right_count, result_map, max);         
        }
    }
};
```
方案一的问题，就在于剪枝没有一次性剪干净，所以方案二就做出了针对性优化

# **方案二 提前获取要删除的括号数量，删除的括号为0时，不走相关分支即可。**
```
class Solution {
public:
    int get_unvalid_char_num(string s) {
        // get unvalid number
        int count = 0;
        int unvalid_num = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++count;
            }
            else if (s[i] == ')') {
                --count;
            }
            if (count < 0) {
                ++unvalid_num;
                count = 0;
            }
        }
        return unvalid_num + count;
    }
    vector<string> removeInvalidParentheses(string s) {
        int unvalid_num = get_unvalid_char_num(s);
        set<string> result_set;
        vector<string> result;
        removeInvalidParenthesesRec(s, "", 0, 0, 0, result_set, unvalid_num);
        for (auto &result_set_iter : result_set) {
            result.push_back(result_set_iter);
        }
        return result;
    }
    void removeInvalidParenthesesRec(const string &s, string cur_string, int cur_pos, 
        int left_count, int right_count, set<string> &result, int unvalid_num) {
        if (cur_pos == s.size()) {
            if (left_count == right_count) {
                result.insert(cur_string);
            }
            return;
        }
        if (s[cur_pos] == '(') {
            // add left 
            removeInvalidParenthesesRec(s, cur_string + "(", cur_pos + 1, 
                left_count + 1, right_count, result, unvalid_num);
            // not add left
            if (unvalid_num >= 0) {
                removeInvalidParenthesesRec(s, cur_string, cur_pos + 1, 
                    left_count, right_count, result, unvalid_num - 1);
            }
        }
        else if (s[cur_pos] == ')') {
            if (left_count > right_count) {
                removeInvalidParenthesesRec(s, cur_string + ")", cur_pos + 1, 
                    left_count, right_count + 1, result, unvalid_num);
                if (unvalid_num >= 0) {
                    removeInvalidParenthesesRec(s, cur_string, cur_pos + 1, 
                        left_count, right_count, result, unvalid_num - 1); 
                }
            }
            else {
                if (unvalid_num >= 0) {
                    removeInvalidParenthesesRec(s, cur_string, cur_pos + 1, 
                        left_count, right_count, result, unvalid_num - 1);  
                }
            }
        }
        else {
            removeInvalidParenthesesRec(s, cur_string + s[cur_pos], cur_pos + 1, 
                    left_count, right_count, result, unvalid_num);         
        }
    }
};
```

耗时只打败了百分之三十。。当时我是有点想不通的，因为我想不到更给力的剪枝方案了，直到我看到了方案三。

# **方案三——从完整的字符开始，进行字符串删除**
方案一，二都是从空字符串，一路累加过去的，递归调用的深度是跟字符串直接关联，长度一百的字符串，删除一个，也要递归调用100次。
而方案三则是从完整的字符串开始，进行删除，深度就是要删除的括号量级。所以，长度一百的字符串，删除一个，递归调用一次即可。
所以，一个自顶向下，另一个自底向上。
```
class Solution {
public:
    bool isvalid(string s) {
        int cnt = 0;
        for (auto c : s) {
            if (c == '(') {
                cnt++;
            } else if (c == ')') {
                cnt--;
                if (cnt < 0) return false;
            }
        }
        return cnt == 0;
    }

    void dfs(string s, int st, int l, int r, vector<string>& ans)
    {
        if (l == 0 && r == 0) {
            if (isvalid(s)) {
                ans.push_back(s);
            }
            return;
        }
        for (int i = st; i < s.size(); i++) {
            if (i != st && s[i] == s[i-1]) continue;
            if (s[i] == '(' && l > 0) {
                dfs(s.substr(0, i) + s.substr(i+1, s.size()-1-i), i, l - 1, r, ans);
            } 
            if (s[i] == ')' && r > 0) {
                dfs(s.substr(0, i) + s.substr(i+1, s.size()-1-i), i, l, r - 1, ans);
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        //最快的方式是获取有多少个可以删除的括号，然后想办法删除
        int left = 0;
        int right = 0;
        vector<string> ans;

        for (auto c : s) {
            if (c == '(') {
                left++;
            } else if (c == ')') {
                if (left > 0) { 
                    left--;
                } else {
                    right++;
                }
            }
        }
        // left和right表示左右括号要删除的个数
        dfs(s, 0, left, right, ans);
        return ans;
    }

};
```




