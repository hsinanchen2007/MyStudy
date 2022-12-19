### 解题思路
1、这里运用了桶排序（可能不是最佳答案），题意为小写的字母，所以只需要建立26个桶即可，每一个桶代表一个英文字母。
2、遍历一次字符串，计算出每个字母重复多少次，并写入到对应的桶里面
3、最后对比words[i]组建的桶和chars组建的桶，只要words[i]对应桶的计数小于chars的计数，都是满足题意的。
### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) 
    {
        int stand_array[26] = {0};
        for(int i = 0; i < chars.size(); ++i)
        {
            stand_array[chars[i] - 'a'] += 1;
        }

        int sum = 0;
        int chars_size = chars.size();
        for(int i = 0; i < words.size(); ++i)
        {
            int word_size = words[i].size();
            if(chars_size < word_size)
            {
                continue;
            }

            int self_array[26] = {0};
            for(int j = 0; j < words[i].size(); ++j)
            {
                self_array[words[i][j] - 'a'] += 1;
            }
            
            int index = 0;
            for(; index < 26; ++index)
            {
                if(self_array[index] > stand_array[index])
                {
                    break;
                }
            }

            if(index == 26)
            {
                sum += word_size;
            }
        }

        return sum;
    }
};
```