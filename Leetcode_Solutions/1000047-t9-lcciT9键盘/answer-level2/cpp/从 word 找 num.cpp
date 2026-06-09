对于每一个单词，找到该单词对应的 wordNum，然后比较 wordNum 和 num

```
class Solution {
   public:
    vector<string> getValidT9Words(string num, vector<string>& words) {
        vector<string> res;
        if (num.size() == 0 || words.size() == 0) return res;

        char mm[26] = {'2', '2', '2', '3', '3', '3', '4', '4', '4',
                       '5', '5', '5', '6', '6', '6', '7', '7', '7',
                       '7', '8', '8', '8', '9', '9', '9', '9'};

        for (string word : words) {
            bool find = true;
            for (int i = 0; i < word.size(); i++) {
                if (mm[word[i] - 'a'] != num[i]) {
                    find = false;
                    break;
                }
            }
            if (find) res.push_back(word);
        }
        return res;
    }
};
```

- 时间复杂度：O(num.size() * words.size())
- 空间复杂度：O(1)