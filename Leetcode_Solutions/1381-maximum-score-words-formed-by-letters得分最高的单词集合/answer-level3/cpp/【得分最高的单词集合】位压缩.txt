#### 解题思路：
1. 提供的字母集合，每个字母只能用一次
2. 提供的单词集合，每个单词也只能用一次
3. 单词集合的大小，`1 <= words[i].length <= 15`
4. 枚举 words 子集总共 `2^15` 种情况
5. 对每一种情况统计使用了哪些字母
   1. 如果字母超出范围了，就不符合要求
   2. 否则按照字母表计算得分
   3. 记录最大得分

#### 位压缩：
1. 对于单词集合中每一个词，都可以选择，用/不用
    > 所以就可以用位 `0/1` 来表示
2. 单词集合中每个单词都表示出来，总和就是 $2^N$ 种
    > 可以用 `1 << N` 来表示
3. 当遍历到其中一个组合时，其数字的二进制位表示的就是各个单词的使用状态
    > 比如 5，二进制 101，代表第 0 个和第 2 个单词使用，第 1 个单词不使用
4. 检查时，对于第 `i` 个单词，使用 `1 << i`，得到二进制除了第 `i` 位（顺序是从右至左）其余全 0 的数字
    > 比如第 2 个单词，`1 << 2` 之后得到 4（二进制 100）
5. 再与状态位进行&操作，得到是否使用
    > 4（二进制100）与刚才的 5（二进制101）&操作，得到 true

#### 代码：
```C++ [-C++]
// 将第（bit）种组合情况，所使用的单词中的字母数量统计出来
vector<int> group(vector<string>& words, int bit)
{
    vector<int> g(26, 0);
    for (int i = 0; i < words.size(); i++)
    {
        if (!(bit & (1 << i))) continue;
        for (auto c : words[i])
        {
            g[c - 'a']++;
        }
    }
    return g;
}

// 根据规则计算得分
int calcScore(vector<int>& group, vector<int>& lettercnt, vector<int>& score)
{
    int s = 0;
    for (int j = 0; j < 26; j++)
    {
        if (lettercnt[j] < group[j]) return 0;
        s += group[j] * score[j];
    }
    return s;
}

int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score)
{
    // 统计给出的字母的数量
    vector<int> lettercnt(26, 0);
    for (auto c : letters)
    {
        lettercnt[c - 'a']++;
    }
    
    int ans = 0;
    for (int i = 0; i < (1 << words.size()); i++)
    {
        auto g = group(words, i);
        ans = max(ans, calcScore(g, lettercnt, score));
    }
    return ans;
}
```




感谢您的观看，希望对您有帮助，欢迎热烈的交流！