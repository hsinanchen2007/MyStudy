## 解法：哈希表计数法

求解此题的关键在于，如何理解题目中所表述的“拼写”。通过分析发现，想要使用字符表拼写出单词表中的单词，**单词中每一个字母出现的次数就必须小于或等于字符表中对应字母出现的次数**（题目要求，不得重复使用字符表中的字符）。

进行了上述的思路转换，该题目就很容易求解了。

* 首先使用哈希表统计字符表中每一个字符出现的次数；
* 接着，逐个每个单词的字母出现的次数，并将其重复次数与字符表中对应字母的次数进行对比，如果该单词中的所有字母的次数都满足要求，则将该单词的长度加入最终的长度中。

代码如下：

```c++
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char, int> char_count;
        // 统计chars中每一个字符出现的次数
        for (auto single_char: chars){
            char_count[single_char]++;
        }

        int length = 0;
        for (auto word: words){
            // 统计当前word中每一个字符出现的次数
            map<char, int> word_char_count;
            for (auto single_char: word){
                word_char_count[single_char]++;
            }
            bool spell = true;
            for (auto item: word_char_count){
                if (item.second > char_count[item.first]){
                    spell = false;
                    break;
                }
            }
            if (spell == true)
                length += word.size();
        }
        return length;
    }
};
```

时间复杂度：$O(n)$，$n$为字符表和单词表中所有字符的总长度；

空间复杂度：$O(s)$，$s$为字母的个数，额外的空间均由哈希表带来。

## 解法：对哈希表进行优化

实际上，上述程序还有很大的优化空间：

* 可以不使用`STL`原生的`map`：因为字符最多只有26个，所以可以申请一个大小为26的`vector`，将字母映射为下标即可；
* 在进行是否可以拼写的判定时，可以在每一次字母次数的统计之后就进行判断，这样可以省去一些统计步骤。

优化判定步骤的代码：

```c++
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char, int> char_count;
        // 统计chars中每一个字符出现的次数
        for (auto single_char: chars){
            char_count[single_char]++;
        }

        int length = 0;
        for (auto word: words){
            // 统计当前word中每一个字符出现的次数，统计次数的同时判断是否可以被拼写出
            map<char, int> word_char_count;
            bool spell = true;
            for (auto single_char: word){
                word_char_count[single_char]++;
                if (word_char_count[single_char] > char_count[single_char]){
                    spell = false;
                    break;
                }
            }
            if (spell == true)
                length += word.size();
        }
        return length;
    }
};
```

使用`vector`替代`map`的代码：

```c++
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> char_count(26, 0);
        // 统计chars中每一个字符出现的次数
        for (auto single_char: chars){
            char_count[single_char - 'a']++;
        }

        int length = 0;
        for (auto word: words){
            // 统计当前word中每一个字符出现的次数，统计次数的同时判断是否可以被拼写出
            vector<int> word_char_count(26, 0);
            bool spell = true;
            for (auto single_char: word){
                word_char_count[single_char - 'a']++;
                if (word_char_count[single_char - 'a'] > char_count[single_char - 'a']){
                    spell = false;
                    break;
                }
            }
            if (spell == true)
                length += word.size();
        }
        return length;
    }
};
```