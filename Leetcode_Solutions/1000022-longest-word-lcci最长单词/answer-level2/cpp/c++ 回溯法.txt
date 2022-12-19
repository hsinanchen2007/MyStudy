### 解题思路
先把所有单词按从长到短,字典序排序,再遍历,则第一个遍历到的可以由其他单词组成的单词就是答案
再思考如何判断一个词能否由其他单词组成:
- 考虑到一个单词可能由好多个单词合成，所以用剪枝回溯法
### 代码

```cpp
class Solution {
public:
    bool flag = false;
    static bool cmp(const string& a, const string& b){//从长到短，字典序
        if(a.size() != b.size())
            return a.size() > b.size();
        else
            return a < b;
    }
    //回溯法判断，word[idx...]能否由字典里的单词组成
    bool judge(string& word, int idx, unordered_map<char, unordered_set<string>>& m){
        if(flag) return true;
        if(idx == word.size()){
            flag = true;
            return true;
        }
        for(auto it = m[word[idx]].begin(); it != m[word[idx]].end(); it++){
            int len = (*it).size();
            if(len <= word.size()-idx){
                string cur = word.substr(idx, len);
                if(cur == *it && cur != word){
                    if(judge(word, idx+len, m))
                        return flag;//提前终止for循环
                }
            }
        }
        return flag;
    }
    string longestWord(vector<string>& words) {
        int len = words.size();
        if(len <= 1) return "";
        sort(words.begin(), words.end(), cmp);
        unordered_map<char, unordered_set<string>> m;//存储以各个字符开头的单词有哪些
        for(int i = 0; i < len; i++)
            m[words[i][0]].insert(words[i]);
        for(int i = 0; i < len; i++){
            if(judge(words[i], 0, m))
                return words[i];
        }        
        return "";
    }
};
```