### 解题思路

一开始是想搞个栈记录一下之前的数字 等遍历到最后一个的时候一起计算一遍 
看到解答区有大佬的解法发现其实只需要记录栈顶的元素和当前求和的值即可。碰到优先级更高的乘号，可以根据传入的这两个状态恢复出正确的计算次序。如果碰到乘号，先把栈顶加减的值revert掉，然后把乘号和“栈”顶元素求积放回栈顶即可。这个过程和用栈的情况是一致的，但我们就可以把栈移除了，并且实时的计算遍历到当前位置的计算结果。

具体见代码。

真诚欢迎大家关注我的github和leetcode仓库～
[我的github](https://www.github.com/wfnuser)
[我的题解](https://www.github.com/wfnuser/leetcode)
最近沉迷刷题 同时也在学习和实现lua，欢迎交流


### 代码

```cpp
class Solution {
public:
    vector<string> ans;
    int target;

    void dfs(string& num, int step, int last, long res, string &str) {
        if (step == num.size()) {
            if (res == target) ans.push_back(str);
            return;
        }
        int originSize = str.size();
        for (int i = step; i < num.size(); i++) {
            string curS = num.substr(step, i - step + 1);
            long cur = stol(curS);
            if (step == 0) {
                str += curS;
                dfs(num, i+1, cur, cur, str);
                str.resize(originSize);
            } else {
                // +
                str += "+" + curS;
                dfs(num, i+1, cur, res+cur, str);
                str.resize(originSize);
                // -
                str += "-" + curS;
                dfs(num, i+1, -cur, res-cur, str);
                str.resize(originSize);
                // *
                str += "*" + curS;
                dfs(num, i+1, last*cur, res-last+last*cur, str);
                str.resize(originSize);
            }
            if (cur == 0) break;
        }
    }

    vector<string> addOperators(string num, int target) {
        this->target = target;
        string s = "";
        dfs(num, 0, 0, 0, s);
        return ans;
    }
};
```