### 解题思路

思路一：DFS
前序：感觉题目有点迷惑性，删除最少的括号，其实一旦给定字符串形式，最少删除多少左右括号后字符串有效是确定的。检查合法括号的两种方式，一种是用堆栈，另一种是用计数器
1、删除括号使得字符串有效，其实是可以知道有多少非法的左括号和右括号的，遍历一把就可以计算得到
2、那就在原始字符串上面进行删除操作，遍历删除的字符位置[0, s.size()-1], 对应字符为左右括号时，分别递归
3、当前删除位置需要传递给下一次迭代，因为每次其实删除一个字符后，字符串长度是减少1的，而删除的位置正好是下一次迭代中开始删除的首位。
4、有个优化点，就是在循环删除的时候，如果下一个字符和上一次回溯结束后的字符一样时，不需要再重复处理
5、左右括号删除满足条件时，检查字符串s是否有效

思路二：BFS
1、一般情况下我们拿到最小类问题，首先可能都会去考虑BFS或者贪心，这个题呢也可以用BFS来解，或许思路更加容易理解
2、删除最小括号使得字符串满足要求，那么我们怎么去删除呢，可以考虑每次给定的字符串删除一个字符有多少种可能，在这么多种可能中如果出现一例合法的，也就可以结束了
3、每次删除一个字符后的所有可能都入队列，每次处理队列数据的时候也是把当前队列中的所有元素统一处理，这样其实层次关系就出来了，在给定的层次关系下，计算计算得到最小值时的所有可能数据
4、有个点需要注意下，在每次处理一层队列的时候，删除字符添加新队列进行去重，可以利用set的特性，先识别在set中是否存在，不存在的时候才加队列

8ms 10.2M
--- wangtao HW-2020/3/1

### 代码

```cpp
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