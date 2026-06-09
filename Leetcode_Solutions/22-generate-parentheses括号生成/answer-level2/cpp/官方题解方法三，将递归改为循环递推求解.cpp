### 解题思路
*此解法参考了官方题解方法三，将递归改为了循环递推*


对任意非空的有效括号序列`s`,我们都可以将`s`表达成`(a)b`的形式，其中`a`,`b`均为有效括号序列。注意到`s`括号对数 = `a`括号对数 + `b`括号对数 + 1, 这就构成了递推关系。

令`cache[i]`代表`i`对括号所有可能的组合。
1. 显然`cache[0]`为`{""}`，因为0对括号只有可能是空字符串；
2. 然后递推计算`cache[i]`: `cache[i]`中的序列可以写成`(a)b`的形式。设`a`括号对数为`j`，那么`b`括号对数就为`i-j-1`。因此`cache[i]`中的序列可以由`cache[j]`内序列与`cache[i-j-1]`内序列拼接得到。

这样，令`i`从`1`到`n`循环，再在内层令`j`从`0`到`i-1`循环，将`cache[j]`与`cache[i-j-1]`所有可能的组合拼接成序列加入`cache[i]`。最终`cache[n]`就是我们想要的结果。

### 代码

```cpp
class Solution {
    shared_ptr<vector<string>> cache[100] = {nullptr};
public:
    vector<string> generateParenthesis(int n) {
        cache[0] = shared_ptr<vector<string>>(new vector<string>{""});
        for(int i=1;i<=n;i++){
            cache[i] = shared_ptr<vector<string>>(new vector<string>);
            for(int j=0;j<i;j++){
                auto lefts = cache[j];
                auto rights = cache[i-j-1];
                for (const string& left : *lefts)
                    for (const string& right : *rights)
                        cache[i] -> push_back("(" + left + ")" + right);
            }
        }
        return *cache[n];
    }
};
```