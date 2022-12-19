用last记录上一个字符串，now记录当前的字符串，迭代n次得出最后结果。
在判断字符个数时，用cnt记录当前字符已经连续出现了几次（cnt默认为1）。将last字符串中当前位的字符和下一位字符进行比较，如果相同，cnt++；如果不相同，将cnt和当前字符加入到now字符串当中，之后将cnt重置为1。为了方便以及防止下标越界，预先在last字符串结尾添加一个字符"#"。

numToString函数是为了将cnt转化为一个字符串，添加这么一个函数，而不是直接将cnt加上0的ASCII码添加进字符串的原因是避免cnt是两位数时无法正常转化的问题（不过cnt的值貌似不会超过9）。
```c++
class Solution
{
private:
string numToString(int x)
{
    string re;
    while (x != 0)
    {
        char c = x % 10 + '0';
        re = c + re;
        x /= 10;
    }
    return re;
}

public:
    string countAndSay(int n)
    {
        string last, now = "1";
        for (register int i = 2; i <= n; i++)
        {
            last = now + '#'; //在末尾补上一个字符，防止越界
            now = "";
            int cnt = 1;
            for (register int j = 0; j < last.size() - 1; j++)
                if (last[j] != last [j + 1])
                {
                    now += numToString(cnt) + last[j];
                    cnt = 1;
                }
                else
                    cnt++;
        }
        return now;
    }
};
```
