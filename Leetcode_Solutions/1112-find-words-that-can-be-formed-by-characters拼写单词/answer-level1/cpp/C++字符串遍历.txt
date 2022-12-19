### 解题思路
此处撰写解题思路
注意点“每次拼写，chars中的每个字母都只能用一次”，代表words里每个单词里的字母，用了一次chars之后，需要剔除chars里的那个字母。当遍历到words的下一个单词时，chars又是完整的。
并不是所有单词里的字母只能用一次chars里的字母。因为理解错一次，导致花了一些时间。

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        if (chars.length() == 0) return 0;
        int sum = 0;
        bool flag = true;
        for (int i = 0; i < words.size(); i++)
        {
            string chars1 = chars;
            for (int j = 0; j < words[i].length(); j++)
            {
                if (chars1 == "") break;
                int index = chars1.find(words[i][j]);
                if (index == -1) break;
                if (index != -1)
                {
                    chars1.erase(index, 1);
                    if (j == words[i].length() - 1) {
                        sum += words[i].length();
                    }
                }
            
            }
        }
        return sum;
    }
};
```
执行结果：
    通过
执行用时 :
    76 ms, 在所有 C++ 提交中击败了61.76%的用户
内存消耗 :
    17.9 MB, 在所有 C++ 提交中击败了60.32%的用户