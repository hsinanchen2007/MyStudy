从最高位起遍历，得到除数为几就放入几个对应字符，遇到1000， 100， 10时，判断除完余数是否会遇到特殊情况，遇到则做对应处理。
```
class Solution {
public:
    string intToRoman(int num) {
        vector<char> romanchar{'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        vector<int> numerical{1, 5, 10, 50, 100, 500, 1000};
        string res;
        for (int i = 6;i >= 0;--i)
        {
            num = calromannum(romanchar, numerical, num, i, res);
        }
        return res;
    }
    int calromannum(vector<char> romanchar, vector<int> numerical, int num, int loc, string& result)
    {
        int count = num / numerical[loc];
        while (count > 0)
        {
            result.push_back(romanchar[loc]);
            --count;
        }
        num = num % numerical[loc];
        if (loc > 0 && loc % 2 == 0 && (num/numerical[loc - 2] == 4 || num/numerical[loc - 2] == 9))
        {
            result.push_back(romanchar[loc - 2]);
            if (num/numerical[loc - 2] == 4)
            {
                result.push_back(romanchar[loc - 1]);
            }
            else if (num/numerical[loc - 2] == 9)
            {
                result.push_back(romanchar[loc]);
            }
            num = num % numerical[loc - 2];
            return num;
        }
        return num;
    }
};
```
