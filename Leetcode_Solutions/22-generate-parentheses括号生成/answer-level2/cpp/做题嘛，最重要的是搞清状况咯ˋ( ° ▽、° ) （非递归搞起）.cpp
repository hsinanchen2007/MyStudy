// 设字符串 str 初始时为空串，我们尝试拼接 '(' 或 ')' 使得 str.size() == n*2 且是一个合法的括号匹配字符串。
// 设 str 中 '(' 数量为 lc， ')'的数量为 rc。

// **讨论两种状况：**
// 1. **当 rc+1 <= lc 时可以放入 ')'。**
// 2. **当 lc+1-rc <= n-str.size()-1 时，可以放入 '('。**

// 状况1代表，拼接一个')'后，str中的'('仍然不少于')'。
// 如果不满足，则不可以拼接')'，**因为会导致当前的 ')' 没有 '(' 与之匹配**。

// 状态2代表，拼接一个'('后，在后续的拼接中，仍可以将str拼接成一个合法的括号匹配。
// 如果不满足，则不可以拼接'('，因为会导致**即使剩余的位置全放')' 仍然是 '(' 多于 ')' 的情况**。


// 有些刁钻的面试官，会让你写一个非递归版本：
// ```
class Solution {
public:
    //可以认为 Data 就是递归版本的栈帧，str，lc，rc就是参数。
    //Data::status 就是递归调用返回后，继续执行的指令地址。
    struct Data {
        string str;
        int lc;
        int rc;
        int status; 
    };
    stack<Data> st;
    vector<string> generateParenthesis(int n) {
        n *= 2;
        vector<string> res;
        st.push(Data{"", 0, 0, 0});
        while(st.empty() == false) {
            Data &t = st.top();
            if(t.str.size() == n) {
                res.push_back(t.str);
                st.pop();
                continue;
            }
            if(t.status == 2) {
                st.pop();
                continue;
            }
            if(t.status == 0) {
                if(t.rc + 1 <= t.lc) {
                    st.push(Data{t.str + ")", t.lc, t.rc+1, 0});
                }
                t.status = 1;
                continue;
            }
            if(t.status == 1) {
                if(t.lc+1-t.rc <= n - t.str.size()-1) {
                    st.push(Data{t.str+"(", t.lc+1, t.rc, 0});
                }
                t.status = 2;
                continue;
            }
        }
        return res;
    }
};
// ```

// 递归版本
// ```
class Solution {
public:
    void work(const string &str, int lc, int rc, int n, vector<string> &res) {
        if(str.size() == n) {
            res.push_back(str);
            return;
        }
        if(rc < lc) {
            work(str+")", lc, rc+1, n, res);
        }
        if(lc+1-rc <= n-str.size()-1) {
            work(str+"(", lc+1, rc, n, res);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        work("", 0, 0, n*2, res);
        return res;
    }
};
// ```
// # 如果感觉有点意思，可以关注👏[HelloNebula](http://q8b35lo57.bkt.clouddn.com/qrcode_for_gh_6e5f8557b1f8_258.jpg)👏
// * **分享周赛题解**
// * **分享计算机专业课知识**
// * **分享C++相关岗位面试题**
// * **分享专业书籍PDF**