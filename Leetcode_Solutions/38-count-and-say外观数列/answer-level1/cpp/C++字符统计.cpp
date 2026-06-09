![截屏2020-04-10下午12.53.42.png](https://pic.leetcode-cn.com/ec14541eaec5e39efb7b1e3a732969bd0a2d67be4f3b40200ab227d171657e9b-%E6%88%AA%E5%B1%8F2020-04-10%E4%B8%8B%E5%8D%8812.53.42.png)

### 解题思路
从 “1” 开始逐个计算直到第 n 个 字符串，具体思路见代码。

### 代码

```cpp
class Solution {
public:
    string countAndSay(int n) {
        string pre;     //用于保存待统计数字串
        string res = "1";   //用于保存结果
        for(int i = 1; i < n; ++i)  // 从1开始，如果 n=1 则直接输出结果 res
        {
            pre = res;      // 更新待统计数字串
            res.clear();    // 清空上一个统计的结果，用于保存当前统计结果
            int cnt = 0;    // 保存同一字符出现的次数
            char preChar = pre[0];  // 当前待统计字符
            for(int j = 0; j < pre.size(); ++j)
            {
                if(pre[j] == preChar){
                    ++cnt;      // 字符不变则递加统计值cnt
                }
                else{       // 字符改变
                    res.push_back(cnt + '0');   // 保存上一字符的个数
                    res.push_back(preChar); // 保存上一字符
                    preChar = pre[j];   // 更新待统计字符
                    cnt = 1;    // 待统计字符初始数目
                }
            }
            res.push_back(cnt + '0'); // 保存最后一个统计的字符数目
            res.push_back(preChar); //保存最后一个统计的字符
        }
        return res;
    }
};
```