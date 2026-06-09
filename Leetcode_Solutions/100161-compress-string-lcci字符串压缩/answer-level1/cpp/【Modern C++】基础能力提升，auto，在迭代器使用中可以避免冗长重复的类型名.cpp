```
#include <sstream>
class Solution {
public:
    string compressString(string S)
    {
        string compress = buildCompressString(S);
        if (compress.size() >= S.size()) {
            return S;
        }
        return compress;
    }
private:

    string buildCompressString(string &S)
    {
        stringstream ss;
        auto count = 0;
        auto current = '';
        for (auto a = S.begin(); a != S.end(); ++a) {
            auto c = *a;
            if (count == 0) {
                count++;
                current = c;
                continue;
            }
            if (current == c) {
                count++;
            } else {
                ss << current << count;
                count = 1;
                current = c;
            }
        }

        if (count != 0) {
            ss << current << count;
        }
        return ss.str();
    }

};
```
