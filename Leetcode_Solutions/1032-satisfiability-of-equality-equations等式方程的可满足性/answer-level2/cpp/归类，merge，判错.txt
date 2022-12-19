思路见标题，代码见下。
```
class Solution {
public:
    bool equationsPossible(vector<string>& equations)
    {
        int integer = 0;
        map<char, int> isNum; /* char, category */

        for (auto &str : equations) {
            char left = str[0];
            char right = str[str.length() - 1];
            if (str[1] == '!') {
                continue;
            }

            if (left == right) {
                if (!isNum.count(left)) {
                    isNum[left] = integer++;
                }
            } else {
                if (isNum.count(left)) {
                    if (isNum.count(right)) {
                        /* merge category */
                        int value = isNum[right];
                        for (auto &m : isNum) {
                            if (m.second == value) {
                                m.second = isNum[left];
                            }
                        }
                    }
                    isNum[right] = isNum[left];
                } else {
                    if (isNum.count(right)) {
                        isNum[left] = isNum[right];
                    } else {
                        isNum[left] = integer++;
                        isNum[right] = isNum[left];
                    }
                }
            }
        }

        for (auto &str : equations) {
            char left = str[0];
            char right = str[str.length() - 1];
            if (str[1] == '=') {
                continue;
            }

            if (left == right) {
                return false;
            } else {
                if (isNum.count(left) && isNum.count(right)) {
                    if (isNum[right] == isNum[left]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
```
