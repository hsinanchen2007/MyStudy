### 解题思路


### 代码

```cpp
class Solution {
public:

    //1、
    string gcdOfStrings(string str1, string str2) {

        //首先计算两个字符串长度的最大公因数
        int gcd = get_gcd(str1.size(), str2.size());
    
        //因数：最大公约数到1中能整除最大公因数的数
        //例如：str1长度为12 str2长度为6 则最大公因数为6  因数则还有 3、2、1
        vector<int> v_cd; //因数数组
        for (int i = gcd; i >= 1; --i)
        {
            if (gcd % i == 0)
            {
                v_cd.push_back(i);
            }
        }

        //从最大公因数直到1， 两个字符串分别都拆分成 因数个字符为一组  比较所有组是否都相等
        //只要有一个因数满足，就返回
        for (int i = 0; i < v_cd.size(); ++i)
        {
            bool ok = true;
            vector<char> v_char(str1.begin(), str1.begin() + v_cd.at(i));
            for (int j = 0; j < str1.size() / v_cd.at(i); ++j) //分组
            {
                if (!equal(str1.begin() + j * v_char.size(), str1.begin() + (j + 1) * v_char.size(), v_char.begin()))
                {
                    ok = false;
                    break;
                }
            }

            if (!ok)
            {
                continue;
            }

            for (int j = 0; j < str2.size() / v_cd.at(i); ++j) //分组
            {
                if (!equal(str2.begin() + j * v_char.size(), str2.begin() + (j + 1) * v_char.size(), v_char.begin()))
                {
                    ok = false;
                    break;
                }
            }

            if (ok)
            {
                return string(str1.begin(), str1.begin() + v_cd.at(i));
            }
        }

        return "";
    }

    int get_gcd(int a, int b) {
        while (b) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }


    //2、参考官方题解 对枚举法优化内存
    //不使用拼接 不拷贝 减少内存消耗
    bool check(const string& t, const string& s){
        int lenx = (int)s.length() / (int)t.length();
        for (int i = 0; i < lenx; ++i){
            if(!equal(s.begin() + i * t.size(), s.begin() + (i + 1) * t.size(), t.begin()))
                return false;
        }
        return true;
    }

    //只需考虑最大公约数个字符的前缀是否满足
    string gcdOfStrings(string str1, string str2) {
        int len1 = (int)str1.length(), len2 = (int)str2.length();
        string T = str1.substr(0, __gcd(len1,len2)); // __gcd() 为c++自带的求最大公约数的函数
        if (check(T, str1) && check(T, str2)) 
            return T;
        return "";
    }
};
```