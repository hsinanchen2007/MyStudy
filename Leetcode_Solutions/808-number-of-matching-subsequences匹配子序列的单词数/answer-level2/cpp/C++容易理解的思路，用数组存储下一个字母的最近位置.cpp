C++数组模拟，没有去重，首先我们可以用二维数组pos[S.size()][26],存储母串当前位置需要匹配下一个字母的最近位置,如果我们正着去遍历预处理pos数组的话，每次都需要将字符串遍历一遍(最坏情况)，我们知道最近位置是唯一的，那么如果我们倒着遍历S去处理pos的话，上一个位置的pos数组是可以被继承到当前位置的，当前位置只需要更新下当前字母的位置即可。
我们记pos[i][S[i] - 'a'] = i为当前字母的位置其余的pos[i]['a' ~ 'z'] = pos[i + 1]['a' ~ 'z']即可。
注意我们当前字母等于当前位置，如果遇到待匹配串有连续相同的字母的话，需要手动将当前位置+1
```
class Solution {
public:
    int pos[50005][27];
    int numMatchingSubseq(string S, vector<string>& words) {
        int len = S.size();
        memset(pos, -1, sizeof pos);
        pos[len - 1][S[len - 1] - 'a'] = len - 1;
        for (int i = len - 2; i >= 0; i--) //预处理
        {      
            for (int j = 0; j < 26; j++) pos[i][j] = pos[i + 1][j];
            pos[i][S[i] - 'a'] = i;
        }
        int cnt = 0;
        for (auto& s : words)
        {
            int x = 0, p = 0;
            while (p < s.size() && pos[x][s[p] - 'a'] != -1)
            {
                x = pos[x][s[p] - 'a'];
                p++;
                if (s[p] == s[p - 1]) x++; //相同字母 需要加 1
            }
            if (p == s.size())
            {
                cnt++;
            } 
        }
        return cnt;
    }
};
```
