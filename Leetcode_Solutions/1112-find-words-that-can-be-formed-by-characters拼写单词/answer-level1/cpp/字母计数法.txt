### 解题思路
1：因为说了仅大写字母或者小写字母，所以可以利用int[26]来计算字母出现次数
2：然后计算出字母表里的字母出现次数
3：计算出单词组里每个单词字母出现次数
4：检查单词字母出现次数是否超过了字母表里字母出现次数

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> chars_count =  count(chars);
        int res = 0;
        for(string& word : words){
            vector<int> word_count = count(word);
            if(contains(chars_count, word_count)){
                res += word.length();
            }
        }
        return res;
    }
    //检查单词的字母出现次数是否超过字母表中的出现次数
    bool contains(vector<int>& chars_count,vector<int> word_count){
        for(int i=0;i<26;i++){
            if(chars_count[i] < word_count[i]){
                return false;
            }
        }
        return true;
    }

    //统计字母出现次数
    vector<int> count(string& word){
        vector<int> counter(26,0);//创建一个counter数组，size为26，初始值为0
        for(char c : word){
            counter[c-'a']++;
        }
        return counter;
    }
};
```