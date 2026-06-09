### 思路
1. 先数出一行能够容纳的单词，将这些单词根据规则填入一行

2. 计算出额外的空格数量 `spaceCount`
    21. 由总长度算起
    22. 除去每个单词末尾必须的空格
    23. 除去所有单词字母的长度
    24. 得到额外的空格数量

3. 按照单词的间隙数量 `wordCount - 1` ，对额外空格**平均分布**
    31. **平均分布**可查看 [另一篇题解](https://leetcode-cn.com/circle/discuss/eXOcnD/view/SecVmv/) 的配图，就是商和余数的计算
    32. 对于每个词填充之后，需要填充的空格数量等于 `spaceCount + 1 + ((i - bg) < t)`
        即：【额外空格的平均值】，【单词尾部固定的空格】，【额外空格的余数，前 t 个需要多 1 个空格】
    33. 注意一行只有一个单词的特殊处理

4. 因为会有最后一行或者一行只有一个单词的特殊情况，需要在最后将不足的位置补充成空格

### 图解
![图片.png](https://pic.leetcode-cn.com/75b02584132980cf62dcb07e60d3c531b157320445cf8713e45cda3f4e169663-%E5%9B%BE%E7%89%87.png)

![图片.png](https://pic.leetcode-cn.com/5c7cc09c9d43ba5cf351a419a1d3a699e55a62af438b510283109282ecf58a1c-%E5%9B%BE%E7%89%87.png)


### 答题
```C++ []
string fillWords(vector<string>& words, int bg, int ed, int maxWidth, bool lastLine = false)
{
    string ans;
    int wordCount = ed - bg + 1;
    int spaceCount = maxWidth + 1 - wordCount;  // 除去每个单词尾部空格， + 1 是最后一个单词的尾部空格的特殊处理
    for (int i = bg; i <= ed; i++)
    {
        spaceCount -= words[i].size();  // 除去所有单词的长度
    }

    int t = (wordCount == 1) ? 0 : spaceCount % (wordCount - 1);    // 求余数
    spaceCount /= (wordCount == 1) ? 1 : (wordCount - 1);   // 求平均值

    for (int i = bg; i < ed; i++)
    {
        ans += words[i];    // 填入单词
        if (lastLine)   // 特殊处理最后一行
        {
            fill_n(back_inserter(ans), 1, ' ');
            continue;
        }
        // 根据计算结果补上空格
        // 【额外空格的平均值】，【单词尾部固定的空格】，【额外空格的余数，前 t 个需要多 1 个空格】
        fill_n(back_inserter(ans), spaceCount + 1 + ((i - bg) < t), ' ');
    }
    ans += words[ed];
    fill_n(back_inserter(ans), maxWidth - ans.size(), ' '); // 补上这一行最后的空格
    return ans;
}

vector<string> fullJustify(vector<string>& words, int maxWidth) 
{
    vector<string> ans;
    int cnt = 0;
    int bg = 0;
    for (int i = 0; i < words.size(); i++)
    {
        cnt += words[i].size() + 1;

        if (i + 1 == words.size() || cnt + words[i + 1].size() > maxWidth)
        {   // 如果是最后一个单词，或者加上下一个词就超过长度了，即可凑成一行
            ans.push_back(fillWords(words, bg, i, maxWidth, i + 1 == words.size()));
            bg = i + 1;
            cnt = 0;
        }
    }
    return ans;
}
```
```C++ []
string fillWords(vector<string>& words, int bg, int ed, int maxWidth, bool lastLine = false)
{
    string ans;
    int wordCount = ed - bg + 1;
    int spaceCount = maxWidth + 1 - wordCount;
    for (int i = bg; i <= ed; i++)
    {
        spaceCount -= words[i].size();
    }

    int t = (wordCount == 1) ? 0 : spaceCount % (wordCount - 1);
    spaceCount /= (wordCount == 1) ? 1 : (wordCount - 1);

    for (int i = bg; i < ed; i++)
    {
        ans += words[i];
        if (lastLine)
        {
            fill_n(back_inserter(ans), 1, ' ');
            continue;
        }
        fill_n(back_inserter(ans), spaceCount + 1 + ((i - bg) < t), ' ');
    }
    ans += words[ed];
    fill_n(back_inserter(ans), maxWidth - ans.size(), ' ');
    return ans;
}

vector<string> fullJustify(vector<string>& words, int maxWidth) 
{
    vector<string> ans;
    int cnt = 0;
    int bg = 0;
    for (int i = 0; i < words.size(); i++)
    {
        cnt += words[i].size() + 1;

        if (i + 1 == words.size() || cnt + words[i + 1].size() > maxWidth)
        {
            ans.push_back(fillWords(words, bg, i, maxWidth, i + 1 == words.size()));
            bg = i + 1;
            cnt = 0;
        }
    }
    return ans;
}
```

### 执行时间
![图片.png](https://pic.leetcode-cn.com/6e384d6a79d0173c9cc2d2e0a7af64e401307726076f87f4c7dfdf00d873d646-%E5%9B%BE%E7%89%87.png)


### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

