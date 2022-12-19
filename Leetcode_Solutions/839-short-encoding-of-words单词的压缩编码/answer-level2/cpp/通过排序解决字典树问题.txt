### 解题思路
1、由于是后缀匹配，使用reverse倒置所有字符串；
2、对所有字符进行字典序排序+长度排序；
3、通过2，就会使得这个字符串必然是下一个字符串的前缀或者不符合；
4、逐个比较当前字符串是否是下一个字符串，是就继续，不是就把当前字符串的长度+1加到结果中。

### 代码

```cpp
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        for (int i=0; i<words.size(); i++) reverse(words[i].begin(), words[i].end());
        sort(words.begin(), words.end(), cmp);
        int re=0;
        for (int i=0; i<words.size()-1; i++){
            if (words[i+1].substr(0, words[i].size())==words[i]) continue;
            else re+=words[i].size()+1;
        }
        re+=words[words.size()-1].size()+1;
        return re;
    }
    static bool cmp(string a, string b){
        int len=min(a.size(), b.size());
        int i=0;
        while(a[i]==b[i] && i<len) i++;
        if (a[i] != b[i]) return a[i] < b[i];
        else return a.size() < b. size(); 
    }
};
```