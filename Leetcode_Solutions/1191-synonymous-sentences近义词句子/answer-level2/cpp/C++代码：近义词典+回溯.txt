![image.png](https://pic.leetcode-cn.com/0d9c6fae41e2a9e2a9d6c793c72026aaf5004f4717565329df7f1469923e1e8c-image.png)

使用`unordered_map<string, unordered_set<string> *>`来存储每个词对应的近义词集合，其内容不需要排序。

```c++
class Solution {
public:
    void backtracking(set<string>& res, vector<string>& words, unordered_map<string, unordered_set<string> *>& similar, int index){
        for(int i = index; i < words.size(); i++){
            if(similar.count(words[i]) > 0){
                string tmp = words[i];
                for(auto s : (*(similar[tmp]))){
                    if(s == tmp) continue;
                    words[i] = s;
                    string r = "";
                    for(int i = 0; i < words.size(); i++)
                    {
                        r += words[i];
                        if(i != words.size() - 1) r += " ";
                    }
                    res.insert(r);
                    backtracking(res, words, similar, i + 1);
                }
                words[i] = tmp;
            }
        }
    }
    
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        set<string> res;
        vector<string> words;
        int l = 0, r, p = text.find(' ', l), n = text.length();
        while(p != -1)
        {
            r = l;
            while(r < n && text[r] != ' ') r++;
            words.push_back(text.substr(l, r - l));
            l = r + 1;
            p = text.find(' ', l);
        }
        words.push_back(text.substr(l));
        unordered_map<string, unordered_set<string> *> similar;
        for(vector<string> iter : synonyms){
            if(similar.count(iter[0]) > 0){
                similar[iter[1]] = similar[iter[0]];
                similar[iter[0]]->insert(iter[1]);
            }
            else if(similar.count(iter[1]) > 0){
                similar[iter[0]] = similar[iter[1]];
                similar[iter[1]]->insert(iter[0]);
            }
            else{
                unordered_set<string> *tmp = new unordered_set<string>;
                similar[iter[0]] = tmp;
                similar[iter[1]] = tmp;
                tmp->insert(iter.begin(), iter.end());
            }
        }
        backtracking(res, words, similar, 0);
        res.insert(text);
        return vector<string>(res.begin(), res.end());
    }
};
```

注释版本：
```c++
class Solution {
public:
    // 回溯
    void backtracking(set<string>& res, vector<string>& words, unordered_map<string, unordered_set<string> *>& similar, int index){
        // 从index开始顺次替换当前句子中在近义词表中的词
        for(int i = index; i < words.size(); i++){
            // 当前词在近义词表中
            if(similar.count(words[i]) > 0){
                // 记录原词
                string tmp = words[i];
                // 依次替换
                for(auto s : (*(similar[tmp]))){
                    // 跳过原词
                    if(s == tmp) continue;
                    words[i] = s;
                    // 合成句子
                    string r = "";
                    for(int i = 0; i < words.size(); i++)
                    {
                        r += words[i];
                        if(i != words.size() - 1) r += " ";
                    }
                    // 存入结果
                    res.insert(r);
                    // 从下一个位置继续回溯
                    backtracking(res, words, similar, i + 1);
                }
                words[i] = tmp;
            }
        }
    }
    
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        set<string> res;
        vector<string> words;
        // 根据空格分词
        int l = 0, r, p = text.find(' ', l), n = text.length();
        while(p != -1)
        {
            r = l;
            while(r < n && text[r] != ' ') r++;
            words.push_back(text.substr(l, r - l));
            l = r + 1;
            p = text.find(' ', l);
        }
        words.push_back(text.substr(l));
        // 记录近义词表
        unordered_map<string, unordered_set<string> *> similar;
        for(vector<string> iter : synonyms){
            if(similar.count(iter[0]) > 0){
                similar[iter[1]] = similar[iter[0]];
                similar[iter[0]]->insert(iter[1]);
            }
            else if(similar.count(iter[1]) > 0){
                similar[iter[0]] = similar[iter[1]];
                similar[iter[1]]->insert(iter[0]);
            }
            else{
                unordered_set<string> *tmp = new unordered_set<string>;
                similar[iter[0]] = tmp;
                similar[iter[1]] = tmp;
                tmp->insert(iter.begin(), iter.end());
            }
        }
        // 回溯
        backtracking(res, words, similar, 0);
        // 存入原句
        res.insert(text);
        return vector<string>(res.begin(), res.end());
    }
};
```