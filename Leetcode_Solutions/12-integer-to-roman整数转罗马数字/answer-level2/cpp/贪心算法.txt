```
class Solution {
public:
    string intToRoman(int num) {
        const vector<pair<int,string>> mapRom {{1000, "M"}, {900, "CM"},{500, "D"},{400, "CD"},{100, "C"},{90, "XC"},{50, "L"},{40, "XL"},{10, "X"},{9, "IX"},{5, "V"},{4, "IV"},{1, "I"}};

    string res;
    for (int i = 0; i < mapRom.size(); ++i) {
        if (num >= mapRom[i].first) {
            int temp = num / mapRom[i].first;
            num -= temp * mapRom[i].first;
            for (int j = 0; j < temp; ++j) {
                res += mapRom[i].second;
            }
        }
    }
    return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/26463adc372c9eea609c3aebf3cade2909a910197f2d90b19ea18fb8356f97f2-image.png)
![image.png](https://pic.leetcode-cn.com/7fe235da80dbc1ea08aa45efc133f9e3dd5e4945b39aa1fbee44173ffb2ae59a-image.png)

