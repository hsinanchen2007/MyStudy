利用stringstream可以比较简单地在int与string类型之间转换，用时0ms
```
class Solution {
  public:
    string countAndSay(int n) {
        string ret = "1";
        for (int i = 1; i < n; i++) {
            int count = 1;
            char last = ret[0];
            stringstream ss;
            for (int i = 1; i <= ret.size(); i++) {
                if (ret[i] == last)
                    count++;
                else {
                    ss << count;
                    ss << last;
                    count = 1;
                    last = ret[i];
                }
            }
            ss >> ret;
        }
        return ret;
    }
};
```
