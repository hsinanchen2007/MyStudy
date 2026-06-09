可以从最大高度开始枚举，将雨水区域进行计算。
对于每个正在枚举的高度设为 curHeight，仅次于该高度的值为 nextHeight。特别的，当 curHeight 为最小高度时，nextHeight = 0。
设 L 为不低于nextHeight的柱子坐标的最小值，R为不低于nextHeight的柱子坐标的最大值。
设 count 为高于nextHeight柱子的数量。
则待计算区域面积为 area = (R-L+1) * (curHeight - nextHeight)
该区域中雨水的数量为 sum = area - count*(curHeight - nextHeight)

区域示意如下：
![接雨水3.png](https://pic.leetcode-cn.com/6d6cda5bdb49505d3801f391714d6d1c49e2ebc3897cb6952dab7921609ac9d1-%E6%8E%A5%E9%9B%A8%E6%B0%B43.png)

枚举过程如下：

<![](https://pic.leetcode-cn.com/1cb631717cd0bd1f9a2bb26f58ed00932b7cd6bc0279bb339692d50e757ae43b-%E6%8E%A5%E9%9B%A8%E6%B0%B41.png),![](https://pic.leetcode-cn.com/72fc91728483158acdab266725423705469253f4d1213dd175e2e066399383d1-%E6%8E%A5%E9%9B%A8%E6%B0%B42.png),![](https://pic.leetcode-cn.com/b000c124ce7f3d81da51f9f92be28ef0b32ae744955aaa58ecf0e5c28e266714-%E6%8E%A5%E9%9B%A8%E6%B0%B43.png),![](https://pic.leetcode-cn.com/4f0d1c64493ed88e8830a4f7bef8a7d705903c37e72298223be26508918e185e-%E6%8E%A5%E9%9B%A8%E6%B0%B44.png)>

实现技巧：可以使用一个 map 统计每个高度柱子的出现次数及坐标，然后使用 std::greater 实现map的降序排序。
```
class Solution {
public:
    struct Info {
        int L, R;
        int cnt;
        Info() : L(0x7FFFFFFF), R(-1), cnt(0) {}
    };
    map<int, Info, greater<int>> data;
    int trap(vector<int>& height) {
        for(int i = 0, n = height.size(); i < n; i++) {
            auto &d = data[height[i]];
            d.L = min(d.L, i);
            d.R = max(d.R, i);
            d.cnt ++;
        }
        int L = height.size(), R = 0, cnt = 0;
        int res = 0;
        for(auto it = data.cbegin(); it != data.cend();) {
            L = min(L, it->second.L);
            R = max(R, it->second.R);
            cnt += it->second.cnt;
            int nowHeight = it->first;
            int nextHeight = 0;
            ++it;
            if(it == data.cend()) {
                nextHeight = 0;
            } else {
                nextHeight = it->first;
            }
            res += (R-L+1-cnt) * (nowHeight - nextHeight);
        }
        return res;
    }
};
```

# 如果感觉有点意思，可以关注👏[HelloNebula](http://q8b35lo57.bkt.clouddn.com/qrcode_for_gh_6e5f8557b1f8_258.jpg)👏
* **分享周赛题解**
* **分享计算机专业课知识**
* **分享C++相关岗位面试题**
* **分享专业书籍PDF**

