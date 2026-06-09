先吐槽一下题目的数据，k = 0 时竟然要返回空的 vector。长度为0的板不要面子的吗？！好气哦

当两种板子长度相同的时候，显然无论如何组合，跳板的长度均为 k*shorter。故只有一种长度。
当两种板子的长度不相同的时候，可以组合出 k+1 种长度的跳板，证码过程如下：

首先，我们选择k块短板，此时长度为 k*shorter。**这是一种方案。**
每用一块长板替换掉一块短板，跳板的长度就会增加 longer - shorter。故每替换一次，就会产生一种新方案。
**一共可以替换k次**。故总共有 k + 1 种方案。

频繁的push_back 有可能触发内存的频繁分配，如果预先知道push_back的次数，可以预先分配以提高效率。
常用的构造函数如下图：
![image.png](https://pic.leetcode-cn.com/c57956379b35afc32612d4163ab6789caaddae0ad69d5467d6b57eec0f34f8da-image.png)

```
class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        if(k == 0) {
            return vector<int>{};
        }
        if(shorter == longer) {
            return vector<int> {shorter * k};
        }
        vector<int> vec(k+1);
        for(int i = 0; i <= k; i++) {
            vec[i] = (k-i)*shorter + i*longer;
        }
        return vec;
    }
};
```

![qrcode_for_gh_6e5f8557b1f8_258.jpg](https://pic.leetcode-cn.com/c2444cd4f69533ef9ffa7cf4348068d442d736cf281eaf9d353c5b0ac6946d61.jpg)

# **扫码关注，Offer加倍**

