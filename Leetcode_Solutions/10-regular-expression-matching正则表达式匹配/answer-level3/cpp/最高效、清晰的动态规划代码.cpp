动态规划别的题解讲了很多了，属于比较基本的内容。
由于该题具有最优子结构，使用f[i][j]表示模式串前i个字符和文本串前j个字符是否能匹配，然后普通字符/通配符 × 有星号和没有星号 共四种转移方式，容易写出方程。

但除了状态的表示和转移，动态规划难的一点还有特殊情况的处理，本题中即对于模式串中星号的处理（单独拿出来不能代表字符，导致转移时难以处理），还有初值和状态边界。
我使用了类来表示模式串中的一个通用字符，并在初始化时、字符串首尾添加了占位符，使得DP过程简单易懂，可读性高，debug难度大大降低。

以下是代码：

```
/*
 * 自定义字符类以方便DP处理，'.*'，'x*'等在匹配的语义中实际上是一个而不是两个字符。
 * 同时也cover '.'和占位符等特殊字符的处理。
 */
class CharPattern {
public:    
    static const char WILDCARD_CHAR = '.';
    static const char REPEATING_CHAR = '*';
    static const char PLACEHOLDER = '@';

    CharPattern()
        :_char(PLACEHOLDER), _repeating(false) {}

    size_t parseCharPattern(const string& s, size_t pos) {
        if (pos >= s.length()) {
            return 0;
        }
        _char = s[pos];

        if (pos + 1 < s.length() && s[pos + 1] == REPEATING_CHAR) {
            _repeating = true;
            return 2;
        }
        return 1;
    }
    
    bool canRepeat() const {
        return _repeating;
    }

    bool canOmit() const {
        return _repeating;
    }

    bool matchChar(char x) const {
        return ((_char == WILDCARD_CHAR) || (x == _char));
    }

private:
    bool _repeating;
    char _char;
};

class Solution {
    vector<CharPattern> pattern;
    vector<bool> isMatchBase;
    vector<bool> isMatchInfer;
public:
    /*
     *  使用自定义字符类重新定义模式串。
     *  同时为模式串和文本串首尾添加占位符，消灭DP中任何特殊情况的处理。
     */
    void init(string& s, const string& p) {
        pattern.push_back(CharPattern());
        for (size_t i = 0; i < p.length();) {
            CharPattern cp;
            i += cp.parseCharPattern(p, i);
            pattern.push_back(cp);
        }
        pattern.push_back(CharPattern());

        s.insert(s.begin(), CharPattern::PLACEHOLDER);
        s.insert(s.end(), CharPattern::PLACEHOLDER);

        isMatchBase.resize(s.size(), false);
        isMatchInfer.resize(s.size(), false);
        isMatchBase[0] = true;
    }
    /*
     * DP， 自底向上， 滚动数组
     */
    bool isMatch(string s, string p) {
        init(s, p);
        for (size_t i = 0; i+1 < pattern.size(); ++i) {
            isMatchInfer.assign(isMatchInfer.size(), false);
            for (size_t j = 0; j+1 < s.size(); ++j) {
                if (isMatchBase[j] == false) {
                    continue;
                }

                if (pattern[i].canRepeat() && pattern[i].matchChar(s[j+1])) {
                    isMatchBase[j+1] = true;
                }

                if (pattern[i+1].canOmit()) {
                    isMatchInfer[j] = true;
                }

                if (pattern[i+1].matchChar(s[j+1])) {
                    isMatchInfer[j+1] = true;
                }
            }
            swap(isMatchInfer, isMatchBase);
        }
        return isMatchBase.back();
    }
};
```
