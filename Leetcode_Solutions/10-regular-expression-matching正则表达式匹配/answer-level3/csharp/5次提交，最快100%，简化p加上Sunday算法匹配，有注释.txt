### 解题思路
先做一次p的等价简化，再进行匹配。
匹配时，如果没有碰到*，则循环匹配；
如果碰到*，则递归调用；
如果遇到.*，则后续的匹配上会采用Sunday算法加速

### 代码

```csharp
public class Solution {
    public bool IsMatch(string s, string p)
    {
        // 先对p做一个格式化，形成等价的p，格式化过程中做以下处理：
        // 1、遇到"c*c*"这样的情形，忽略后一个c*
        // 2、遇到"c*c"这样的的情形将后面的c前移，形成"cc*"
        StringBuilder builder = new StringBuilder(), builderTmp = new StringBuilder();
        char c = '\0';
        for (int i = 0; i < p.Length;)
        {
            // 判断下一个字符字符，上述的特殊情况，第二个字符都是*，如果下一个字符会越界，则也不会出现特殊情况
            if (i + 1 == p.Length || p[i + 1] != '*')
            {
                builder.Append(p[i]);
                ++i;
                continue;
            }

            // 如果是"*"，则要判断是否是上述情况中的一种
            c = p[i];
            // c*模式
            if (i + 2 == p.Length)
            {
                // c*是最后一个了，不用再管
                builder.Append(c);      // i
                builder.Append('*');    // i+1
                i += 2;
                break;
            }

            for (i = i + 2; i + 1 < p.Length;)
            {
                if (p[i+1] == '*')
                {
                    // 连续的c*
                    if (c == '.' || p[i] == c)
                    {
                        // .*后跟着其他的c*或者连续相同的c*，忽略c*
                        i += 2;
                        continue;
                    }

                    if (p[i] == '.')
                    {
                        // c*后跟着.*，将c改为.，将builderTmp清空，并将c置为.
                        builderTmp.Clear();
                        c = '.';
                        i += 2;
                        continue;
                    }

                    // 如果是两对都没有.*，那么将前一对加到builderTmp中，然后c记为后一对
                    builderTmp.Append(c);
                    builderTmp.Append('*');
                    c = p[i];
                    i += 2;
                    // continue;
                }
                else
                {
                    // 不是连续的c*，那么先将builderTmp中的内容append到builder中
                    if (builder.Length > 0)
                    {
                        builder.Append(builderTmp.ToString());
                        builderTmp.Clear();
                    }

                    if (p[i] == c)
                    {
                        // c*c的模式，将c添加到builder中
                        builder.Append(c);
                        ++i;
                        continue;
                    }

                    // 其他情况就跳出当前循环，循环外会将当前的c*添加到builder中
                    break;
                }
            }

            // 如果builderTmp中有内容，则先添加builderTmp，再添加c*
            if (builder.Length > 0)
            {
                builder.Append(builderTmp.ToString());
                builderTmp.Clear();
            }

            // 把c*添加到字符串
            builder.Append(c);
            builder.Append('*');

            // continue;
        }

        // p格式化完成后，开始匹配
        return this.IsMatch(s, builder.ToString(), 0, false, '\0');
    }

    private bool IsMatch(string s, string p, int begin, bool canSkip, char skipChar)
    {
        if (begin == s.Length && p.Length == 0)
        {
            // s和p都是末尾了
            return true;
        }

        if (p.Length == 0)
        {
            // p没有了，那就要看是否能跳过头部以及skipChar的情况
            if (canSkip)
            {
                if (skipChar == '.')
                {
                    // 可以跳过任意字符，直接返回true
                    return true;
                }

                for (; begin < s.Length; ++begin)
                {
                    if (s[begin] != skipChar)
                    {
                        return false;
                    }
                }
                return true;
            }
            else
            {
                return false;
            }
        }

        int[] skipDistance = new int[26];

        // 找到maxSkip的值
        int maxSkip = p.IndexOf('*') - 1;
        if (maxSkip < 0)
        {
            maxSkip = p.Length;
        }

        if (canSkip && skipChar == '.')
        {
            // 如果可以跳过头部并且是任意字符的跳过，则采用sunday算法加速比较，最大跳跃只能到*为止
            int dotIndex = -1;
            for (int i = 0; i < p.Length && p[i] != '*'; ++i)
            {
                if (i + 1 < p.Length && p[i + 1] == '*')
                {
                    // 如果下一个是*，则跳出
                    break;
                }
                if (p[i] == '.')
                {
                    dotIndex = i;
                    continue;
                }
                skipDistance[p[i] - 'a'] = maxSkip - i;
            }

            for (int i = 0; i < skipDistance.Length; ++i)
            {
                if (skipDistance[i] > maxSkip - dotIndex || skipDistance[i] == 0)
                {
                    skipDistance[i] = maxSkip - dotIndex;
                }
            }
        }

        int pIndex = 0;
        while (begin < s.Length)
        {
            // 先判断下一个是否是*
            if (pIndex + 1 < p.Length && p[pIndex + 1] == '*')
            {
                // 遇到c*，进行递归
                if (this.IsMatch(s, p.Substring(pIndex + 2), begin, true, p[pIndex]))
                {
                    return true;
                }
            }
            else if (pIndex < p.Length && (s[begin] == p[pIndex] || p[pIndex] == '.'))
            {
                // 相同或者p为"."，过
                ++begin;
                ++pIndex;
                continue;
            }

            // 如果递归没有匹配上，或者当前字符不匹配，或者p已经结束了，判断是否能够跳过
            if (!canSkip)
            {
                // 不能跳过字符，直接返回false
                return false;
            }

            // 如果能够跳过，则看是否能够跳过任意字符
            if (skipChar == '.')
            {
                // 按照sunday算法跳跃，p重置为0
                if (begin - pIndex + maxSkip >= s.Length || begin - pIndex + skipDistance[s[begin - pIndex + maxSkip] - 'a'] >= s.Length)
                {
                    // 跳过后越界，直接返回false
                    return false;
                }
                begin += skipDistance[s[begin - pIndex + maxSkip] - 'a'] - pIndex;
                pIndex = 0;
                continue;
            }

            // 如果只能跳过特定字符，那么就判断s和skipChar是否一致，一致就跳一个字符后后重新从头匹配
            if (s[begin - pIndex] == skipChar)
            {
                begin = begin - pIndex + 1;
                pIndex = 0;
                continue;
            }

            // 能跳过的特定字符与s不匹配，则返回false
            return false;
        }

        // 最后判断一下begin和pIndex的情况
        if (begin == s.Length && pIndex == p.Length)
        {
            // 都正好匹配结束，返回true
            return true;
        }
        else if (begin < s.Length)
        {
            // 如果s没有走完，那就是没有匹配到最后，返回false
            return false;
        }
        else if (pIndex < p.Length - 1)
        {
            // p没有走完，看看其后面的偶数个位置是否都是*，只要有一个不是，那就返回false
            if ((p.Length - pIndex) % 2 == 0)
            {
                // 一定是偶数个
                for (pIndex += 1; pIndex < p.Length; pIndex += 2)
                {
                    if (p[pIndex] != '*')
                    {
                        return false;
                    }
                }

                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            // 其他情况
            return false;
        }
    }
}
```