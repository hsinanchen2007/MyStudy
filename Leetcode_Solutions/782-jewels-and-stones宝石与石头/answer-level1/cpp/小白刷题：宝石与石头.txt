设一长度52的bool数组表示对应字母是否为宝石，两字符串各遍历一遍即可

代码：
```
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int jlen = J.length();
        int slen = S.length();
        int ans = 0;
        bool letter[52] = {false};
        for (int i = 0; i < jlen; i++) {
            if (J[i] >= 'A' && J[i] <= 'Z')
                letter[(int)J[i] - 65] = true;
            else if (J[i] >= 'a' && J[i] <= 'z')
                letter[(int)J[i] - 71] = true;
        }
        for (int i = 0; i < slen; i++) {
            if (S[i] >= 'A' && S[i] <= 'Z' && letter[(int)S[i] - 65])
                ans++;
            else if (S[i] >= 'a' && S[i] <= 'z' && letter[(int)S[i] - 71])
                ans++;
        }
        return ans;
    }
};
```
