主要是统计各个字母出现的次数，然后取出最小值。
```
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> tmp(5, 0);
        for(int i = 0; i < text.length(); ++i)
        {
            if(text[i] == 'b')
                tmp[0]++;
            else if(text[i] == 'a')
                tmp[1]++;
            else if(text[i] == 'l')
                tmp[2]++;
            else if(text[i] == 'o')
                tmp[3]++;
            else if(text[i] == 'n')
                tmp[4]++;
        }
        tmp[2] /= 2;
        tmp[3] /= 2;
        int t1 = min(tmp[4], min(tmp[3], tmp[2]));
        int t2 = min(tmp[1], tmp[0]);
        return t1>t2?t2:t1;
    }
};
```
