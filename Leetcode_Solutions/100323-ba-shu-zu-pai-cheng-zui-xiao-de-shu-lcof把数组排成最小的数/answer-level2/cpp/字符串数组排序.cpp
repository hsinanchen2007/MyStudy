对字符串数组进行排序，对于字符串 m, n，如果 mn < nm，返回 true，否则，返回 false

```
class Solution {
   public:
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        for (int num : nums) {
            strs.push_back(to_string(num));
        }

        sort(strs.begin(), strs.end(),
             [](const string& str1, const string& str2) {
                 return str1 + str2 < str2 + str1;
             });

        string res = "";
        for (string str : strs) {
            res.append(str);
        }
        return res;
    }
};
```



