```C++ []
class Solution
{
public:
    string reverseWords(string s)
    {
        if (s == "")
            return s;
        istringstream iss(s);
        string tmp = "";
        string result = "";
        while (iss >> tmp)
        {
            for (int i = tmp.size() - 1; i >= 0; --i)
                result += tmp[i];
            result += " ";
        }
        result.erase(result.size() - 1);
        return result;
    }
};

```
执行用时：20 ms，超越92.99%，主要是看到空格分隔想到了istringstream。至于最核心的单词交换算法是最无脑的直接翻转，如果拦腰翻转的话会更快一些，这里只是为了提醒大家C++是有istringstream的233。