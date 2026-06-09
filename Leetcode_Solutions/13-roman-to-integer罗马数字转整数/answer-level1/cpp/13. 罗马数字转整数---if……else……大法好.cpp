直接用if...else...语句先将六种特殊情况写出来
然后再按照无特殊情况逐个字符进行计算

```
#include <iostream>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        int cnt = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            cout << cnt << " ";
            if (s[i] == 'I' && s[i + 1] == 'V')
            {
                cnt += 4;
                i++;
            }
            else if (s[i] == 'I' && s[i + 1] == 'X')
            {
                cnt += 9;
                i++;
            }
            else if (s[i] == 'X' && s[i + 1] == 'L')
            {
                cnt += 40;
                i++;
            }
            else if (s[i] == 'X' && s[i + 1] == 'C')
            {
                cnt += 90;
                i++;
            }
            else if (s[i] == 'C' && s[i + 1] == 'D')
            {
                cnt += 400;
                i++;
            }
            else if (s[i] == 'C' && s[i + 1] == 'M')
            {
                cnt += 900;
                i++;
            }
            else if (s[i] == 'I')
                cnt += 1;
            else if (s[i] == 'V')
                cnt += 5;
            else if (s[i] == 'X')
                cnt += 10;
            else if (s[i] == 'L')
                cnt += 50;
            else if (s[i] == 'C')
                cnt += 100;
            else if (s[i] == 'D')
                cnt += 500;
            else if (s[i] == 'M')
                cnt += 1000;
        }
        return cnt;
    }
};

int main()
{
    Solution so;

    string str;
    cin >> str;
    int a = so.romanToInt(str);
    cout << a << endl;
    return 0;
}

```
