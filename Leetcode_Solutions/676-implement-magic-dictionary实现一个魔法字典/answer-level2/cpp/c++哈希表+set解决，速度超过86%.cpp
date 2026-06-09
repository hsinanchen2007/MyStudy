将dict中每个单词的字母逐个替换成！然后作为map的key放入map中，map的value是这个键出现的次数，并用一个set保存dict的所有字符串。
查询的时候，依次替换被查询单词每个字母为！，找到最大的value，如果是0或者是1且原dict出现过则返回false，否则是true；
```
class MagicDictionary {
private:
    unordered_map<string, int> magicDict;
    unordered_set<string> originlDict;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(auto &dic : dict) {
            originlDict.insert(dic);
            char tmp;
            for(int i = 0; i < dic.length(); i++) {
                tmp = dic[i]; dic[i] = '!';
                magicDict[dic]++;
                dic[i] = tmp;
            }
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        char tmp, cnt = 0;
        for(int i = 0; i < word.length(); i++) {
            tmp = word[i]; word[i] = '!';
            if(cnt < magicDict[word]) cnt = magicDict[word];
            word[i] = tmp;
        }
        if(cnt == 0 || (cnt == 1 && originlDict.find(word) != originlDict.end())) return false;
        return true;
    }
};
```
![微信图片_20191230160344.png](https://pic.leetcode-cn.com/06dd2741fcd7888ac658cd4c060b04ff3f5147dc9018f7041c73a336298151d5-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20191230160344.png)
