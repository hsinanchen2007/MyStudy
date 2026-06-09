因为数量有限，直接用了穷举法。有些哥们用了回溯法，也是可以参考一下

```
class Solution {
public:
   vector<vector<string>> hours= {
        {"0"},
        {"1", "2", "4", "8"},
        {"3", "5", "9", "6", "10"},
        {"7", "11"}
    };

    vector<vector<string>> minutes= {
        {"00"},
        {"01", "02", "04", "08", "16", "32"},
        {"03", "05", "09", "17", "33", "06", "10", "18", "34", "12", "20", "36", "24", "40", "48"},
        {"07", "11", "19", "35", "13", "21", "37", "25", "41", "49", "14", "22", "38", "26", "42", "50", "28", "44", "52", "56"},
        {"15", "23", "39", "27", "43", "51", "29", "45", "53", "57", "30", "46", "54", "58"},
        {"31", "47", "55", "59"},
    };

    vector<string> readBinaryWatch(int num) {
        if (num > 8) return {};
        vector<string> res;
        for (int i=0; i <= min(num, 3); i++) {
            if (num-i > 5) continue;
            for (int j=0; j<hours[i].size(); j++) {               
                for (int k=0; k<minutes[num-i].size(); k++) {
                    res.emplace_back(hours[i][j] + ":" + minutes[num-i][k]);
                }
            }
        }
        return res;
    }
};
```

