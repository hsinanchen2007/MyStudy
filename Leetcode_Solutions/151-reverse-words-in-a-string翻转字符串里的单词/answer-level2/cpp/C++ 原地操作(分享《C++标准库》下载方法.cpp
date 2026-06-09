// 1. 先整体反转
// 2. 确定子串的起始位置和结束位置。向前移动，局部反转。
// 3. 删除末尾多余的空格。

// 虽然C++的标准库没有python等丰富，但还是有一些好用的基础函数的，不熟悉的小伙伴可以看下 《C++标准库》。

// ```
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        int pos = 0;
        for (int begin = 0; begin < n; ++begin) {
            if (s[begin] != ' ') {//找到了下一个字符串的起点
                if (pos != 0) { //放一个空格做间隔
                    s[pos++] = ' ';
                }
                int end = begin;
                while (end < n && s[end] != ' ') {//前移
                    s[pos++] = s[end++];
                }
                reverse(s.begin() + pos - (end - begin), s.begin() + pos); //局部反转
                begin = end;
            }
        }
        s.erase(s.begin() + pos, s.end());//末尾可能有多余空格
        return s;
    }
};
// ```

// 关注公众号，发送 CPP标准库，即可获得下载链接~

// # 如果感觉有点意思，可以关注👏[HelloNebula](http://q8b35lo57.bkt.clouddn.com/qrcode_for_gh_6e5f8557b1f8_258.jpg)👏
// * **分享周赛题解**
// * **分享计算机专业课知识**
// * **分享C++相关岗位面试题**
// * **分享专业书籍PDF**