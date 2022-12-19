把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。
你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。

所有的可能性为pow(6, n),本题难点是如何计算每种情况出现的概率,考虑每个骰子按顺序的投掷。
1个骰子的情况,1~6面每个出现的可能性是1次。
std::map<int, int> map;
for (int i = 1; i <= 6; ++i)
{
    ++map[i];
}
2个骰子的情况,利用第一次的运算结果。
std::map<int, int> temp;
for (const auto& p : map)
{
    for (int j = 1; j <= 6; ++j)
    {
        temp[p.first + j] += p.second;
    }
}

代码:
std::map<int, int> map;
for (int i = 1; i <= 6; ++i)
{
    ++map[i];
}

std::map<int, int> temp;
for (int i = 2; i <= n; i++)
{
    for (const auto& p : map)
    {
        for (int j = 1; j <= 6; ++j)
        {
            temp[p.first + j] += p.second;
        }
    }
    map = temp;
    temp.clear();
}

vector<double> result;
for (const auto& p : map)
{
    result.emplace_back(p.second / pow(6, n));
}

return result;