### 解题思路

1、暴力搜索

2、X为所有数字次数的最大公约数的约数 即可成功分组

### 代码

```cpp

//1、从2到min_count进行搜索
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {

        map<int, int> m;

        for (int i = 0; i < deck.size(); ++i)
        {
            ++m[deck.at(i)];
        }

        auto iter = m.begin();
        int min_count = iter->second;

        for (; iter != m.end(); ++iter)
        {
            if (iter->second < 2) //如果有次数小于2，返回false
            {
                return false;
            }

            if (iter->second < min_count)
            {
                min_count = iter->second;
            }
        }

        for (int i = 2; i <= min_count; ++i)
        {
            //i能否整除size
            if (deck.size() % i != 0)
            {
                continue;
            }

            for (iter = m.begin(); iter != m.end(); ++iter)
            {
                if (iter->second % i != 0)
                {
                    break;
                }
            }

            if (iter == m.end()) //是所有数字次数的约数
            {
                return true;
            }
        }

        return false;
    }
};

//2、最大公约数
class Solution {
public:
    int gcd(int a, int b)
    {
        while (b)
        {
            int tmp = b;
            b = a % b;
            a = tmp;
        }
        return a;
    }

    bool hasGroupsSizeX(vector<int>& deck) {

        map<int, int> m;

        for (int i = 0; i < deck.size(); ++i)
        {
            ++m[deck.at(i)];
        }

        int g = 0;
        auto iter = m.begin();
        for (; iter != m.end(); ++iter)
        {
            if (iter->second < 2) //如果有次数小于2，返回false
            {
                return false;
            }

            if (g == 0)
            {
                g = iter->second;
            }
            else
            {
                g = gcd(g, iter->second);
            }

        }

        return g >= 2;
    }
};

