### 解题思路
1.首先搞清楚爬楼梯算法(斐波拉契数列)，可以参考LeetCode第70题的各种题解。
2.其中只需排除不需要的解，就是本题答案。主要在于，判断字符在"0"到"26"之间。
3.使用非递归的动态规划方式，可以最大限度地节省时空。
![1.png](https://pic.leetcode-cn.com/a3df43bff222bc8e3c0d746dc7d5bf33c55781e350fb911bb42c6f06a7372047-1.png)
### 代码

```cpp
class Solution {
public:
    int numDecodings(string s) {//题上说了，非空字符串
        if('0' == s[0])//一定需要这个例外判别，‘0’开头的都不行
            return 0;
        
        int sLength = s.size();
        int *fb = new int[sLength+1];
        fb[0] = 1;
        fb[1] = 1;
        for(int i=2; i<sLength+1; ++i)
        {
            fb[i] = 0;//初始值必须为0，实例：输入“100”，输出0。
            if(('0' < s[i-1]) && (s[i-1] <= '9'))
            {
                fb[i] = fb[i] + fb[i-1];
            }
            if(('0' < s[i-2]) && (s[i-2] < '3'))
            {
                if((('2' == s[i-2]) && ('6' < s[i-1])))
                {//什么也不做
                }
                else
                {
                    fb[i] = fb[i] + fb[i-2];
                }
            }
        }
        return fb[sLength];
    }
};
```