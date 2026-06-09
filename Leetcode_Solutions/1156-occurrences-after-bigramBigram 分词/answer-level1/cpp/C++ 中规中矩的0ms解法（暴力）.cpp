```cpp
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        istringstream words(text);
        string w;
        vector<string> tmp, ans;
        while (words >> w) tmp.push_back(w);
        for (int i = 0, j = 1; j < tmp.size() - 1; ++i, ++j) 
            if (tmp[i] == first && tmp[j] == second) ans.push_back(tmp[j + 1]);

        return ans;
    }
};

```