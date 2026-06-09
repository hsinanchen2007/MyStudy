### 解题思路
1. 设计一个有效长度状态记录器(有效指左右括号数量相同)
2. 第一遍从左到右遍历, '('记为+1, ')'记为-1, sum记录代数和就能监听有效长度
3. 每一次达成有效长度, 更新validLen, 如果达到退出状态即sum=-1, 刷新max
4. 第二遍同理从右到左, ')'记为+1, '('记为-1
5. 需要两遍的原由是, 上述第一遍时对于((()这样的串, 获取不到任何一个有效状态, 转换成)(((, 再把记录方式翻转, 就能获取到

### 代码

```cpp
class Solution {
public:
    int longestValidParentheses_single_dir(string s, int i, int flag, int end, char ch){
        int max = 0, sum = 0, currlentLen = 0, validLen = 0;
        while (i!=end){
            sum += (s[i] == ch ? 1 : -1);
            currlentLen++;
            if (sum == 0) validLen = currlentLen;
            else if (sum < 0){
                max = max > validLen ? max : validLen;
                sum = currlentLen = validLen =  0;
            }
            i+=flag;
        }
        return max > validLen ? max : validLen;
    }
    int longestValidParentheses(string s) {
        return max(longestValidParentheses_single_dir(s, 0, 1, s.size(), '('),
        longestValidParentheses_single_dir(s, s.size()-1, -1, -1,')'));
    }
};
```