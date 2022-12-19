![image.png](https://pic.leetcode-cn.com/39985a428c7d68621ab1e532cdbd0367db7fbfabadbd225b21c9a692f67fad36-image.png)

思路就是，先把存在的字符串，放到 hashmap ，可以快速比较，然后每一个位置都进行匹配
但这里会有很多的重复计算，就可以使用一个小技巧，先计算目标串的每个字母的 ASCII 和， 
然后和当前要匹配的字符串的每个字母的 ASCII 进行比较，如果不相等就不用进行下面的匹配过程了

```
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(words.size()<1 || s.size()<1 || s.size() < words[0].size()*words.size()) return res;
        int wordLen = words[0].size(), lens = wordLen*words.size(), target = 0, cur = 0;
        unordered_map<string,int> allWord;
        for(auto& it:words){
            allWord[it]++;
            for(auto& i:it) target += i;
        }
        for(int i=0; i<lens; i++) cur += s[i];
        // 先看当前字符串的 ASCII 码相加是否相等 方便去重
        for(int i=0, j; i<=s.size()-lens; cur -= s[i], cur += s[lens + i++]){
            // 快速去重
            if(cur != target) continue;
            // 确认一下，是否为真的匹配
            unordered_map<string,int> tem(allWord);
            for(j=i; j<i+lens; j+=wordLen)
                if(tem[s.substr(j, wordLen)]-- == 0) break;
            if(j == i+lens) res.push_back(i);
        }
        return res;
    }
};
```

