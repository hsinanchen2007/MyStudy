### 解题思路

这个题其实就是从 `words` 中取出一个单词，然后到 `chars` 中去找字符看是否能组成这个单词。唯一需要考虑的是， `chars` 中的每个字符在一个单词中只能使用一次，所以应该标记已经使用过的单词。

首先如果 `words` 或 `chars` 为空，则直接返回0，因为不可能有能拼写的单词。然后定义一个 `length` 并将其初始化为0，用于保存掌握的单词的长度和，遍历 `words` 中的所有单词，定义一个和字母表中字符个数相同的 `vector<int>` 数组 `mark[]`，将其初始化为全1，表示所有字符均未被使用，然后二层循环遍历每个单词的所有字母，然后第三层循环遍历 `chars` 查找是否有还未使用过的这个字母，如果有，将 `chars` 中的这个字母标记为已经用，即 `mark[j] = 0;` ，继续循环查找下一个字母。只要三层循环中有一个字母找不到，则表示这个单词不能拼写，应直接查找下一个单词。找到一个能拼写的单词，就将这个单词的长度加到 `length` 上。循环上述步骤，直到遍历完 `words` 。

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        if (words.empty() || chars.empty())
            return 0;
        int length = 0;//总长度
        int n = chars.length();
        for (auto word : words) {
            bool b = true;//该单词能否拼写
            vector<int> mark(n, 1);//标记字符是否被使用，0为已使用，1为未使用
            for (auto c : word) {
                bool findc = false;//是否有没被使用过的这个字符
                for (int j = 0; j < n; j++) {
                    if (c == chars[j] && mark[j] == 1) {
                        findc = true;
                        mark[j] = 0;//该字符被使用
                        break;
                    }
                }
                //只要有一个字符没找到则这个单词不能拼写
                if (findc == false) {
                    b = false;
                    break;
                }
            }
            if (b == true) {
                length += word.length();
            }
        }
        return length;
    }
};
```