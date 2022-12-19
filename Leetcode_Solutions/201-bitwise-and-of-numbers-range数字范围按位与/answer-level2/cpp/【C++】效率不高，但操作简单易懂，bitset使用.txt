```
class Solution {
public:
    int rangeBitwiseAnd(int m, int n)
    {
        std::string mString = std::bitset< 64 >(m).to_string();
        std::string nString = std::bitset< 64 >(n).to_string();
        int i = 0;
        int j = 0;
        while (i < mString.length() && j < nString.length()) {
            if (mString.at(i) == nString.at(j)) {
                i++;
                j++;
            } else {
                break;
            }
        }

        string padding(mString.length() - i, '0');

        return std::bitset<64>(mString.substr(0, i) + padding).to_ulong();
    }
};
```
