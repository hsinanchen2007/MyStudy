![image.png](https://pic.leetcode-cn.com/3304a0ee7b88d9d2da581b72ed75c9eb2b88e93ea16e4cba39da740b443458bb-image.png)
```
vector<string> letterCasePermutation(string S)
{
    vector<string> result;
    result.push_back(S);

    // 记录每个字母的位置
    vector<int> pos;
    for (int i = 0; i < S.size(); i++)
    {
        if ((S[i] >= 'A' && S[i] <= 'Z') || (S[i] >= 'a' && S[i] <= 'z'))
        {
            pos.push_back(i);
        }
    }

    if (pos.empty())
    {
        return result;
    }

    int len = pow(2, pos.size());
    for (int i = 1; i < len; i++)
    {
        result.push_back(S);
    }

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j <= log2(i); j++)
        {
            if (i & (1 << j))
            {
                int p = pos[j];
                result[i][p] ^= 1 << 5;
            }
        }
    }

    return result;
}
```
