### 解题思路
没学过字典树，就硬写。。。
![image.png](https://pic.leetcode-cn.com/1ce2be9445ea29a01f711579b01a659b7ab03d5f22b994a9168f98164e6e6586-image.png)


### 代码

```cpp
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        if (words.size() == 0)
            return 0;

        string res = words[0] + "#";
        vector<int> placeholder;
        placeholder.push_back(words[0].size());

        for (int i = 1; i < words.size(); i++)
        {
            subsetChecker(res, words[i], placeholder);
        }

        return res.size();
    }

    void subsetChecker(string& tmp, string& word, vector<int>& placeholder)
    {
        int len = word.size();
        for (int i = 0; i < placeholder.size(); i++)
        {
            int end = placeholder[i] - 1;
            int start;
            if (0 == i)
                start = 0;
            else
                start = placeholder[i - 1] + 1;

            int k = len - 1;
            int j = end;
            if (len <= end - start + 1)
            {
                for (; k >= 0; j--, k--)
                {
                    if (tmp[j] != word[k])
                        break;
                }
                if (-1 == k)
                    return;
            }
            else
            {
                for (; j >= start; j--, k--)
                {
                    if (tmp[j] != word[k])
                        break;
                }
                if (j == start - 1)
                {
                    tmp.insert(j + 1, word, 0, len - end + start - 1);
                    return;
                }
            }
        }

        tmp += (word + "#");
        placeholder.push_back(placeholder.back() + len + 1);
    }
};
```