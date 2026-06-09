### 解题思路
grayCode(n)可以分为两部分，一部分就是grayCode(n - 1)，另一部分就是grayCode(n - 1)每一位都加上2^(n-1)再倒过来
具体思路看图：
![绘图1.png](https://pic.leetcode-cn.com/7b664cf95543ae1c6fdb3cd2ab88bd8a705e2966b08f2d66f619bf87e9ccfc99-%E7%BB%98%E5%9B%BE1.png)

如果我们知道了gray_n的二进制表示，那么gray_n+1实际上就是gray_n的头部加0（10进制里+0），然后反转gray_n后头部加1（10进制里+2^n）
以n = 2到n = 3为例;
![image.png](https://pic.leetcode-cn.com/278700329e035aa4b6efcf67798564c958b571644319d54abe563f4accd9d397-image.png)

所以这道题本质就是个**动态规划**

### 代码

```cpp
class Solution {
public:
    vector<int> grayCode(int n) {
        // 边界条件
        vector<int> temp{0};
        if(!n) return temp;
        // 状态转移方程
        temp = grayCode(n - 1);
        vector<int> res;
        int increment = 1 << (n - 1);
        for(int i = 0; i < temp.size(); i++) {
            res.push_back(temp[i]);
        }
        for(int i = temp.size() - 1; i >= 0; i--) {
            res.push_back(temp[i] + increment);
        }
        return res;
    }
};
```