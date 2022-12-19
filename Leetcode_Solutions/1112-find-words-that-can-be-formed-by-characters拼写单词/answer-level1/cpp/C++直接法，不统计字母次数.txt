思路：直接根据题目描述，对每个单词的每个字母进行检查，如果不在词汇表里就跳过；在词汇表里，删掉这个字母，继续比较，直到末尾。
看到题解里大多数用哈希表，我觉得哈希表对每个单词必然要进行一次完整遍历，速度上可能没有直接快。
```c++
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans = 0;
        for(int i = 0;i < words.size(); ++ i){
            string copy = chars;
            string word = words[i];
            for(int j = 0; j < word.length(); ++ j){
                int pos = copy.find(word[j]);
                if(pos == -1) break;
                copy.erase(pos,1);//找过的删掉
                if(j == word.length() - 1) ans += word.length();
            }
        }
        return ans;

    }
};


