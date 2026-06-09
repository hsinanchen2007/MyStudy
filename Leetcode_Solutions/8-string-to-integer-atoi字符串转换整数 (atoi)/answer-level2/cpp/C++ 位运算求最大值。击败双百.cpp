// 我觉得比较难搞的两个点：
// 1. 在转化过程中防止超过 MAX。
// 2. 求得int的最大值和最小值。

// 对于第一点，有 res * 10 + curVal <= MAX，转化一下 res <= (MAX - curVal)/10 。
// 对于第二点，可以考虑位运算，但直接左移31位会影响符号位，所以分三步走。
// * 先将 1 左移30位，然后减一。此时二进制为 0011111111111111111111111111，即两个0 和 30 个1。
// * 左移一位。此时二进制为 0111111111111111111111111110，即一个 0 和 30 个1 和 1 个 0。
// * 然后加一。

// 最小值可以由最大值做减法得到。

// ```
class Solution {
public:
    int myAtoi(string str) {
        const char *p = str.c_str();
        for(; p != nullptr && *p == ' '; p++) {}
        if(p == nullptr || (*p != '+' && *p != '-' && (*p < '0' || *p > '9'))) {
            return 0;
        }
        int res = 0, flag = 1;
        if(*p == '-') {
            flag = -1;
            p++;
        } else if(*p == '+') {
            p++;
        }
        int MAX = (((1 << 30)-1)<<1) + 1;
        int MIN = -MAX-1;
        for(; '0' <= *p && *p <= '9'; p++) {
            if((MAX-(*p-'0')) / 10 < res) {
                if(flag == -1) {
                    return MIN;
                } else {
                    return MAX;
                }
            }
            (res *= 10) += *p-'0';
        }
        return res * flag;
    }
};
// ```
// ![image.png](https://pic.leetcode-cn.com/a83699b555c7d972f89da884fa3833af3e750ea9671d5461ca11f022b5d1adb3-image.png)

// # 如果感觉有点意思，可以关注👏[HelloNebula](http://q8b35lo57.bkt.clouddn.com/qrcode_for_gh_6e5f8557b1f8_258.jpg)👏
// * **分享周赛题解**
// * **分享计算机专业课知识**
// * **分享C++相关岗位面试题**
// * **分享专业书籍PDF**