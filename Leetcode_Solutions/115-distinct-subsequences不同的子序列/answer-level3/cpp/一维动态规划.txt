其实和二维动态规划思路一样，只不过用高度为2的数据就可以解决了，而不需要太高。


执行用时 :
12 ms
, 在所有 C++ 提交中击败了
78.22%
的用户

内存消耗 :
9.2 MB
, 在所有 C++ 提交中击败了
74.14%
的用户

```c++
class Solution {
public:
    int numDistinct(string s, string t) {
        int ls = s.length(), lt = t.length();
        if(ls < lt)
            return 0;
        vector<long long> tmp(ls+1, 0);
        vector<vector<long long> > table(2, tmp);
        for(int i = 0;i <= ls;++i){
            table[0][i] = 1;
        }
        int current = 1, last = 0;
        for(int i = 1;i <= lt;++i){
            for(int j = i;j <= ls;++j){
                if(s[j-1] == t[i-1]){
                    long long left = j == i ? 0 : table[current][j-1];
                    long long up = table[last][j-1];
                    table[current][j] = left + up;
                }
                else{
                    table[current][j] = j == i ? 0 : table[current][j-1];
                }
            }
            int tmp = last;
            last = current;
            current = tmp;
        }
        return table[last][ls];
    }
};
```
