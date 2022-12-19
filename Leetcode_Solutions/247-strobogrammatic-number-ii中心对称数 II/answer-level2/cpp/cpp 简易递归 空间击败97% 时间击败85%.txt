### 解题思路
![image.png](https://pic.leetcode-cn.com/c9e0d9acbea82f4ff4375b003c0725da68bd56101b427b95f94ae521f22731dd-image.png)

构造中心对称数是可以找到明显的子问题求解规律的。
一个长度为n的字符串，可以先把中间n-2位字符串的所有构造方式列出。然后两边拼接上 11 69 96 88 即可。
需要注意的是，要处理一下最外层数据不能取0的限制。

[自己动手实现分布式存储](https://www.github.com/wfnuser/burrow)
[我的题解](https://www.github.com/wfnuser/leetcode)
[我的github](https://www.github.com/wfnuser)
最近沉迷刷题，真诚欢迎大家star和follow 最近也在学习和实现lua，欢迎交流

### 代码

```cpp
class Solution {
public:

    vector<string> helper(int n) {
        if (n == 1) {
            return vector<string>{"0", "1", "8"};
        }
        if (n == 2) {
            return vector<string>{"11", "69", "88", "96", "00"};
        }
        vector<string> subs = helper(n-2);
        vector<string> ans;

        for (auto sub: subs) {
            ans.push_back("0"+sub+"0");
            ans.push_back("1"+sub+"1");
            ans.push_back("6"+sub+"9");
            ans.push_back("9"+sub+"6");
            ans.push_back("8"+sub+"8");
        }

        return ans;
    }

    vector<string> findStrobogrammatic(int n) {
        if (n == 1) {
            return vector<string>{"0", "1", "8"};
        }
        if (n == 2) {
            return vector<string>{"11", "69", "88", "96"};
        }

        vector<string> subs = helper(n-2);
        vector<string> ans;
        for (auto sub: subs) {
            ans.push_back("1"+sub+"1");
            ans.push_back("6"+sub+"9");
            ans.push_back("9"+sub+"6");
            ans.push_back("8"+sub+"8");
        }

        return ans;
    }
};
```