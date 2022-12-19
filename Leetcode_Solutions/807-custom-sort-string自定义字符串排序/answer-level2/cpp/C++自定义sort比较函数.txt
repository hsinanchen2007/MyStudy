以写结构体，重载 () 的方式自定义 sort 的比较函数。结构体内部可以维护从 S 获得的字典序信息

```C++
class Solution {
public:
    string customSortString(string S, string T) {
        int n = S.size();
        if(n <= 1) return T;
        vector<int> char_idx(26, -1);
        for(int i = 0; i < n; ++i)
            char_idx[S[i] - 'a'] = i;
        Dictionary_less dictionary_less(char_idx);
        sort(T.begin(), T.end(), dictionary_less);
        return T;
    }

private:
    struct Dictionary_less 
    {
        vector<int> char_idx;

        Dictionary_less(vector<int> mapping):char_idx(mapping) {}

        bool operator() (const char& c1, const char& c2)
        {
            return char_idx[c1 - 'a'] < char_idx[c2 - 'a'];
        }
    };
};

```
