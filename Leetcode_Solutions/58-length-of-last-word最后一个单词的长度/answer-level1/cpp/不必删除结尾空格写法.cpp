可以再用一个变量res一直记录当前的单词长度不清零，本来的计数变量count碰到 空格 就清零即可。
```
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size();
        int count = 0;
        int res = 0;

        for(int i=0; i<len; i++)
        {
            if(s[i] != ' ')
            {
                count++;
                res = count;
            }
            else{
                count = 0;
            }
        }

        return res;
        
        
    }
};
```
