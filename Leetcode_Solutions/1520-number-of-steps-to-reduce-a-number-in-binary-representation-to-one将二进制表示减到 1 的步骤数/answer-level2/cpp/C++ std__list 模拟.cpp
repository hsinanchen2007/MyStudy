// 可以借助链表模拟。首先将 string 转为 list。然后模拟规则处理list。
// **转成 list 是为了降低最高位进位时的时间复杂度。**
// 设 cnt 为操作计数器。
// 1. 如果 list.size() == 1 ，处理结束。
// 2. 如果 list 的最后一个元素为 0，cnt += 1，将最后一个结点弹出。跳转第一步。
// 3. 如果 list 的最后一个元素为 1，cnt += 1，对最后一个结点加一并模拟进位。需要考虑最高位进位的情况。跳转第一步。

// 代码如下：
// ```cpp
class Solution {
public:
    int numSteps(string s) {
        list<int> node;
        for(int i = 0; i < s.size(); ++i) {
            node.push_back(s[i]-'0');
        }
        int cnt = 0;
        while(node.size() > 1) {
            if(node.back() == 0) {
                cnt++;
                node.pop_back();
            } else {
                cnt++;
                for(auto it = --node.end();;) {
                    if(*it == 1) {
                        *it = 0;
                        if(it == node.begin()) {
                            node.insert(it, 1);
                            break;
                        } else {
                            --it;
                        }
                    } else {
                        *it = 1;
                        break;
                    }
                }
            }
        }
        return cnt;
    }
};
// ```
// # 如果感觉有点意思，可以关注👏[HelloNebula](http://q8b35lo57.bkt.clouddn.com/qrcode_for_gh_6e5f8557b1f8_258.jpg)👏
// * **分享周赛题解**
// * **分享计算机专业课知识**
// * **分享C++相关岗位面试题**
// * **分享专业书籍PDF**