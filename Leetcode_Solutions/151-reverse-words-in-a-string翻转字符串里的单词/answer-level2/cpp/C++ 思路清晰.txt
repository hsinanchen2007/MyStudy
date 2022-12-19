首先去空格，找到每个单词，然后把单词存到vector里，然后reverse，连接

```
class Solution {
public:
    string reverseWords(string s) {
        int idx1 = 0, idx2 = 0;
        vector<string> ans;
        int n = s.length();
        while(idx1 < n && idx2 < n){
            while(s[idx1]== ' '&& idx1 < n) idx1++;
            idx2 = idx1;
            while(s[idx2] != ' ' && idx2 < n) idx2++;
            if(idx2 == idx1) break;
            string tmp  =s.substr(idx1, idx2 - idx1);
            ans.push_back(tmp);
            idx1 = idx2 + 1;
        }
        reverse(ans.begin(), ans.end());
        string ansstr = "";
        for(int i = 0; i < ans.size(); i++) {
             ansstr+= ans[i];
            if(i!=ans.size() - 1) ansstr+=" ";
        }
        return ansstr;

    }
};
```
