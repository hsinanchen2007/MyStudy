### 解题思路
将每个word反转，并对words排序后，若可能存在压缩情况，只能是前一个word是后一个word的前缀。

### 代码

```cpp
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int len = words.size(), len_idx_str = 0;
        // 数据预处理：反转+排序
        for(string & word : words)
            reverse(word.begin(), word.end());
        sort(words.begin(), words.end());
        words.push_back("");//使最后一个word也能在下面循环中计算
        for(int i = 0; i < len; ++i)
        {   // 如果比后一个长，肯定不会是其压缩码，直接加上其长度
            if(words[i].size() > words[i+1].size())
                len_idx_str += words[i].size()+1;
            else
            {   // 对比是否为压缩码，不是就加上这个word的长度
                for(int j = 0; j < words[i].size(); j++)
                    if(words[i][j] != words[i+1][j])
                    {    
                        len_idx_str += words[i].size()+1;
                        break;
                    }
            }
        }
        return len_idx_str;
    }
};
```