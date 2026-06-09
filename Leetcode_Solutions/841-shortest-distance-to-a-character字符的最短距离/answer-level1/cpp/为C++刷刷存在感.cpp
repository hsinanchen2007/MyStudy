遍历字符串S，如果相等距离则等于0，不相等开始前后遍历。
```
    vector<int> shortestToChar(string S, char C) 
    {

        vector<int> src;
        int len = S.length();
        for (int pos = 0; pos < len; ++pos)
        {
            if (S[pos] == C)
            {
                src.emplace_back(0);
                continue;
            }   
            int cnt = 0;
            while (++cnt)
            {
                if ((pos + cnt) < len && (S[pos + cnt] == C))
                {
                    src.emplace_back(cnt);
                    break;
                }
                if ((pos - cnt) >= 0 && (S[pos - cnt] == C))
                {
                    src.emplace_back(cnt);
                    break;
                }
            }

        }
        return src;
    }
```
