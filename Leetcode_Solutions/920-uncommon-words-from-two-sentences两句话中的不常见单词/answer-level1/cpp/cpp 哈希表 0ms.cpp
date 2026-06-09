![image.png](https://pic.leetcode-cn.com/6bd99a6bf461477edcd72fa370f9b91dd5cff4c037afac09dd425d790b5c42a1-image.png)

思路：
切割字符串，然后用一个哈希表记录字符串出现的频率，频率为1则输出到结果中。

```
class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        countWords(A);
        countWords(B);
        vector<string> result;
        for (const auto& [str, count] : record_) {
            if (count == 1) {
                result.emplace_back(str);
            }
        }
        return result;
    }

private:
    void countWords(const string& str) {
        int pos = 0;
        int pre = 0;
        while (pos != -1) {
            pos = str.find(' ', pre);
            if (pos == -1) {
                break;
            }
            record_[str.substr(pre, pos - pre)]++;
            pre = pos + 1;
        }
        record_[str.substr(pre)]++;
    }
    unordered_map<string, int> record_;
};
```
