### 解题思路
递推
可以发现，s[1] - s[n] 位的解码方法总数只与s[1] - s[n - 2] 位以及 s[1] - s[n - 1] 位的解码方法s总数有关，因此可以以递推方式实现。
若令 f[n] 代表第 n 位的解码总数，则：
f[n] = 0
1、若 s[n] 位非零，则 f[n] += f[n - 1] **// f[n] 位单独代表一个字母**
2、若 s[n-1] - s[n] 可以组成一个在 [10, 26] 区间内的数，则 f[n] += f[n - 2] **// f[n - 1] 与 f[n] 共同代表一个字母 **

![image.png](https://pic.leetcode-cn.com/3bf2d96060dd2bf3c18b051078d6f39bd7bf723d848ea60af3b5ddef30e00b64-image.png)

### 代码

```cpp
class Solution {
public:
    int numDecodings(string s) {
        // 特殊情况处理
        if(s.length() == 0) return 0;
        if(s[0] == '0') return 0;
        if(s.length() == 1) return 1;
        // 将 f[n] 压缩至 f[3] (仅保存 f[n - 2], f[n - 1], f[n])
        int f[3];
        f[2] = 1;
        f[1] = 1;
        for(int i = 1; i < s.length(); i ++)
        {
            // 位移
            f[0] = f[1];
            f[1] = f[2];
            // 方法判断累加
            if(s[i] == '0') f[2] = 0;
            int tmp = (s[i - 1] - '0') * 10 + s[i] - '0';
            if(tmp > 9 && tmp < 27) f[2] += f[0];
        }
        return f[2];
    }
};
```