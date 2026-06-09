```
#include <map>
#include <vector>
#include <string>

class Solution {
public:

    using CharsStatistic = map<char, int>;

    int countCharacters(vector<string>& words, string chars)
    {
        int result = 0;
        CharsStatistic source;
        calcCharsStatistic(chars, source);

        for (auto iter = words.begin();
                iter != words.end();
                ++iter) {
            CharsStatistic target;
            calcCharsStatistic(*iter, target);
            try {
                auto t = target.begin();
                for (; t != target.end();
                        t++) {
                    if (source.at(t->first) < t->second) {
                        break;
                    }
                }

                if (t != target.end()) {
                    continue;
                }
                result += (*iter).length();
            } catch (...) {
            }
        }
        return result;
    }

private:
    void calcCharsStatistic(string &chars, CharsStatistic &charsStatistic)
    {
        for (auto iter = chars.begin();
                iter != chars.end();
                ++iter) {
            charsStatistic[*iter]++;
        }
    }

};
```
