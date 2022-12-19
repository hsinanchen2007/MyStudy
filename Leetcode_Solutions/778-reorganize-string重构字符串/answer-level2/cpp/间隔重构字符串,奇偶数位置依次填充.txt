### 解题思路
1、统计每个字符的数量
2、将数量最多的字符依次填充到奇数的位置，如果索引超过字符串长度则从头开始填充偶数的位置。
3、删除已使用的字符，继续寻找下一个数量最多的字符。继续填充位置。
### 代码

```cpp
class Solution {
public:
    string reorganizeString(string S) {
        if(S.length() <= 1)
        {
            return S;
        }
        string result_str;
        map<char,int> m_count;//统计每个字符数量
        for(int i = 0; i < S.length(); i++)
        {
            m_count[S[i]]++;
        }
        int max = 0;
        char max_ch;
        int index = 0;
        while(m_count.size() > 0)
        {
            max = 0;
            for(auto &it: m_count)
            {
                if(it.second > max)
                {
                    max = it.second;
                    max_ch = it.first;
                }
            }
            if(max > (S.length() + 1)/2)
            {
                return "";
            }
            m_count.erase(max_ch);
            while(max > 0)
            {
                S[index] = max_ch;
                index += 2;
                max --;
                if(index > S.length() - 1)
                {
                    index = 1;
                }
            }
        }
        return S;
    }
};
```