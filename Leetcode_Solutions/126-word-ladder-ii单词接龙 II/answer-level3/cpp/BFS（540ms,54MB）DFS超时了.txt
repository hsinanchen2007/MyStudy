```
private:
    bool canTrans(string const& s1, string const& s2) {
        if (s1.size() != s2.size()) return false;
        int count = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) count++;
        }
        return count == 1;
    }
    
public: // BFS 488ms 119.8MB
    /*
        dfs查找下一个符合条件的单词， 并且遍历完这层后删除掉符合条件的单词（题意只要最短，下一次有符合这层删除的词说明至少比当前层次要多一步），比较的时候用到的是上一层符合条件的单词替换一个字母（而不是剩余wordList进行遍历(m*26 与m*n(wordList)))算法上的区别
    */
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    vector<vector<string>> res;
    std::queue<pair<string, vector<string>>> trace;
    int curCount = 0;
    trace.push(make_pair(beginWord, vector<string>{beginWord}));

    bool isEnd = false;
    unordered_set<string> dels;
    unordered_set<string> curs{wordList.begin(), wordList.end()};
    pair<string, vector<string>> oneTrace;
    string traceStr;
    curs.erase(beginWord);
    while(!trace.empty() && curs.count(endWord) != 0) {
        curCount = trace.size();
        while (curCount > 0) {
            oneTrace = trace.front();
            trace.pop();
            if (canTrans(oneTrace.first, endWord)) {
                oneTrace.second.push_back(endWord);
                res.push_back(oneTrace.second);
                isEnd = true;
            } else {
                if (!isEnd) {
                    for (int i = 0; i < oneTrace.first.size(); ++i) {
                        traceStr = oneTrace.first;
                        for (char c = 'a'; c <= 'z'; ++c) {
                            if (oneTrace.first[i] == c) continue;
                            traceStr[i] = c;
                            if (curs.count(traceStr) == 0) continue;
                            oneTrace.second.push_back(traceStr);
                            trace.push(make_pair(traceStr, oneTrace.second));
                            oneTrace.second.pop_back();
                            dels.insert(traceStr);
                        }
                    }
                }
            }
            
            curCount--;
        }
        if (isEnd) break;
        for (auto delw : dels) {
            curs.erase(delw);
        }
        dels.clear();
    }
    return res;
}
```
public: //DFS 超时了
    void findLaddersCore(const string& beginWord, const string& endWord, vector<string>& wordList, vector<string>& res, int curStep) {
        if (beginWord == endWord) {
            if (curStep <= minLen_) {
                minLen_ = curStep;
                res.push_back(beginWord);
                ress_.push_back(res);
                res.erase(res.end()-1);
            }
            return;
        }
        if (curStep > minLen_) return;
        setS_.insert(beginWord);
        res.push_back(beginWord);
        for (auto word : wordList) {
            if (setS_.find(word) == setS_.end() && 
                canTrans(beginWord, word)) {
                findLaddersCore(word, endWord, wordList, res, curStep+1);
            }
        }
        res.erase(res.end()-1);
        setS_.erase(beginWord);
    }
```
代码块
```

