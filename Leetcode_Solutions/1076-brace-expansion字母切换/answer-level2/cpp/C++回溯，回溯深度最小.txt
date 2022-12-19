***Talk is cheap. Show me the code.***

复用同样的内存空间去得到每个单词，回溯深度和花括号的对数一样！


```cpp
class Solution {
public:
    vector<string> expand(string S) {
        generateTable(S);
        backtrack(0);
        sort(results.begin(), results.end());    // 真是不想吐槽返回字典顺序这个要求了，判题系统不能自己去判断乱序的答案吗？
        return results;
    }
    
    void generateTable(const string &S) {
        for(auto i = 0; i < S.size(); i++) {
            if (S[i] == '{') {
                string tmp;
                i++;
                while (S[i] != '}') {
                    if(S[i] != ',') tmp.push_back(S[i]);
                    i++;
                }
                table.push_back(make_pair(result.size(), tmp));    // 记录备选项和备选项的位置！
                result.push_back(' ');
            } else {
                result.push_back(S[i]);    // 这些必选项就不再动它了
            }
        }
    }
    
    void backtrack(int round) {
        if (round == table.size()) {
            results.push_back(result);
            return;
        }
        for (int i = 0; i < table[round].second.size(); i++) {
            result[table[round].first] = table[round].second[i];
            backtrack(round+1);
        }
    }
    
private:
    string result;                          // 内存复用
    vector<pair<int, string>> table;        // 记录备选项和备选项的位置！
    vector<string> results;     
};

```