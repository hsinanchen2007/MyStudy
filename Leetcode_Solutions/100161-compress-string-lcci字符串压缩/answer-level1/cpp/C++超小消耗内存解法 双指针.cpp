### 解题思路
![捕获.PNG](https://pic.leetcode-cn.com/3b91b247dd158cf5dfdb3bbfdba524271cd27cf167bbde8f1467ff8447143dab-%E6%8D%95%E8%8E%B7.PNG)

采用两个指针 一个指针指向当前值 另一个指针指向元素的值如果跟这个指针指向元素值一样那就计数
不一样那么就 将原来的值保存起来 然后更新

### 代码

```cpp
class Solution {
public:
    string compressString(string S) {
        if (S.empty()|| S.size()<=2)
            return S;
        //一初始字符
        string::iterator ptr = S.begin();
        string::iterator qtr = ptr;
        size_t counter = 0;
        string ans;//结果字符串
        //一遍遍历
        while (qtr != S.end())
        {
            if (*ptr == *qtr)
            {
                counter++;
                qtr++;

                //如果走到结尾 那么添加
                if (qtr == S.end())
                {
                    ans.push_back(*ptr);
                    string s = to_string(counter);

                    for (auto c : s)
                        ans.push_back(c);

                    ptr = qtr;
                    counter = 0;
                }
            }
            else
            {
                //ptr之后为保存数目
                ans.push_back(*ptr);
                string s = to_string(counter);

                for (auto c : s)
                    ans.push_back(c);

                ptr = qtr;
                counter = 0;
            }
        }

        if (ans.size() < S.size())
            return ans;
        else
            return S;

    }
};
```