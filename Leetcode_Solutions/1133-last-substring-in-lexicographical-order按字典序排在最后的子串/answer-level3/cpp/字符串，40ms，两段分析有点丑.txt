最开始是后面那个循环，vector存当前最大的字母位置，每个循环依靠现有的位置继续比较下一个位置的字母大小。

但这样会在全是同一个字母的时候超时，就在前面重新加了一个单次的循环，如果当前最大字母且最长连续字符串只有一个，就输出它，否则进后面的循环。

```
class Solution {
public:
    string lastSubstring(string s) {
        vector<int> pos;
        string ans;
        int count = 0, maxCount = 0, fuck = 0, tmpAns = 0;
        char tmpMin = 'a';
        for(int i = 0; i < s.size(); i++) {
            pos.push_back(i);
            if(i>0 && s[i] != s[i-1]) {
                if(s[i] == tmpMin) {
                    if(maxCount == count) fuck++;
                    maxCount = maxCount > count ? maxCount: count;
                }
                count = 0;
            }
            if(s[i] > tmpMin) {
                fuck = 0;
                tmpMin = s[i];
                tmpAns = i;
            }
            if(s[i] == tmpMin) count++;
        }
        if(fuck == 0) return s.substr(tmpAns);
        
        count = 0;
        while(pos.size() != 1) {
            char tmp = 'a';
            vector<int> tmpPos;
            for(int i = 0; i < pos.size(); i++) {
                if(pos[i] + count >= s.size()) continue;
                if(s[pos[i]+count] > tmp) {
                    tmpPos.clear();
                    tmp = s[pos[i]+count];
                    tmpPos.push_back(pos[i]);
                    //cout << pos[i] << " ";
                }
                else if(s[pos[i]+count] == tmp) tmpPos.push_back(pos[i]);
            }
            pos = tmpPos;
            count++;
            //cout << endl;
        }
        return s.substr(pos[0]);
    }
};
```
