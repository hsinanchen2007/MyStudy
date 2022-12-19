看到这道题目，首先想到的是回溯算法，按照回溯思路编写代码如下：
```
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        vector<string> res;
        string tmp="";
        helper(res,s,tmp,0,dict);
        sort(res.begin(),res.end());
        return res;
    }
    void helper(vector<string>& res, string s, string tmp, int pre, unordered_set<string>& dict) {
        if (pre >= s.size()) {
            res.push_back(tmp);
            return;
        }
        for (int i = pre; i<s.size(); i++) {
            if (dict.count(s.substr(pre, i - pre + 1))) {
                int len = tmp.size();
                tmp += s.substr(pre, i - pre + 1) + (i==(s.size())-1?"":" ");
                helper(res, s, tmp, i + 1, dict);
                tmp.erase(len, tmp.size() - len + 1);
            }
        }
    }
};
```
可以通过大部分的情况，但是有种情况一直超出时间限制，就是全是相似的字符串这种问题：

```python []
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
```
因此需要对上面算法进行优化，避免重复计算，参考各位大佬们的答案之后，将每个字符串对应的结果保存在map结构中，这样可以减少重复运算，最终实现如下，可以成功通过。
回溯+剪枝，利用一个map保留键值映射，想相当于加入剪枝操作，可以对之前计算过的避免重复计算，进而加速计算过程，注意helper中的m.count(s)的判断非常必要，如果已经存在就直接调用之前计算的结果，加速计算。
```
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,vector<string> > m;
        return helper(m,wordDict,s);
    }
    vector<string> helper(unordered_map<string,vector<string> >& m,vector<string>& wordDict,string s){
        if(m.count(s)) return m[s];
        if(s.empty()) return {""};
        vector<string> res;
        for(auto word:wordDict){
            if(s.substr(0,word.size())!=word) continue;
            vector<string> tmp=helper(m,wordDict,s.substr(word.size()));
            for(auto itm:tmp){
                res.push_back(word+(itm.empty()?"":" "+itm));
            }
        }
        m[s]=res;
        return res;
    }
};
```