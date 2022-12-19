```
class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> q;
        vector<int> w;
        fun(queries, q);
        fun(words, w);

        sort(w.begin(), w.end());

        vector<int> ans;
        for(int n : q)
        {
            auto ret = upper_bound(w.begin(), w.end(), n);
            if(ret == w.end())
            {
                ans.push_back(0);
            }
            else
            {
                int pos = ret - w.begin();
                ans.push_back(w.size() - pos);
            }
        }

        return ans;
    }

    void fun(const vector<string>& strs, vector<int>& vec)
    {
        for(string s : strs)
        {
            for(int i = 0; i < 26; i++)
            {
                char c = 'a' + i;
                int cur = count(s.begin(), s.end(), c);
                if(cur > 0)
                {
                    vec.push_back(cur);
                    break;
                }
            }
        }
    }
};
```
