### 解题思路
遍历字符串，第一个字符到底要不要保留，和第二个有关系，同时有可能和第三个有关系，只能用栈先暂存，这就想到了栈！！！
利用栈处理，注意点：
    1、放入栈的字符次数不用减少，因为有迹可循；
    2、跳过的字符，需要将次数减少，因为后面就不能顶出来了；
    3、需要一个是否已经在栈里面的标记。

### 代码

```cpp
class Solution {
public:

string removeDuplicateLetters(string s)
{
    vector<int> wordTimes(26, 0);
    vector<bool> wordDone(26, false);
    for (auto chr : s) {
        wordTimes[chr - 'a']++;
    }
    string results("");
    for (auto chr : s) {
        if (results.empty()) {
            results.push_back(chr);
            wordDone[chr - 'a'] = true;
            continue;
        }
        if (wordDone[chr - 'a']) {
            wordTimes[chr - 'a']--;
            continue;
        }
        while(! results.empty() && chr < results.back() && wordTimes[results.back() - 'a'] != 1) {
            wordDone[results.back() - 'a'] = false;
            wordTimes[results.back() - 'a']--;
            results.pop_back();
        }
        results.push_back(chr);
        wordDone[chr - 'a'] = true;
    }
    return results;
}
};
```