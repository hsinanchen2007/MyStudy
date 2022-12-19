![8.mp4](09b8ab1e-5222-45bb-9608-7462a35e41e0)

<![1.jpg](https://pic.leetcode-cn.com/f2a257c31298d69be065f2d5c544ca011d4b64adaa558b175c41db950dd22e5e-1.jpg),![2.jpg](https://pic.leetcode-cn.com/120cb778f434b3383464662e84cccaa7ee961edab7210d9f2f0d64ad4d14ff3d-2.jpg),![3.jpg](https://pic.leetcode-cn.com/158d42275952896cab0b708d7625bf321e182e57ffd3e26724e42bb07e776d88-3.jpg)>

```cpp [-C++]
#include <iostream>
#include <sstream>
#include <cmath>
#include <climits>
#include <regex>
#include <string>
using namespace std;

class Solution
{
public:
    int myAtoi(string str)
    {
        int result;
        string resultStr;
        smatch tmpMatch;
        //c++中要用\\进行转义
        regex tmpRegex("^[\\+\\-\\d]\\d*");
        //先将左边的空格去除
        trimStart(str);
        regex_search(str, tmpMatch, tmpRegex);

        stringstream ss;
        if (int(tmpMatch.size()) == 0)
        {
            return 0;
        }
        string tmpStr = tmpMatch[0];
        //转换成int
        ss << tmpStr;
        cout << tmpStr << endl;
        long longResult;
        ss >> longResult;
        result = max(min(longResult, long(INT_MAX)), long(INT_MIN));

        return result;
    }

    void trimStart(string &s)
    {
        if (!s.empty())
        {
            s.erase(0, s.find_first_not_of(" "));
            //s.erase(s.find_last_not_of(" ") + 1);
        }
    }
};
```

<![1.jpg](https://pic.leetcode-cn.com/5d71ad4ab18d2a42e52855c66168f5f741ae15c39ff6be6b57be82e292321c4f-1.jpg),![2.jpg](https://pic.leetcode-cn.com/7f096078056778cce4b5ec143e2d4b83367d917862893a3b4611d42525f830df-2.jpg),![3.jpg](https://pic.leetcode-cn.com/8b2316e97f68c3f93867108f000261af00c2063c74bb6ded80c7a691edd546cb-3.jpg)>

```cpp [-C++]
#include <iostream>
#include <sstream>
using namespace std;

class Solution
{
public:
    int myAtoi(string str)
    {
        int result = 0;
        stringstream ss;
        ss << str;
        ss >> result;
        return result;
    }
};
```
![结局.jpg](https://pic.leetcode-cn.com/9cbe04ffcb3c8fccda5b0e3897b0fdb64458381845a43dc3e86b36d45089cf3e-%E7%BB%93%E5%B1%80.jpg)
更多内容可以看我制作的视频
https://www.bilibili.com/video/av75423327
