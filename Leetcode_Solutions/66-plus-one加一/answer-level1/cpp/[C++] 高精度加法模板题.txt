### 分析：
- 这个题目实际就是大数加法的简化版，只考虑+1的特殊情况
- 逆序遍历`digits`数组，每次循环将`digits`的元素加到`t`上
- 仅当第一次遍历（个位）时使`t`额外加1
- 将当前位结果`t%10`存到答案`res`里
- 用`t/10`表示进位并进入下一次循环
- 遍历后，如果最高位仍有进位则补1
- 翻转数组得到答案
### 代码：
```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int t = 0;
        for(int i = digits.size() - 1; i >= 0; i--) {
            t += digits[i];
            if(i == digits.size() - 1) t += 1;
            res.push_back(t % 10);
            t /= 10;
        }
        if(t) res.push_back(1);
        reverse(res.begin(), res.end());
        return res;
    }
};
```
### 相关：
- [高精度加法模板及应用](https://leetcode-cn.com/circle/article/AGF5sg/)
- [Add Two Numbers](https://leetcode-cn.com/problems/add-two-numbers/)
- [Add Two Numbers II](https://leetcode-cn.com/problems/add-two-numbers-ii/)
- [Add Binary](https://leetcode-cn.com/problems/add-binary/submissions/)