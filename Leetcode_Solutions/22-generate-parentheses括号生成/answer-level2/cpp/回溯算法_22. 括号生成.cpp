### 解题思路 回溯算法
参考字符串的排列


    /*
     * 回溯法
     *
     * 对于合法括号，有两个要求：
     * 1. 左括号的数量一定等于右括号的数量；
     * 2. 对于任何括号字符串p，其子串p[0...i]中左括号的数量都大于或等于右括号的数量。
     *
     * 对于n对括号，等于有2n个位置，每个位置可以放置"("")"任意一个字符，
     * 组成的所有括号组合中，取合法括号的字符串，即是对此2n个字符进行合法排列。
     * 而字符串的排列方法最合适的就是回溯算法，可以使用回溯算法穷举所有可能，找到合法的字符串即可。
     * 对于2n个位置，必然有n个左括号，n个右括号，所以不是简单的穷举位置i，而是分出left记录左括号，
     * right记录还可以使用多少个右括号，这样就能通过合法括号的规律对括号字符串进行筛选。
     * */
### 代码

```cpp
std::vector<std::string> generateParenthesis(int n) {
    if (n == 0) {
        return {};
    }

    // 记录所有合法的括号字符串
    std::vector<std::string> ans;
    // 回溯过程中的路径
    std::string track;

    // 可用的左括号和右括号数量初始化为n
    backtrack(n, n, track, ans);

    return ans;
}

void backtrack(int left, int right, std::string &track, std::vector<std::string> &ans) {
    // 若左括号剩下的多，不合法
    if (right < left) {
        return;
    }

    // 左右括号数量小于0，不合法
    if (left < 0 || right < 0) {
        return;
    }

    // 当左右括号都恰好用完时，得到一个合法的括号字符串
    if (left == 0 && right == 0) {
        ans.push_back(track);
        return;
    }

    // 尝试放置一个左括号
    track.push_back('(');
    // 选择
    backtrack(left - 1, right, track, ans);
    // 撤销选择
    track.pop_back();

    // 尝试放置一个右括号
    track.push_back(')');
    // 选择
    backtrack(left, right - 1, track, ans);
    // 撤销选择
    track.pop_back();

}

```