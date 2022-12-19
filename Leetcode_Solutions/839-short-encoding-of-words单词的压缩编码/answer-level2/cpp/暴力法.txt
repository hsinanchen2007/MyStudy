### 解题思路
这个题目主要是理解题意，然后翻译出来即可：
1. 观察可以知道，如果单词A是单词B的后缀则可以将其去除，以index为起始#为结束即可；
2. 则对每一个word的所有后缀的情况进行一遍比对，然后数组中的对应word；
3. 将剩余的word + #的值返回；
4. 这里使用set/map应该都比较快；
5. 由于word不需要做任何变动，所以直接取原数组中位置即可，整体跑下来这样还快一些 

### 代码

```cpp
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        //这个题目题意就研究了好半天，理解了题意其实就比较简单了，indexes是word的索引位置，#是结束位置
        //也就是说如果一个单词是另一个单词的后缀，则不需要在S中加入
        unordered_set<string> S_word (words.begin(), words.end());
        int result = 0;
        for(const string &word:words){
            for(int i=1; i<word.size();i++){
                S_word.erase(word.substr(i));
            }
        }
        for(const string &word:S_word) {
            result += word.size()+1;
        }
        return result;
    }
};
```