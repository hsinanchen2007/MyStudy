### 解题思路
滑动窗口思想

### 代码

```cpp
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        vector<int> res;
        int word_num = words.size();
        if (word_num == 0) {
            return res;
        }
        int word_len = words[0].size();
        if (n < word_num * word_len) {
            return res;
        }
        unordered_map<string, int> m1;
        for(const auto& w:words){
            m1[w]++;
        }
        for(int i = 0; i < word_len; ++i) {
            //cout<<"test:"<<i<<endl;
            int left = i;
            int right = i;
            int count = 0;
            unordered_map<string, int> m2;
            while(right + word_len <= s.size()) {
                string w = s.substr(right, word_len);
                //cout<<w<<endl;
                right = right + word_len;
                if (m1.count(w) == 0) {
                    count = 0;
                    left = right;
                    m2.clear();
                } else {
                    ++count;
                    m2[w]++;
                    while(m2[w] > m1[w]) {
                        string tmp = s.substr(left, word_len);
                        m2[tmp]--;
                        count--;
                        left = left + word_len;
                    }
                    if (count == word_num) {
                        res.push_back(left);
                    }
                }
            }
        }
        return res;
    }
};
```