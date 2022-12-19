要求给定一个字符串text，返回一个子字符序列，要求可以涵盖其中所有的字符，同时还要确保必须是字典序排列~
思路：
统计所有字符出现的次数，
如果当前字符已经在子序列中出现过，就跳过，因为要求只出现一次。
如果当前子字符序列上面的最后一个词a大于下一个待判断字符b，同时后面确定还有a存在，那么就可以放心删掉a了，如果后面没有a存在了，那么就不能删掉a。

编程实现：
```
class Solution {
public:
    string smallestSubsequence(string text) {
        string res="";
        vector<int> num(26,0);
        vector<int> used(26,0);
        for(auto c:text) num[c-'a']++;
        for(int i=0;i<text.size();i++){
            num[text[i]-'a']--;
            if(used[text[i]-'a']) continue;
            while(!res.empty() && res.back()>text[i] && num[res.back()-'a']){
                used[res.back()-'a']--;
                res.pop_back();
            }
            res.push_back(text[i]);
            used[text[i]-'a']++;
        }
        return res;
    }
};
```
