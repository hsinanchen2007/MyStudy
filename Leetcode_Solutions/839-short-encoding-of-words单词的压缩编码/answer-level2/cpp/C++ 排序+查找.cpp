第一眼看这个题，没怎么看懂，看懂之后，又没有什么思路。
仔细阅读思考之后，隐约感觉可以根据单词长度进行排序，因为较长的单词不可能存在于已经编码的较短的单词中，所以先处理较长的单词。
然后遍历每个单词，如果单词已经存在于被编码的单词中，那一定可以找到本单词+“#”，如果找不到，则说明单词需要参与编码，并加入编码中。
最后的结果，就是编码字符串的长度

```
class Solution {
public:
    struct Longer {
        bool operator()(string const& l, string const& r) {
            if (l.length() > r.length()) {
                return true;
            }
            else if (l.length() == r.length()) {
                return l > r;
            }
            return false;
        }
    };

    int minimumLengthEncoding(vector<string>& words) {
        if (words.empty()) {
            return 0;
        }
        sort(words.begin(), words.end(), Longer());

        string s;
        for (int pos = 0; pos < words.size(); ++pos) {
            if (s.find(words[pos] + "#") != string::npos) {
                continue;
            }
            else {
                s = s + words[pos] + "#";
            }
        }
        return s.length();
    }
};
```

