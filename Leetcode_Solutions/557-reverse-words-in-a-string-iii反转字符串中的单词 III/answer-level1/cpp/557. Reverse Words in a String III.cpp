
// // 本来我是这样写的，但是吧，测试发现测试用例有问题；
// // still preserving whitespace； 
// // 我觉得官方答案有问题；不是应该保留空白吗?  ‍🤦‍♂️🤷‍♀️🤷‍♂️;
// // 见测试用例；

// // 输入        " Let's take   LeetCode     contest   "
// // 输出        " s'teL ekat   edoCteeL     tsetnoc   "
// // 预期结果     "s'teL ekat edoCteeL tsetnoc"

// ```
class Solution {
public:
    string reverseWords(string s) {
        if (s.size() <= 1) return s;

        auto it1 = s.begin(), it2 = it1;
        while (it2 != s.end()) {
            while (it2 != s.end() && *it2 != ' ') {
                ++it2;
            }
            std::reverse(it1, it2);
            while (it2 != s.end() && *it2 == ' ') {
                ++it2;
            }
            it1 = it2;
        }

        return s;
    }
};
// ```