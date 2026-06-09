### 解题思路
此处撰写解题思路
做这个题的时候，总是想着避免去用map，觉得多申请一块map内存着实浪费空间。
现在重新看这块代码，时间应该消耗在比较上面了，假设N个字符串，可以分为M组，则算法时间复杂度
应该为O(MN)，这种方法还是太慢了。
### 代码

```cpp
class Solution {
public:

    bool IsEqual(const string &str1, const string &str2) {
        if (str1.size() != str2.size()) {
            return false;
        }

        char sum[26] = {0};

        for (int i = 0; i < str1.size(); ++i) {
            sum[str1[i] - 'a'] += 1;
            sum[str2[i] - 'a'] -= 1;
        }
        for (int i = 0; i < 26; ++i) {
            if (sum[i] != 0) {
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > vec_vec_str;

        if (0 == strs.size()) {
            return vec_vec_str;
        }

        vector<string> vec_str;
        vec_str.push_back(strs[0]);
        vec_vec_str.push_back(vec_str);

        int i = 1;
        while (i < strs.size()) {
            int j = 0;
            while (j < vec_vec_str.size()) {
                if (IsEqual(vec_vec_str[j][0], strs[i])) {
                    vec_vec_str[j].push_back(strs[i]);
                    break;
                }
                ++j;
            }
            if (vec_vec_str.size() == j) {
                vector<string> vec_str;
                vec_str.push_back(strs[i]);
                vec_vec_str.push_back(vec_str);
            }
            ++i;

        }
        return vec_vec_str;


    }
};
```