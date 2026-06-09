### 解题思路

思路：单调栈
1、推演一下就好，比较简单不介绍了
2、有个坑点注意下，单调栈删除数据之后，K值可能是没减少到0的，也就是说达成了单调递增栈的情况，但是题目的目标还没满足，可以简化处理，计算最终需要返回的字符个数，再进行消除首部0

8ms 8.5M
--- wangtao HW-2020/3/11

### 代码

```cpp
class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> stack;
        int m = num.size() - k;
        
        for (int i = 0; i < num.size(); i++) {
            int c = num[i];

            while (stack.size() != 0 && k > 0 && c < stack.back()) {
                stack.pop_back();
                k--;
            }
            stack.push_back(num[i]);
        }
        string ans = "";
        // 如果上面删的不够的话，最终是要返回m个数字
        int numbegin = 0;
        int cnt = 0;
        for (auto c : stack) {
            cnt++;
            if (cnt > m) {
                break;
            }
            if (c == '0' && numbegin == 0) continue;
            numbegin = 1;
            ans += c;
        }
        ans = ans == "" ? "0" : ans;
        return ans;
    }
};
```