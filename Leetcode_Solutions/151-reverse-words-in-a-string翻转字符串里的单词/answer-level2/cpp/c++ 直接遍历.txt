```
class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int size = s.size();
        for(int i=size-1; i>=0; --i){ 
            int count = 0;
            while(i>=0 && s[i] !=' '){ 
                --i;
                ++count;  //统计一个单词的字母数量
            }
            if(count>0)
                ans += s.substr(i+1,count)+' ';  //截取单词
        }
        ans = ans.substr(0,ans.size()-1);  ////去除最后一个空格
        return ans;
    }
};
```
